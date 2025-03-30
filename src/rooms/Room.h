//
// Created by benderm on 3/26/2025.
//

#ifndef ROOM_H
#define ROOM_H

#include "Player.h"
#include <string>

class Room {
private:
  bool revealed;
public:
  Room() : revealed(false) {}
  bool isRevealed();
  void reveal();
  virtual void shoot();
  virtual void enter(Player* player);
  virtual char getIcon();
  virtual bool canEnter();
};


#endif //ROOM_H
