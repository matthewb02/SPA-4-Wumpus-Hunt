//
// Created by benderm on 3/28/2025.
//

#ifndef TORCHROOM_H
#define TORCHROOM_H

#include "Room.h"

class TorchRoom : public Room {
private:
    bool looted;
public:
    TorchRoom() : looted(false) {}
    void enter(Player* player) override;
};



#endif //TORCHROOM_H
