//
// Created by benderm on 3/26/2025.
//

#include "Room.h"
#include <iostream>

using namespace std;

bool Room::isRevealed() {
  return revealed;
}

void Room::reveal() {
  revealed = true;
}

void Room::shoot() {

}

void Room::enter(Player* player) {
    cout << "There is nothing here." << endl;
}

string Room::getWarning() {
  return "";
}

char Room::getIcon() {
  return ' ';
}

bool Room::canEnter() {
  return true;
}