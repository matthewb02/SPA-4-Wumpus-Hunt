//
// Created by benderm on 3/27/2025.
//

#ifndef TREASUREROOM_H
#define TREASUREROOM_H

#include "Room.h"

class TreasureRoom : public Room {
private:
  bool looted;
public:
  TreasureRoom() : looted(false) {}
  void enter(Player* player) override;
  char getIcon() override;
};



#endif //TREASUREROOM_H
