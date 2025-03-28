//
// Created by benderm on 3/27/2025.
//

#include "GoldRoom.h"

#include <iostream>

void GoldRoom::enter(Player* player) {
  if (!looted) {
    std::cout << "You find a pouch of gold!" << std::endl;
    player -> changeGold(5);
    looted = true;
  } else {
    std::cout << "This room has been emptied." << std::endl;
  }
}