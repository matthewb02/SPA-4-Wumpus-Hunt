//
// Created by benderm on 3/26/2025.
//

#ifndef MAP_H
#define MAP_H

#include "rooms/Room.h"

class Map {
private:
  Room** rooms;
  Player* player;
  int width, height;
  int playerX, playerY;
public:
  Map(int w, int h, Player* p);
  ~Map();
  Room* getRoom(int x, int y);
  Room* getCurrentRoom();
  void printMap();
  int getPlayerX();
  int getPlayerY();
  bool canMovePlayer(int dx, int dy);
  void movePlayer(int dx, int dy);
  void revealRooms();
};



#endif //MAP_H
