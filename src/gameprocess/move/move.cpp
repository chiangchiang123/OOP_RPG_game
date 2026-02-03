#include "move.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"
#include "../../controller/enviroment.h"
#include "../../functions/position/position.h"

// Move the code from controller.cpp to this file, completing the Move Class

Move::Move(Player* player, Room* room, vector <Block *> &blocks, int egg){
    this->player = player;
    this->room = room;
    this->blocks = blocks;
    this->egg = egg;
}

Move::~Move(){
    //delete player;
    //delete room;
}

ProcessInfo Move::run(InputState action){
    switch(action){
        case ACTION_UP:
            if(player->getPosition().getY() - 1 == -1 && (room->getRoomID() == 3 || room->getRoomID() == 4)){
                player->setPosition(Position(player->getPosition().getX(), 19));
                for(auto block : blocks){
                    if(room->getRoomID() - 1 == block->getRoomIndex() && block->getPosition() == player->getPosition() && room->walkable(Position(block->getPosition().getX(), block->getPosition().getY() - 1))){
                        block->nextPosition(action);
                    }
                }
                return MOVE_FINISH_ROOMCHANGE_UP;
            }
            else if(room->walkable(Position(player->getPosition().getX(), player->getPosition().getY() - 1))){
                int flag = 0;
                for(auto block : blocks){
                    if(room->getRoomID() == block->getRoomIndex() && block->getPosition() == Position(player->getPosition().getX(), player->getPosition().getY() - 1) && block->getPosition().getY() - 1 == -1 && (block->getRoomIndex() == 3 || block->getRoomIndex() == 4)){
                        block->changeRoom(action);
                    }
                    else if(room->getRoomID() == block->getRoomIndex() && block->getPosition() == Position(player->getPosition().getX(), player->getPosition().getY() - 1) && room->walkable(Position(block->getPosition().getX(), block->getPosition().getY() - 1))){
                        block->nextPosition(action);
                    }
                    else if(room->getRoomID() == block->getRoomIndex() && block->getPosition() == Position(player->getPosition().getX(), player->getPosition().getY() - 1) && !(room->walkable(Position(block->getPosition().getX(), block->getPosition().getY() - 1)))){
                        flag = 1;
                    }
                }
                if(flag) break;
                player->setPosition(Position(player->getPosition().getX(), player->getPosition().getY() - 1));
            }
            break;
        case ACTION_DOWN:
            if(player->getPosition().getY() + 1 == 20 && (room->getRoomID() == 3 || room->getRoomID() == 2)){
                player->setPosition(Position(player->getPosition().getX(), 0));
                for(auto block : blocks){
                    if(room->getRoomID() + 1 == block->getRoomIndex() && block->getPosition() == player->getPosition() && room->walkable(Position(block->getPosition().getX(), block->getPosition().getY() + 1))){
                        block->nextPosition(action);
                    }
                }
                return MOVE_FINISH_ROOMCHANGE_DOWN;
            }
            else if(room->walkable(Position(player->getPosition().getX(), player->getPosition().getY() + 1))){
                int flag = 0;
                for(auto block : blocks){
                    if(room->getRoomID() == block->getRoomIndex() && block->getPosition() == Position(player->getPosition().getX(), player->getPosition().getY() + 1) && block->getPosition().getY() + 1 == 20 && (block->getRoomIndex() == 3 || block->getRoomIndex() == 2)){
                        block->changeRoom(action);
                    }
                    else if(room->getRoomID() == block->getRoomIndex() && block->getPosition() == Position(player->getPosition().getX(), player->getPosition().getY() + 1) && room->walkable(Position(block->getPosition().getX(), block->getPosition().getY() + 1))){
                        block->nextPosition(action);
                    }
                    else if(room->getRoomID() == block->getRoomIndex() && block->getPosition() == Position(player->getPosition().getX(), player->getPosition().getY() + 1) && !(room->walkable(Position(block->getPosition().getX(), block->getPosition().getY() + 1)))){
                        flag = 1;
                    }
                }
                if(flag) break;
                player->setPosition(Position(player->getPosition().getX(), player->getPosition().getY() + 1));
            }
            break;
        case ACTION_LEFT:
            if(egg && player->getPosition().getX() - 1 == -1 && room->getRoomID() == 1){
                player->setPosition(Position(34, player->getPosition().getY()));
                for(auto block : blocks){
                    if(room->getRoomID() - 1 == block->getRoomIndex() && block->getPosition() == player->getPosition() && room->walkable(Position(block->getPosition().getX() - 1, block->getPosition().getY()))){
                        block->nextPosition(action);
                    }
                }
                return GO_EGG_ROOM;

            }
            else if(player->getPosition().getX() - 1 == -1 && (room->getRoomID() == 3 || room->getRoomID() == 5)){
                player->setPosition(Position(34, player->getPosition().getY()));
                for(auto block : blocks){
                    if(room->getRoomID() - 2 == block->getRoomIndex() && block->getPosition() == player->getPosition() && room->walkable(Position(block->getPosition().getX() - 1, block->getPosition().getY()))){
                        block->nextPosition(action);
                    }
                }
                return MOVE_FINISH_ROOMCHANGE_LEFT;

            }
            else if(room->walkable(Position(player->getPosition().getX() - 1, player->getPosition().getY()))){
                int flag = 0;
                for(auto block : blocks){
                    if(room->getRoomID() + 2 == block->getRoomIndex() && block->getPosition() == Position(player->getPosition().getX() - 1, player->getPosition().getY()) && block->getPosition().getX() - 1 == -1 && (block->getRoomIndex() == 3 || block->getRoomIndex() == 5)){
                        block->changeRoom(action);
                    }
                    else if(room->getRoomID() == block->getRoomIndex() && block->getPosition() == Position(player->getPosition().getX() - 1, player->getPosition().getY()) && room->walkable(Position(block->getPosition().getX() - 1, block->getPosition().getY()))){
                        block->nextPosition(action);
                    }
                    else if(room->getRoomID() == block->getRoomIndex() && block->getPosition() == Position(player->getPosition().getX() - 1, player->getPosition().getY()) && !(room->walkable(Position(block->getPosition().getX() - 1, block->getPosition().getY())))){
                        flag = 1;
                    }
                }
                if(flag) break;
                player->setPosition(Position(player->getPosition().getX() - 1, player->getPosition().getY()));
            }
            break;
        case ACTION_RIGHT:
            if(egg && player->getPosition().getX() + 1 == 35 && room->getRoomID() == 0){
                player->setPosition(Position(0, player->getPosition().getY()));
                for(auto block : blocks){
                    if(room->getRoomID() + 1 == block->getRoomIndex() && block->getPosition() == player->getPosition() && room->walkable(Position(block->getPosition().getX() - 1, block->getPosition().getY()))){
                        block->nextPosition(action);
                    }
                }
                return LEAVE_EGG_ROOM;
            }
            else if(player->getPosition().getX() + 1 == 35 && (room->getRoomID() == 3 || room->getRoomID() == 1)){
                player->setPosition(Position(0, player->getPosition().getY()));
                for(auto block : blocks){
                    if(room->getRoomID() == block->getRoomIndex() && block->getPosition() == player->getPosition() && room->walkable(Position(block->getPosition().getX() + 1, block->getPosition().getY()))){
                        block->nextPosition(action);
                    }
                }
                return MOVE_FINISH_ROOMCHANGE_RIGHT;
            }
            else if(room->walkable(Position(player->getPosition().getX() + 1, player->getPosition().getY()))){
                int flag = 0;
                for(auto block : blocks){
                    if(room->getRoomID() == block->getRoomIndex() && block->getPosition() == Position(player->getPosition().getX() + 1, player->getPosition().getY()) && block->getPosition().getX() + 1 == 35 && (block->getRoomIndex() == 3 || block->getRoomIndex() == 1)){
                        block->changeRoom(action);
                    }
                    else if(room->getRoomID() == block->getRoomIndex() && block->getPosition() == Position(player->getPosition().getX() + 1, player->getPosition().getY()) && room->walkable(Position(block->getPosition().getX() + 1, block->getPosition().getY()))){
                        block->nextPosition(action);
                    }
                    else if(room->getRoomID() == block->getRoomIndex() && block->getPosition() == Position(player->getPosition().getX() + 1, player->getPosition().getY()) && !(room->walkable(Position(block->getPosition().getX() + 1, block->getPosition().getY())))){
                        flag = 1;
                    }
                }
                if(flag) break;
                player->setPosition(Position(player->getPosition().getX() + 1, player->getPosition().getY()));
            }
            break;
        case ACTION_PAUSE:
            return MOVE_FINISH_PAUSE;
        default:
            break;
    }
    for(auto enemy : room->getEnemies()){
        Position temp = enemy->nextPosition();
        if(room->walkable(temp)){
            enemy->setPosition(temp);
        }
        if(player->getPosition() == enemy->getPosition()){ 
            return MOVE_FINISH_BATTLE;
        }
    }
    for(auto box : room->getBox()){
        if(player->getPosition() == box->getPosition()){ 
            return MOVE_FINISH_OPEN_BOX;
        }
    }
    /*for(auto enemy : room->getEnemies()){
        Position temp = enemy->nextPosition();
        if(room->walkable(temp)){
            enemy->setPosition(temp);                            
        }                 
    }*/
    //this->render();
    return CONTINUE;
}




void Move::render() {
    for (int y = 0; y < GAME_WINDOW_SIZE_Y; y++) {
        for (int x = 0; x < GAME_WINDOW_SIZE_X; x++) {
            if(player->getPosition() == Position(x, y)) {
                player->render();
                continue;
            }
            bool flag = false;
            for(auto enemy : room->getEnemies()) {
                if(enemy->getPosition() == Position(x, y)) {
                    enemy->render();
                    flag = true;
                    continue;
                }
            }
            if(flag) continue;
            for(auto block : blocks) {
                if(block->getPosition() == Position(x, y) && block->getRoomIndex() == room->getRoomID()) {
                    block->render();
                    flag = true;
                    continue;
                }
            }
            if(flag) continue;
            for(auto box : room->getBox()) {
                if(box->getPosition() == Position(x, y)) {
                    box->render();
                    flag = true;
                    continue;
                }
            }
            if(flag) continue;
            room->render(Position(x, y));
        }
        AnsiPrint("\n", nochange, nochange);
    }
}
