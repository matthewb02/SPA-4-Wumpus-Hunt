//
// Created by benderm on 3/28/2025.
//

#include "FoodRoom.h"

#include <iostream>

void FoodRoom::enter(Player *player) {
    if (looted)
        std::cout << "You're in an empty storeroom." << std::endl;
    else {
        looted = true;
        player->changeRations(20);
        std::cout << "You find a storeroom full of food, mostly rotten." << std::endl;
    }
}

char FoodRoom::getIcon() {
    return looted ? ' ' : 'F';
}
