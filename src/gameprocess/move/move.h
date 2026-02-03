#ifndef MOVE_H
#define MOVE_H

#include "../gameprocess.h"
#include "../../gameobjects/player/player.h"
#include "../../gameobjects/room/room.h"
#include "../../gameobjects/block/block.h"
#include <vector>
using namespace std;

class Move: public GameProcessBase {
private:
    Player *player;
    
    Room *room;

    vector <Block *> blocks;

    int egg;
    
public:
    Move(Player* player, Room* room, vector <Block *> &blocks, int egg);
    ~Move();

    ProcessInfo run(InputState action);

    void render();
};

#endif