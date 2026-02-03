#include "room.h"
#include "roomdata.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"
#include <vector>
using namespace std;

// read data to the Room class
Room::Room(RoomData data) {
    this->roomID = data.id;
    this->roomName = data.name;
    this->roomDescription = data.description;

    this->playerInitialPosition = data.playerInitialPosition;

    for(auto enemy : data.enemies) {
        this->enemies.push_back(enemy);
    }

    for(auto box : data.box) {
        this->box.push_back(box);
    }

    for (int y = 0; y < GAME_WINDOW_SIZE_Y; y++) {
        for (int x = 0; x < GAME_WINDOW_SIZE_X; x++) {
            this->defaultRoomObjectMap[y][x] = RoomObject(data.defaultRoomObjectMap[y][x]);
        }
    }
}

// add your code to implement the Room class here

Room::~Room(){
 
}

bool Room::walkable(Position position){
    if(defaultRoomObjectMap[position.getY()][position.getX()] == OBJECT_WALL || defaultRoomObjectMap[position.getY()][position.getX()] == OBJECT_ROCK || defaultRoomObjectMap[position.getY()][position.getX()] == OBJECT_WATER || position.getX() == -1 || position.getX() == 35 || position.getY() == -1 || position.getY() == 20){
        return false;                    
    }
    return true;    
}

const vector <Enemy *> & Room::getEnemies(){
    return enemies;
}

const vector <Box *> & Room::getBox(){
    return box;
}

void Room::destroyEnemy(Enemy *enemy){
    int round = enemies.size();
    for(int i = 0; i < round; i++){
        if(enemies[i] == enemy){
            enemies.erase(enemies.begin() + i);
            break;
        }
    }
}

void Room::destroyBox(){
    box.pop_back();
}

int Room::getRoomID(){
    return roomID;
}

void Room::changeRoomMap(RoomData data){
    for (int y = 0; y < GAME_WINDOW_SIZE_Y; y++) {
        for (int x = 0; x < GAME_WINDOW_SIZE_X; x++) {
            this->defaultRoomObjectMap[y][x] = RoomObject(data.defaultRoomObjectMap[y][x]);
        }
    }
}









// render
void Room::render(Position position) {
    switch(this->defaultRoomObjectMap[position.getY()][position.getX()]) {
        case OBJECT_NONE:
            AnsiPrint("  ", black, black);
            break;
        case OBJECT_DOOR:
            AnsiPrint("DR", yellow, black);
            break;
        case OBJECT_WALL:
            AnsiPrint("██", white, black);
            break;
        case OBJECT_GRASS:
            AnsiPrint("WW", green, black);
            break;
        case OBJECT_ROCK:
            AnsiPrint("▲▲", yellow, black);
            break;
        case OBJECT_WATER:
            if(rand() % 2 == 0) {
                AnsiPrint("~~", cyan, blue);
            } else {
                AnsiPrint("……", cyan, blue);
            }
            break;
        case OBJECT_FLOWER:
            AnsiPrint("∗∗", red, black);
            break;
        case OBJECT_PLACE_BLUE:
            AnsiPrint("██", blue, blue);
            break;
        case OBJECT_PLACE_RED:
            AnsiPrint("██", red, red);
            break;
        case OBJECT_PLACE_GREEN:
            AnsiPrint("██", green, green);
            break;
        case OBJECT_PLACE_YELLOW:
            AnsiPrint("██", yellow, yellow);
            break;
        case OBJECT_EGG:
            AnsiPrint("| ", yellow, black);
            break;
    }
}
