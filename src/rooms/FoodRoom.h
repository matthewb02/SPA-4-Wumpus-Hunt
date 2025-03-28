//
// Created by benderm on 3/28/2025.
//

#ifndef FOODROOM_H
#define FOODROOM_H

#include "Room.h"

class FoodRoom : public Room {
private:
    bool looted;
public:
    FoodRoom() : looted(false) {}
    void enter(Player* player) override;
    char getIcon() override;
};



#endif //FOODROOM_H
