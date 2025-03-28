//
// Created by benderm on 3/28/2025.
//

#ifndef SHOP_H
#define SHOP_H

#include "Room.h"

class Shop : public Room {
private:
  bool purchased;
public:
  void enter(Player *player) override;
  char getIcon() override;
};



#endif //SHOP_H
