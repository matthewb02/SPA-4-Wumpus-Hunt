//
// Created by benderm on 3/26/2025.
//

#include <iostream>
#include "Map.h"

using namespace std;

int main() {
	Player player = Player();
	Map map = Map(4, 4);
	int x = 0;
	int y = 0;
	char input;
	while (input != 'q') {
		map.setPlayerPosition(x, y);
		map.printMap();
		cout << "Input w, a, s, d, or q:";
		cin >> input;
		switch (input) {
			case 'w':
				y--;
				break;
			case 'a':
				x--;
				break;
			case 's':
				y++;
				break;
			case 'd':
				x++;
				break;
			default:
				cout << "AAAAAHHH" << endl;
		}
	}
    return 0;
}