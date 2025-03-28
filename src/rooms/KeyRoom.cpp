//
// Created by benderm on 3/27/2025.
//

#include "KeyRoom.h"

#include <iostream>

void KeyRoom::enter(Player* player) {
  if (looted)
    std::cout << "There's a skeleton on the floor." << std::endl;
  else {
    std::cout << "You find an old skeleton with a key." << std::endl;
    std::cout << "You've gained a key." << std::endl;
    looted = true;
    player -> changeKeys(1);
  }
}