//
// Created by benderm on 3/28/2025.
//

#include "Stairs.h"
#include "Map.h"

#include <iostream>

void Stairs::enter(Player *player) {
    std::cout << "You've found stairs that can take you deeper." << std::endl;
    std::cout << "Do you descend the stairs? (y) : ";
    char input;
    std::cin >> input;
    if (input == 'y' || input == 'Y') {
        player -> multiplyGoldMultiplier(1.5);
        player -> changeMap(new Map(newMapW, newMapH, player));
    }
}


char Stairs::getIcon() {
    return 'V';
}
