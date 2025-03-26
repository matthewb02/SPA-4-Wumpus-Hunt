//
// Created by benderm on 3/26/2025.
//

#ifndef MAP_H
#define MAP_H

#include "rooms/Room.h"

class Map {
private:
  Room** rooms;
  int width, height;
  int playerX, playerY;
public:
  Map(int w, int h);
  Room* getRoom(int x, int y);
  void printMap();
  int getPlayerX();
  int getPlayerY();
  void setPlayerPosition(int x, int y);
};



#endif //MAP_H
