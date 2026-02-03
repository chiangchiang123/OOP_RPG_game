#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

#include "../../controller/enviroment.h"
#include "../../functions/position/position.h"
#include "../enemy/enemy.h"
#include "../box/box.h"
//#include "../block/block.h"
#include "roomstate.h"

using namespace RoomState;

class Room {
    private:
        int roomID;
        std::string roomName;
        std::string roomDescription;

        Position playerInitialPosition;

        std::vector<Enemy *> enemies;

        std::vector<Box *> box;

        RoomObject defaultRoomObjectMap[GAME_WINDOW_SIZE_Y][GAME_WINDOW_SIZE_X];

    public:
        Room(RoomData roomData);
        ~Room();

        bool walkable(Position position);

        void destroyEnemy(Enemy *enemy);

        void destroyBox();

        const std::vector<Enemy *> & getEnemies();

        const std::vector<Box *> & getBox();

        void render(Position position);

        int getRoomID();

        void changeRoomMap(RoomData data);
};

#endif
