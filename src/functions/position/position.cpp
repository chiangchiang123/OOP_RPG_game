#include "position.h"
#include "../../controller/enviroment.h"

// Add your code to implement the Position class here.
Position::Position(int initialPositionX, int initialPositionY)
:positionX(initialPositionX), positionY(initialPositionY){}

Position::Position(){}
Position::~Position(){}

int Position::getX() const{
    return positionX;
}

int Position::getY() const{
    return positionY;
}

bool Position::operator==(const Position &other) const{
    if(getX() == other.getX() && getY() == other.getY()){
        return true;
    }
    return false;
}