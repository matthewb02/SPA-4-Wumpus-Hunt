//
// Created by benderm on 3/27/2025.
//

#ifndef MONSTER_H
#define MONSTER_H

#include "Room.h"

class Monster : public Room {
private:
    bool killed;
public:
    Monster() : killed(false) {}
    void enter(Player* player) override;
    void shoot() override;
    char getIcon() override;
};



#endif //MONSTER_H
