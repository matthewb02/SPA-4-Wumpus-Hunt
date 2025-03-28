//
// Created by benderm on 3/26/2025.
//

#include "Map.h"
#include "Generator.h"
#include "rooms/Wall.h"
#include <iostream>
#include <random>

using namespace std;

Map::Map(int w, int h, Player* p) {
  width = w;
  height = h;
  player = p;
  Generator g = Generator(w, h);
  rooms = g.generate();
  playerX = g.getStartX();
  playerY = g.getStartY();

  getCurrentRoom() -> enter(player);
}

Room* Map::getRoom(int x, int y) {
  return rooms[y * width + x];
}

Room* Map::getCurrentRoom() {
  return getRoom(playerX, playerY);
}

void Map::printMap() {
  cout << '+';
  for (int i = 0; i < width * 2 - 1; i++) {
    cout << '-';
  }
  cout << '+' << endl;
  for (int y = 0; y < height; y++) {
    cout << '|';
    for (int x = 0; x < width; x++) {
      if (playerX == x && playerY == y) {
        cout << 'X';
      } else {
        cout << rooms[y * width + x]->getIcon();
      }
      if (x < width - 1)
        cout << ' ';
    }
    cout << '|' << endl;
  }
  cout << '+';
  for (int i = 0; i < width * 2 - 1; i++) {
    cout << '-';
  }
  cout << '+' << endl;
}

int Map::getPlayerX() {
  return playerX;
}

int Map::getPlayerY() {
  return playerY;
}

bool Map::canMovePlayer(int dx, int dy) {
  int newX = playerX + dx;
  int newY = playerY + dy;
  if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
    if (getRoom(newX, newY) -> canEnter()) {
      return true;
    }
  }
  cout << "Something is blocking your path." << endl;
  return false;
}

void Map::movePlayer(int dx, int dy) {
  player -> decrementTorchDuration();
  player -> changeRations(-1);
  playerX += dx;
  playerY += dy;
  getRoom(playerX, playerY) -> enter(player);
  getRoom(playerX, playerY) -> reveal();
  if (player->getTorchDuration() > 0) {
    if (playerX < width - 1)
      getRoom(playerX + 1, playerY) -> reveal();
    if (playerX > 0)
      getRoom(playerX - 1, playerY) -> reveal();
    if (playerY < height - 1)
      getRoom(playerX, playerY + 1) -> reveal();
    if (playerY > 0)
      getRoom(playerX, playerY - 1) -> reveal();
  }
}