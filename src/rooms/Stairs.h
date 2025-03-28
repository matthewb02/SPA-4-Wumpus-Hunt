//
// Created by benderm on 3/28/2025.
//

#ifndef STAIRS_H
#define STAIRS_H

#include "Room.h"

class Stairs : public Room {
private:
    int newMapW, newMapH;
public:
    Stairs(int newW, int newH) : newMapW(newW), newMapH(newH) {}
    void enter(Player *player) override;
    char getIcon() override;
};



#endif //STAIRS_H
