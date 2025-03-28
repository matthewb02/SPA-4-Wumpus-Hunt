//
// Created by benderm on 3/27/2025.
//

#ifndef TRAP_H
#define TRAP_H

#include "Room.h"

class Trap : public Room {
private:
    bool active;
public:
    Trap() : active(true) {}
    void enter(Player* player) override;
    char getIcon() override;
};



#endif //TRAP_H
