//
// Created by benderm on 3/28/2025.
//

#include "Shop.h"

#include <iostream>

void Shop::enter(Player *player) {
    if (purchased)
        std::cout << "The shopkeeper has vanished." << std::endl;
    else {
        std::cout << "You find a shopkeeper, who will sell you a TORCH or 10 RATIONS for 50 gold pieces." << std::endl;
        if (player -> getGold() < 50)
            std::cout << "You don't have enough gold!" << std::endl;
        else {
            std::cout << "Input 't' for torch, 'r' for rations, or 'c' to cancel: ";
            char input;
            std::cin >> input;
            switch (input) {
                case 't':
                    player -> changeGold(-50);
                    player -> changeTorches(1);
                    purchased = true;
                    break;
                case 'r':
                    player -> changeGold(-50);
                    player -> changeRations(10);
                    purchased = true;
                    break;
                default:
                    std::cout << "The shopkeeper is sad..." << std::endl;
            }
        }
    }
}


char Shop::getIcon() {
    return purchased ? ' ' : 's';
}
