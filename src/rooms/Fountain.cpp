//
// Created by benderm on 3/28/2025.
//

#include "Fountain.h"

#include <iostream>

void Fountain::enter(Player *player) {
    if (used)
        std::cout << "The fountain is dried up." << std::endl;
    else {
        std::cout << "You find a magical fountain which improves your health." << std::endl;
        player -> changeLives(1);
        player -> changeRations(3);
        used = true;
    }
}


char Fountain::getIcon() {
    return used ? ' ' : 'f';
}
