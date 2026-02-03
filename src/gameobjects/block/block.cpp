#include "block.h"
#include "../gameobject.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"
#include <string>
using namespace std;

Block::Block(Position initialPosition, int index)
:GameObject(initialPosition, 0, 0, "block"), index(index){
    roomindex = 4;
}

Block::~Block(){

}

void Block::changeRoomIndex(int roomindex){
    this->roomindex = roomindex;
}

int Block::getRoomIndex(){
    return roomindex;
}

Position Block::nextPosition(InputState action){
    switch(action){
        case ACTION_UP:
            setPosition(Position(getPosition().getX(), getPosition().getY() - 1));
            break;
        case ACTION_DOWN:
            setPosition(Position(getPosition().getX(), getPosition().getY() + 1));
            break;
        case ACTION_RIGHT:
            setPosition(Position(getPosition().getX() + 1, getPosition().getY()));
            break;
        case ACTION_LEFT:
            setPosition(Position(getPosition().getX() - 1, getPosition().getY()));
            break;
        default:
            break;
    }
}

Position Block::changeRoom(InputState action){
    int roomindex;
    switch(action){
        case ACTION_UP:
            roomindex = getRoomIndex() - 1;
            changeRoomIndex(roomindex);
            setPosition(Position(getPosition().getX(), 19));
            break;
        case ACTION_DOWN:
            roomindex = getRoomIndex() + 1;
            changeRoomIndex(roomindex);
            setPosition(Position(getPosition().getX(), 0));
            break;
        case ACTION_RIGHT:
            roomindex = getRoomIndex() + 2;
            changeRoomIndex(roomindex);
            setPosition(Position(0, getPosition().getY()));
            break;
        case ACTION_LEFT:
            roomindex = getRoomIndex() - 2;
            changeRoomIndex(roomindex);
            setPosition(Position(34, getPosition().getY()));
            break;
        default:
            break;
    }
}

void Block::render(){
    string temp = str[index];
    AnsiPrint(&temp[0], white, blockcolor[index]);
}