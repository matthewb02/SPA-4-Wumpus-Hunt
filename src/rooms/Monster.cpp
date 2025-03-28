//
// Created by benderm on 3/27/2025.
//

#include "Monster.h"

#include <iostream>

void Monster::enter(Player* player) {
    if (killed) {
        std::cout << "There is a dead monster here, slain by an arrow." << std::endl;
        if (!eaten) {
            eaten = true;
            player -> changeRations(20);
            std::cout << "You scavenge it for food." << std::endl;
        }
    }
    else {
        player -> changeLives(-player -> getLives());
        std::cout << "There's a scary monster here!" << std::endl;
        std::cout << "You've been eaten." << std::endl;
    }
}

void Monster::shoot() {
    killed = true;
}

char Monster::getIcon() {
    return killed ? ' ' : 'M';
}
