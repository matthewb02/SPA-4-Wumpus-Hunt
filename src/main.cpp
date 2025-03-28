//
// Created by benderm on 3/26/2025.
//

#include <iostream>
#include "Map.h"

using namespace std;

int main() {
	Player player = Player();
	Map map = Map(4, 4, &player);
	char input;
	while (input != 'q') {
		map.printMap();
		cout << "gold: " << player.getGold() << endl;
		cout << player.getLives() << " lives | ";
		cout << player.getRations() << " rations | ";
		cout << player.getTorches() << " torches | ";
		cout << player.getArrows() << " arrows" << endl;
		if (player.getKeys() > 0)
			cout << "You have a key." << endl;
		if (player.getRations() <= 0) {
			cout << "YOU STARVED..." << endl;
			break;
		}
		if (player.getTorchDuration() == 0)
			cout << "YOU HAVE NO LIGHT!" << endl;
		cout << "Input w, a, s, d, l, or q:";
		cin >> input;
		cout << endl << endl << endl;
		switch (input) {
			case 'q':
				return 0;
			case 'w':
				if (map.canMovePlayer(0, -1)) {
					map.movePlayer(0, -1);
				}
				break;
			case 'a':
				if (map.canMovePlayer(-1, 0)) {
					map.movePlayer(-1, 0);
				}
				break;
			case 's':
				if (map.canMovePlayer(0, 1)) {
					map.movePlayer(0, 1);
				}
				break;
			case 'd':
				if (map.canMovePlayer(1, 0)) {
					map.movePlayer(1, 0);
				}
				break;
			case 'l':
				cout << "You light a new torch." << endl;
				player.changeTorches(-1);
				player.setTorchDuration(5);
				break;
			default:
				cout << "AAAAAHHH" << endl;
		}

		if (player.getLives() <= 0) {
			cout << "YOU WERE KILLED..." << endl;
			break;
		}
	}
	cout << "Your final score was " << player.getGold() << endl;
    return 0;
}

