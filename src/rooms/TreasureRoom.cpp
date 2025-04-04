//
// Created by benderm on 3/27/2025.
//

#include "TreasureRoom.h"

#include <iostream>

using namespace std;

void TreasureRoom::enter(Player* player) {
  if (looted)
    cout << "There's an empty chest here." << endl;
  else {
    cout << "You've found a locked chest!" << endl;
    if (player -> getKeys() == 0)
      cout << "It needs a key to be opened." << endl;
    else {
      cout << "Would you like to spend a key to open it? (y): ";
      char in;
      cin >> in;
      if (in == 'y' || in == 'Y') {
        int gold = 25 * player -> getGoldMultiplier();
        cout << "You open the chest and find " << gold << " gold pieces!" << endl;
        player -> changeKeys(-1);
        player -> changeGold(gold);
        looted = true;
      }
    }
  }
}

char TreasureRoom::getIcon() {
  return looted ? ' ' : 'C';
}