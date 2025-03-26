//
// Created by benderm on 3/26/2025.
//

#include "Map.h"
#include "rooms/Wall.h"
#include <iostream>

using namespace std;

Map::Map(int w, int h) {
  width = w;
  height = h;
  rooms = new Room*[width * height];

  for (int i = 0; i < width * height; i++) {
    rooms[i] = new Wall();
  }
  rooms[0] = new Room();
  rooms[1] = new Room();
  rooms[width + 1] = new Room();
}

Room* Map::getRoom(int x, int y) {
  return rooms[y * width + x];
}

void Map::printMap() {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (playerX == x && playerY == y) {
        cout << 'X' << ' ';
      } else {
        cout << rooms[y * width + x]->getIcon() << " ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

int Map::getPlayerX() {
  return playerX;
}

int Map::getPlayerY() {
  return playerY;
}

void Map::setPlayerPosition(int x, int y) {
  playerX = x;
  playerY = y;
}