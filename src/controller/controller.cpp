#include <iostream>

#include "controller.h"
#include "../gameobjects/room/roomdata.h"
#include "../functions/position/position.h"
#include "../functions/AnsiPrint/AnsiPrint.h"
#include "../gameobjects/block/block.h"

#include "../gameprocess/allgameprocess.h"
using namespace std;

Controller::Controller() {
    const int defaultRoomIndex = 1;
    RoomData roomData = ROOM_DATA[defaultRoomIndex];
    //Room *room = new Room(roomData);
    //rooms.insert(std::pair<int, Room *>(defaultRoomIndex, room));
    for(int i = 0; i < 8; i++){
        rooms.insert(pair<int, Room *>(i, new Room(ROOM_DATA[i])));
    }
    
    currentRoomIndex = defaultRoomIndex;
    player = new Player(roomData.playerInitialPosition);

    state = PROCESS_MOVEMENT;
    currentProcess = new Move(player, rooms[1], blocks, isegg);
}

Controller::~Controller() {
    for (size_t i = 0; i < rooms.size(); i++) {
        delete rooms[i];
    }
    delete player;
}

RunningState Controller::run(InputState action) {

    if(state == PROCESS_GAMEOVER) {
        return EXIT;
    }

    if(state == PROCESS_GAMECLEAR) {
        return EXIT;
    }

    if(currentRoomIndex == 2 && blocks.size() > 0 && blocks[0]->getPosition() == Position(16, 4) && blocks[1]->getPosition() == Position(11, 9) && blocks[2]->getPosition() == Position(21, 9) && blocks[3]->getPosition() == Position(16, 14)){
        rooms[2]->changeRoomMap(ROOM_DATA[6]);
    }
    else if(currentRoomIndex == 2){
        rooms[2]->changeRoomMap(ROOM_DATA[2]);
    }
    if(currentRoomIndex == 5 && player->getPosition() == Position(25, 9)){
        isegg = 1;
        rooms[1]->changeRoomMap(ROOM_DATA[7]);
        player->isegg();
    }

    ProcessInfo info = currentProcess->run(action);

    // add your code to implement process control
    
    switch(info){
        case MOVE_FINISH_ROOMCHANGE_UP:
            currentRoomIndex = currentRoomIndex - 1;
            delete currentProcess;
            currentProcess = new Move(player, rooms[currentRoomIndex], blocks, isegg);
            break;
        case MOVE_FINISH_ROOMCHANGE_DOWN:
            currentRoomIndex = currentRoomIndex + 1;
            delete currentProcess;
            currentProcess = new Move(player, rooms[currentRoomIndex], blocks, isegg);
            break;
        case MOVE_FINISH_ROOMCHANGE_LEFT:
            currentRoomIndex = currentRoomIndex - 2;
            delete currentProcess;
            currentProcess = new Move(player, rooms[currentRoomIndex], blocks, isegg);
            break;
        case MOVE_FINISH_ROOMCHANGE_RIGHT:
            currentRoomIndex = currentRoomIndex + 2;
            delete currentProcess;
            currentProcess = new Move(player, rooms[currentRoomIndex], blocks, isegg);
            break;
        case GO_EGG_ROOM:
            currentRoomIndex--;
            delete currentProcess;
            currentProcess = new Move(player, rooms[currentRoomIndex], blocks, isegg);
            break;
        case LEAVE_EGG_ROOM:
            currentRoomIndex++;
            delete currentProcess;
            currentProcess = new Move(player, rooms[currentRoomIndex], blocks, isegg);
            break;
        case MOVE_FINISH_BATTLE:
            delete currentProcess;
            for(auto enemy : rooms[currentRoomIndex]->getEnemies()){
                if(player->getPosition() == enemy->getPosition()){
                    currentProcess = new Battle(player, enemy);
                }
            }
            break;
        case MOVE_FINISH_PAUSE:
            delete currentProcess;
            currentProcess = new Pause;
            break;
        case PAUSE_FINISH:
            delete currentProcess;
            currentProcess = new Move(player, rooms[currentRoomIndex],blocks, isegg);
            break;
        case MOVE_FINISH_OPEN_BOX:
            delete currentProcess;
            currentProcess = new OpenBox;
            rooms[2]->destroyBox();
            rooms[6]->destroyBox();
            player->leveup();
            break;
        case OPEN_BOX_FINISH_MOVE:
            delete currentProcess;
            currentProcess = new Move(player, rooms[currentRoomIndex], blocks, isegg);
            break;
        case BATTLE_FINISH_PLAYER_WIN:
            if(currentRoomIndex == 5){
                delete currentProcess;
                currentProcess = new GameClear;
                state = PROCESS_GAMECLEAR;
            }
            else{
                for(auto enemy : rooms[currentRoomIndex]->getEnemies()){
                    if(player->getPosition() == enemy->getPosition()){
                        rooms[currentRoomIndex]->destroyEnemy(enemy);
                    }
                }
                if(rooms[currentRoomIndex]->getEnemies().size() == 0){
                    blocks.push_back(new Block(Position(5, 5), 0));
                    blocks.push_back(new Block(Position(10, 13), 1));
                    blocks.push_back(new Block(Position(23, 7), 2));
                    blocks.push_back(new Block(Position(25, 15), 3));
                }
                delete currentProcess;
                currentProcess = new Move(player, rooms[currentRoomIndex], blocks, isegg);
            }
            break;
        case BATTLE_FINISH_PLAYER_DEAD:
            delete currentProcess;
            currentProcess = new GameOver;
            state = PROCESS_GAMEOVER;
            break;
        default:
            break;
    }

    this->render();

    return PLAY;
}

// Add your code to implement the Controller class here.

void Controller::roomChange(int roomIndex){
    currentRoomIndex = roomIndex;
}

void Controller::stateChange(GameProcessState newState){
    state = newState;
}



// render
void Controller::render() {
    currentProcess->render();
    output();
}
