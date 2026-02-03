#ifndef GAMEPROCESSSTATE_H
#define GAMEPROCESSSTATE_H

namespace GameProcess
{
    enum GameProcessState {
        PROCESS_MOVEMENT,
        PROCESS_PAUSE,
        PROCESS_BATTLE,
        PROCESS_GAMEOVER,
        PROCESS_GAMECLEAR,
        PROCESS_EXIT
    };

    enum ProcessInfo {
        CONTINUE,
        
        MOVE_FINISH_ROOMCHANGE_LEFT,
        MOVE_FINISH_ROOMCHANGE_RIGHT,
        MOVE_FINISH_ROOMCHANGE_UP,
        MOVE_FINISH_ROOMCHANGE_DOWN,
        GO_EGG_ROOM,
        LEAVE_EGG_ROOM,
        MOVE_FINISH_PAUSE,
        MOVE_FINISH_BATTLE,
        MOVE_FINISH_OPEN_BOX,
        OPEN_BOX_FINISH_MOVE,

        PAUSE_FINISH,

        BATTLE_FINISH_PLAYER_WIN,
        BATTLE_FINISH_PLAYER_DEAD,
    };
} // namespace GameProcess


#endif