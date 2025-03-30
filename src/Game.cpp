//
// Created by benderm on 3/28/2025.
//

#include "Game.h"

#include <iostream>

using namespace std;

Game::Game() {
    player = new Player();
    endGame = false;
}

Game::~Game() {
    delete player;
}


void Game::printDisplay() {
    map->printMap();
    cout << "gold: " << player->getGold() << endl;
    cout << player->getLives() << " lives | ";
    cout << player->getRations() << " rations | ";
    cout << player->getTorches() << " torches | ";
    cout << player->getArrows() << " arrows" << endl;
    if (player->getKeys() > 0)
        cout << "You have a key." << endl;
    if (player->getTorchDuration() == 0)
        cout << "YOU HAVE NO LIGHT!" << endl;
}

void Game::move(int dx, int dy) {
    if (map->canMovePlayer(dx, dy))
        map->movePlayer(dx, dy);
}

void Game::lightTorch() {
    if (player -> getTorches() > 0) {
        cout << "You light a new torch." << endl;
        player -> changeTorches(-1);
        player -> setTorchDuration(6);
        map -> revealRooms();
    } else {
        cout << "You don't have any torches." << endl;
    }
}

void Game::shootArrow(int dx, int dy) {
    if (map -> canMovePlayer(dx, dy))
        map -> getRoom(map -> getPlayerX() + dx, map -> getPlayerY() + dy) -> shoot();
}

void Game::shootAction() {
    if (player -> getArrows() > 0) {
        map -> printMap();
        cout << "Input 'w' 'a' 's' or 'd' to choose the direction you shoot, or 'c' to cancel" << endl;
        cout << "Input: ";
        char input;
        cin >> input;
        cout << endl << endl << endl << endl;
        switch (input) {
            case 'w':
                shootArrow(0, -1);
            break;
            case 'a':
                shootArrow(-1, 0);
            break;
            case 's':
                shootArrow(0, 1);
            break;
            case 'd':
                shootArrow(1, 0);
            break;
            default:
                player -> changeArrows(1);
            cout << "Shoot action canceled." << endl;
        }
        player -> changeArrows(-1);
    } else
        cout << "You don't have any arrows." << endl;
}

void Game::help() {
    cout << "You are the 'X' on the map." << endl;
    cout << "Get as much gold as possible before you die!" << endl;
    cout << "Deeper floors contain more gold." << endl;
    cout << "Running out of rations will KILL YOU." << endl;
    cout << "Stumbling into a Monster (M) will KILL YOU." << endl;
    cout << "Stumbling into three Traps (T) will KILL YOU." << endl;
    cout << "Most importantly, move sparingly. Each move costs a ration and wears down your torch." << endl;
    cout << "When your torch burns out you must relight another or else you can't see where you're walking." << endl;
    cout << endl << "Enter '?' to review this message." << endl << endl;
}

void Game::getInput() {
    cout << "Input 'w' 'a' 's' or 'd' to move," << endl;
    if (player -> getTorchDuration() == 0 && player -> getTorches() > 0)
        cout << "'t' to light a torch, ";
    if (player -> getArrows() > 0)
        cout << "'r' to shoot an arrow, ";
    cout << "'?' for help, or 'q' to quit." << endl << "Input: ";
    char input;
    cin >> input;
    cout << endl << endl << endl << endl;
    switch (input) {
        case 'q':
            endGame = true;
            break;
        case 'w':
            move(0, -1);
            break;
        case 'a':
            move(-1, 0);
            break;
        case 's':
            move(0, 1);
            break;
        case 'd':
            move(1, 0);
            break;
        case 't':
            lightTorch();
            break;
        case 'r':
            shootAction();
            break;
        case '?':
            help();
            break;
        default:
            cout << "AAAAAHHH" << endl;
    }
}

bool Game::checkEndGame() {
    if (player -> getRations() <= 0) {
        cout << "YOU STARVED..." << endl;
        return true;
    }
    if (player -> getLives() <= 0) {
        cout << "YOU WERE KILLED..." << endl;
        return true;
    }
    return endGame;
}


void Game::run() {
    help();
    player -> changeMap(new Map(4, 4, player));
    map = player -> getMap();

    while (!endGame && player) {
        printDisplay();
        getInput();
        Map* newMap = player -> getMap();
        if (newMap != map) {
            delete map;
            map = newMap;
        }
        endGame = checkEndGame();
    }

    cout << "Your final score was " << player -> getGold() << endl;
}