//
// Created by benderm on 3/28/2025.
//

#ifndef FOUNTAIN_H
#define FOUNTAIN_H

#include "Room.h"

class Fountain : public Room {
private:
    bool used;
public:
    Fountain() : used(false) {}
    void enter(Player* player) override;
    char getIcon() override;
};



#endif //FOUNTAIN_H
