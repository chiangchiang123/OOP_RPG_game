#include "player.h"
#include "../../controller/enviroment.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"

using namespace PlayerState;

// Add your code to implement the Player class here.

Player::Player(Position initialPosition)
:GameObject(initialPosition, 20, 4, "Player"){

}

Player::~Player(){

}

/*MoveState Player::move(InputState action){
    return MOVE;
}*/

void Player::heal(int amount){
    heal_way(amount);
}

int Player::getHealPower(){
    return healPower;
}

void Player::leveup(){
    changeability();
    healPower = healPower * 2;
    clothindex = 1;
    if(nameindex == 0){
        nameindex = 1;
    }
}

void Player::isegg(){
    nameindex = 2;
}

// render
void Player::render() {
    AnsiPrint("PL", namecolor[nameindex], clothcolor[clothindex]);
}

