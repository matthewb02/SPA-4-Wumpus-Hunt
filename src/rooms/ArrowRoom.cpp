//
// Created by benderm on 3/28/2025.
//

#include "ArrowRoom.h"

#include <iostream>

void ArrowRoom::enter(Player* player) {
  if (looted)
    std::cout << "You find a dead adventurer." << std::endl;
  else {
    std::cout << "You find a dead adventurer, shot by an arrow trap." << std::endl;
    player -> changeArrows(1);
    looted = true;
  }
}