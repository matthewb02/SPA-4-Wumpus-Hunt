//
// Created by benderm on 3/28/2025.
//

#ifndef SMALLFOODROOM_H
#define SMALLFOODROOM_H

#include "Room.h"

class SmallFoodRoom : public Room {
private:
    bool looted;
public:
    SmallFoodRoom() : looted(false) {}
    void enter(Player *player) override;
};



#endif //SMALLFOODROOM_H
