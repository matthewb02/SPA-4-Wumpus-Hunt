//
// Created by benderm on 3/26/2025.
//

#include <Game.h>
#include <iostream>
#include "Map.h"

using namespace std;

/*
 * @TODO
 * Game class - takes game logic out of the driver and allows "global variables"
 *
 * stairs - descend between floors that extend in size
 *
 * arrow functionality - option to shoot adjacent rooms
 *
 * special rooms - campfire, locked door, blessed fountain
 */

int main() {
    Game game = Game();
    game.run();
    return 0;
}

