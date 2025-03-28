//
// Created by benderm on 3/27/2025.
//

#ifndef GOLDROOM_H
#define GOLDROOM_H

#include "Room.h"

class GoldRoom : public Room {
private:
  bool looted;
public:
  GoldRoom() : looted(false) {}
  void enter(Player* player) override;
};



#endif //GOLDROOM_H
