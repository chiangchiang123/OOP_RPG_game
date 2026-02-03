#include "box.h"
#include <stdlib.h>
#include "../../functions/AnsiPrint/AnsiPrint.h"

Box::Box(Position initialPosition): GameObject(initialPosition, 0, 0, "box") {
}

// add your code to implement the Dragon class here


Box::~Box(){

}

Position Box::nextPosition(){
    return getPosition();
}






// render function

void Box::render() {
    AnsiPrint("<>", white, pink);
}
