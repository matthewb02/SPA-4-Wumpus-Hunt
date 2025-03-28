//
// Created by benderm on 3/28/2025.
//

#include "SmallFoodRoom.h"

#include <iostream>

void SmallFoodRoom::enter(Player *player) {
    if (looted)
        std::cout << "There's breadcrumbs here." << std::endl;
    else {
        std::cout << "You find a stale piece of bread. Yummy." << std::endl;
        player -> changeRations(5);
        looted = true;
    }
}
