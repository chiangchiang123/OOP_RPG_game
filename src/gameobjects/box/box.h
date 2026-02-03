#ifndef BOX_H
#define BOX_H

#include "../gameobject.h"

class Box: public GameObject {
public:
    Box(Position initialPosition);
    ~Box();

    // Complete the Dragon class with reference to the Enemy class.

    Position nextPosition();

    void render();







};

#endif