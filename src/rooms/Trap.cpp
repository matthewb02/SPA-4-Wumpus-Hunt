//
// Created by benderm on 3/27/2025.
//

#include "Trap.h"

#include <iostream>

void Trap::enter(Player *player) {
    if (active) {
        active = false;
        player -> changeLives(-1);
        std::cout << "You activate a pressure plate nad a flurry of darts crosses the room!" << std::endl;
        std::cout << "You've been hit by a few and are badly hurt, but not dead." << std::endl;
    } else
        std::cout << "The floor is littered with darts." << std::endl;
}

char Trap::getIcon() {
    return 'T';
}
