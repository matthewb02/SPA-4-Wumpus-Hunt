//
// Created by benderm on 3/27/2025.
//

#include "Trap.h"

#include <iostream>

void Trap::enter(Player *player) {
    if (active) {
        active = false;
        player -> changeLives(-1);
        std::cout << "Several arrows fly cross the room!" << std::endl;
        if (player -> getLives() > 0) {
            player -> changeArrows(1);
            std::cout << "You've been hit by a few and are badly hurt, but not dead." << std::endl;
            std::cout << "You are able to recover one of the arrows." << std::endl;
        }
    } else
        std::cout << "The floor is littered with broken arrows." << std::endl;
}

char Trap::getIcon() {
    return active ? 'T' : ' ';
}
