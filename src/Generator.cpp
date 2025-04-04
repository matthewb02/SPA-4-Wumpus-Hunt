//
// Created by benderm on 3/27/2025.
//

#include "Generator.h"
#include "rooms/Wall.h"
#include "rooms/GoldRoom.h"
#include "rooms/TreasureRoom.h"
#include "rooms/KeyRoom.h"
#include "rooms/Monster.h"
#include "rooms/Trap.h"
#include "rooms/ArrowRoom.h"
#include "rooms/TorchRoom.h"
#include "rooms/FoodRoom.h"
#include "rooms/Stairs.h"
#include "rooms/Campfire.h"
#include "rooms/SmallFoodRoom.h"
#include "rooms/Shop.h"
#include "rooms/Fountain.h"

#include <set>
#include <ctime>
#include <iostream>

using namespace std;

Generator::Generator(int w, int h) {
  width = w;
  height = h;
  map = new int[width * height] {0};
}

Generator::~Generator() {
  delete[] map;
}

Room** Generator::generate() {
  srand(time(nullptr));
  startX = rand() % width;
  startY = rand() % height;
  createSprawl(startX + startY * width);

  Room** finalMap = new Room*[width * height];
  for (int i = 0; i < width * height; i++) {
    switch (map[i]) {
      case 1:
        if (rand() % 5 == 0)
          finalMap[i] = new GoldRoom();
        else if (width * height > 30 && rand() % 10 == 0)
          finalMap[i] = new SmallFoodRoom();
        else if (rand() % 15 == 0)
          finalMap[i] = new KeyRoom();
        else if (rand() % 15 == 0)
          finalMap[i] = new Campfire();
        else if (rand() % 30 == 0)
          finalMap[i] = new Trap();
        else if (rand() % 30 == 0)
          finalMap[i] = new ArrowRoom();
        else if (rand() % 45 == 0)
          finalMap[i] = new TorchRoom();
        else if (width * height > 30 && rand() % 60 == 0)
          finalMap[i] = new Monster();
        else if (rand() % 100 == 0)
          finalMap[i] = new TreasureRoom();
        else
          finalMap[i] = new Room();
        break;
      case 2:
        finalMap[i] = new KeyRoom();
        break;
      case 3:
        finalMap[i] = new TreasureRoom();
        break;
      case 5:
        finalMap[i] = new Trap();
        break;
      case 6:
        finalMap[i] = new Monster();
        break;
      case 7:
        finalMap[i] = new TorchRoom();
        break;
      case 8:
        finalMap[i] = new FoodRoom();
        break;
      case 9:
        finalMap[i] = new Stairs(width + rand() % 2, height + rand() % 2);
        break;
      case 10:
        finalMap[i] = new Shop();
        break;
      case 11:
        finalMap[i] = new Fountain();
        break;
      default:
        finalMap[i] = new Wall();
    }
  }
  return finalMap;
}

// used for debugging
void printStuff(int* m) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (m[i * 4 + j] >= 0)
        cout << " ";
      cout << m[i * 4 + j];
    }
    cout << endl;
  }
  cout << endl;
}

int getRandomElement(set<int> s) {
  int e = rand() % (s.size());
  int j = 0;
  for (int n : s) {
    if (j == e) {
      return n;
    }
    j++;
  }
  return -1;
}

void Generator::createSprawl(int r) {
  set<int> rooms;
  set<int> adjWalls;
  setRoom(r, 1);
  if (r % width + 1 != width && trySetRoom(r + 1, -1))
    adjWalls.insert(r + 1);
  if (r % width != 0 && trySetRoom(r - 1, -1))
    adjWalls.insert(r - 1);
  if (trySetRoom(r + width, -1))
    adjWalls.insert(r + width);
  if (trySetRoom(r - width, -1))
    adjWalls.insert(r - width);

  for (int i = 0; i < width * height * 0.6 - 3; i++) {
    //printStuff(map);
    int newTile = getRandomElement(adjWalls);
    setRoom(newTile, 1);
    rooms.insert(newTile);
    adjWalls.erase(newTile);
    if (newTile % width + 1 != width && trySetRoom(newTile + 1, -1))
      adjWalls.insert(newTile + 1);
    if (newTile % width != 0 && trySetRoom(newTile - 1, -1))
      adjWalls.insert(newTile - 1);
    if (trySetRoom(newTile + width, -1))
      adjWalls.insert(newTile + width);
    if (trySetRoom(newTile - width, -1))
      adjWalls.insert(newTile - width);
  }
  int treasureRoom = getRandomElement(rooms);
  rooms.erase(treasureRoom);
  map[treasureRoom] = 3;
  int keyRoom = getRandomElement(rooms);
  rooms.erase(keyRoom);
  map[keyRoom] = 2;
  int torch = getRandomElement(rooms);
  rooms.erase(torch);
  map[torch] = 7;
  int exit = getRandomElement(rooms);
  rooms.erase(exit);
  map[exit] = 9;
  int monster = getRandomElement(adjWalls);
  adjWalls.erase(monster);
  map[monster] = 6;
  if (rand() % 2 == 0) {
    int food = getRandomElement(rooms);
    rooms.erase(food);
    map[food] = 8;
  }
  if (width * height > 30) {
    if (rand() % 3 == 0) {
      int fountain = getRandomElement(rooms);
      rooms.erase(fountain);
      map[fountain] = 11;
    } else {
      int shop = getRandomElement(rooms);
      rooms.erase(shop);
      map[shop] = 10;
    }
  }
  for (int i = 0; i < width * height - 12; i += 12) {
    int trap = getRandomElement(adjWalls);
    adjWalls.erase(trap);
    map[trap] = 5;
  }
}

bool Generator::setRoom(int r, int id) {
  if (r >= 0 && r < width * height) {
    map[r] = id;
    return true;
  }
  return false;
}

bool Generator::trySetRoom(int r, int id) {
  if (r >= 0 && r < width * height && map[r] == 0) {
    map[r] = id;
    return true;
  }
  return false;
}

int Generator::getStartX() {
  return startX;
}

int Generator::getStartY() {
  return startY;
}