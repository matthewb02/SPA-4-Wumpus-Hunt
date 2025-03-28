//
// Created by benderm on 3/28/2025.
//

#include "Campfire.h"

#include <iostream>

void Campfire::enter(Player *player) {
    if (player->getTorchDuration() >= 2)
        std::cout << "There's a campfire here." << std::endl;
    else {
        std::cout << "You find a campfire and grab a burning stick." << std::endl;
        std::cout << "The burning stick will provide light for a short time." << std::endl;
        player -> setTorchDuration(2);
    }
}

char Campfire::getIcon() {
    return 'c';
}