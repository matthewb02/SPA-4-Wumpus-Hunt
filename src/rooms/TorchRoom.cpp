//
// Created by benderm on 3/28/2025.
//

#include "TorchRoom.h"

#include <iostream>

void TorchRoom::enter(Player *player) {
    if (looted)
        std::cout << "There is nothing here." << std::endl;
    else {
        looted = true;
        player -> changeTorches(1);
        std::cout << "You find an unlit torch." << std::endl;
    }
}
