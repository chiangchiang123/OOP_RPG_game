#ifndef PLAYER_H
#define PLAYER_H

#include "../../gamecore/gamestate.h"
#include "../gameobject.h"
#include "playerstate.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"

using namespace PlayerState;
using namespace std;

class Player: public GameObject {
    int healPower = 8;
    const color clothcolor[2] = {blue, pink};
    const color namecolor[3] = {green, white, yellow};
    int clothindex = 0;
    int nameindex = 0;
public:
    Player(Position initialPosition);
    ~Player();

    //MoveState move(InputState action);

    // To enhance gameplay, a player healing option has been added.
    void heal(int amount);
    int getHealPower();
    
    void leveup();
    void isegg();
    void render();
};

#endif
