//
// Created by benderm on 3/27/2025.
//

#ifndef GENERATOR_H
#define GENERATOR_H

#include "rooms/Room.h"

class Generator {
private:
  int width, height;
  int startX, startY;
  int* map;
  void createSprawl(int r);
  bool setRoom(int r, int id);
  bool trySetRoom(int r, int id);
public:
  Generator(int w, int h);
  Room** generate();
  int getStartX();
  int getStartY();
};



#endif //GENERATOR_H
