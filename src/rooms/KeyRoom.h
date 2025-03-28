//
// Created by benderm on 3/27/2025.
//

#ifndef KEYROOM_H
#define KEYROOM_H

#include "Room.h"

class KeyRoom : public Room {
private:
  bool looted;
public:
  KeyRoom() : looted(false) {}
  void enter(Player* player) override;
};



#endif //KEYROOM_H
