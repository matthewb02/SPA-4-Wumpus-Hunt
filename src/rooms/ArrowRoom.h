//
// Created by benderm on 3/28/2025.
//

#ifndef ARROWROOM_H
#define ARROWROOM_H

#include "Room.h"

class ArrowRoom : public Room {
private:
  bool looted;
public:
  ArrowRoom() : looted(false) {}
  void enter(Player* player) override;
};



#endif //ARROWROOM_H
