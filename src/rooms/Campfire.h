//
// Created by benderm on 3/28/2025.
//

#ifndef CAMPFIRE_H
#define CAMPFIRE_H

#include "Room.h"

class Campfire : public Room {
public:
    void enter(Player *player) override;
    char getIcon() override;
};



#endif //CAMPFIRE_H
