//
// Created by benderm on 3/26/2025.
//

#ifndef WALL_H
#define WALL_H

#include "Room.h"

class Wall : public Room {
public:
    char getIcon() override;
    bool canEnter() override;
};



#endif //WALL_H
