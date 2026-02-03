#ifndef ROOMSTATE_H
#define ROOMSTATE_H

#include <vector>

namespace RoomState
{
    enum RoomObject {
        OBJECT_NONE = 0,
        OBJECT_DOOR = 1,
        OBJECT_WALL = 2,
        OBJECT_GRASS = 3,
        OBJECT_ROCK = 4,
        OBJECT_WATER = 5,
        OBJECT_PLACE_BLUE = 6,
        OBJECT_PLACE_RED = 7,
        OBJECT_PLACE_GREEN = 8,
        OBJECT_PLACE_YELLOW = 9,
        OBJECT_FLOWER = 10,
        OBJECT_EGG = 11
    };

    struct RoomData {
        int id;
        std::string name;
        std::string description;
        Position playerInitialPosition;
        std::vector<Enemy *> enemies;
        std::vector<Box *> box;
        int defaultRoomObjectMap[GAME_WINDOW_SIZE_Y][GAME_WINDOW_SIZE_X];
    };
} // namespace RoomState

#endif