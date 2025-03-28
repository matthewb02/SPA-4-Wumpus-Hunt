//
// Created by benderm on 3/28/2025.
//

#ifndef GAME_H
#define GAME_H

#include "Map.h"

class Game {
private:
    Player* player;
    Map* map;
    bool endGame;
    void printDisplay();
    void getInput();
    bool checkEndGame();
    void move(int dx, int dy);
    void lightTorch();
    void shootArrow(int dx, int dy);
    void shootAction();
public:
    Game();
    void run();
};



#endif //GAME_H
