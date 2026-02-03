#ifndef BLOCK_H
#define BLOCK_H

#include "../../gamecore/gamestate.h"
#include "../gameobject.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"
#include <string>
using namespace GameState;
using namespace std;


class Block: public GameObject {
private:
    int roomindex;
    int index;
    string str[4] = {"~~", "ww", "∗∗", "▲▲"};
    color blockcolor[4] = {blue, green, red, yellow};
public:
    Block(Position initialPosition, int index);
    ~Block();
    
    Position nextPosition(InputState action);

    Position changeRoom(InputState action);

    void render();

    void changeRoomIndex(int roomindex);

    int getRoomIndex();
};

#endif