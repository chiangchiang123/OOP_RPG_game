#include "slime.h"
#include <stdlib.h>

#include "../../../functions/AnsiPrint/AnsiPrint.h"

Slime::Slime(Position initialPosition): Enemy(initialPosition, 5, 1, "Slime") {
}

// add your code to implement the Slime class here


Slime::~Slime(){

}

Position Slime::nextPosition(){
    int left_right[4] = {-1, 1, 0, 0};
    int up_down[4] = {0, 0, -1, 1};
    int choose = rand() % 4;
    return Position(getPosition().getX() + left_right[choose], getPosition().getY() + up_down[choose]);
}



// render function

void Slime::render() {
    AnsiPrint("==", yellow, green);
}
