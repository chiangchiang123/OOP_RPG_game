#include "battle.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"
#include "../../controller/enviroment.h"
using namespace std;
using namespace GameProcess;

// add your code to implement the Battle class here

Battle::Battle(Player* player, Enemy* enemy){
    this->player = player;
    this->enemy = enemy;
    actionPlayerSelected = FORCE_ATTACK;
    state = ACTION_SELECTING;
}

Battle::~Battle(){
    //delete player;
    //delete enemy;
}

ProcessInfo Battle::run(InputState action){
    int enemychoose;
    switch(state){
        case ACTION_SELECTING:
            switch(action){
                case ACTION_UP:
                    switch(actionPlayerSelected){
                        case FORCE_ATTACK:
                            actionPlayerSelected = HEAL;
                            break;
                        case ATTACK:
                            actionPlayerSelected = FORCE_ATTACK;
                            break;
                        case DEFEND:
                            actionPlayerSelected = ATTACK;
                            break;
                        case HEAL:
                            actionPlayerSelected = DEFEND;
                            break;
                        default:
                            break;
                    }
                    break;
                case ACTION_DOWN:
                    switch (actionPlayerSelected){
                        case FORCE_ATTACK:
                            actionPlayerSelected = ATTACK;
                            break;
                        case ATTACK:
                            actionPlayerSelected = DEFEND;
                            break;
                        case DEFEND:
                            actionPlayerSelected = HEAL;
                            break;
                        case HEAL:
                            actionPlayerSelected = FORCE_ATTACK;
                            break;
                        default:
                            break;
                    }
                    break;
                case ACTION_CONFIRM:
                    enemychoose = rand() % 3;
                    switch(enemychoose){
                        case 0:
                            actionEnemySelected = FORCE_ATTACK;
                            break;
                        case 1:
                            actionEnemySelected = ATTACK;
                            break;
                        case 2:
                            actionEnemySelected = DEFEND;
                            break;
                        default:
                            break;
                    }
                    damageToPlayer = damageCalculate(actionEnemySelected, actionPlayerSelected, enemy->getAttack());
                    damageToEnemy = damageCalculate(actionPlayerSelected, actionEnemySelected, player->getAttack());
                    player->hurt(damageToPlayer);
                    if(damageToEnemy == -1){
                        player->heal(player->getHealPower());
                        damageToEnemy = 0;
                    }
                    else{
                        enemy->hurt(damageToEnemy);
                    }
                    state = TURN_END;
                    break;
                default:
                    break;
            }
            break;
        case TURN_END:
            if(action != ACTION_INIT){
                if(player->getHealth() <= 0){
                    state = PLAYER_DEAD;
                }
                else if(enemy->getHealth() <= 0){
                    state = ENEMY_DEAD;
                }
                else{
                state = ACTION_SELECTING;           
                }
            }   
            break;
        case ENEMY_DEAD:
            if(action != ACTION_INIT){
                return BATTLE_FINISH_PLAYER_WIN;
            }
            break;
        case PLAYER_DEAD:
            if(action != ACTION_INIT){
                return BATTLE_FINISH_PLAYER_DEAD;
            }
            break;
        default:
            break;
    }
    return CONTINUE;
}

int Battle::damageCalculate(BattleAction attackerAction, BattleAction targetAction, int damge){
    int sum = 0;
    int heal = 0;
    switch(attackerAction){
        case FORCE_ATTACK:
            sum = damge * FORCE_ATTACK_MULTIPLIER;
            break;
        case ATTACK:
            sum = damge * ATTACK_MULTIPLIER;
            break;
        case DEFEND:
            break;
        case HEAL:
            heal = 1;
            break;
        default:
            break;
    }
    switch(targetAction){
        case FORCE_ATTACK:
            sum = sum * FORCE_ATTACK_MULTIPLIER;
            break;
        case ATTACK:
            break;
        case DEFEND:
            if(heal){
                sum = -1;
            }
            else{
                sum = sum / DEFEND_MULTIPLIER;
            }
            break;
        case HEAL:
            if(heal){
                sum = -1;
            }
            else{
                sum = sum * FORCE_ATTACK_MULTIPLIER;
            }
            break;
        default:
            break;
    }
    return sum;
}


std::string Battle::BattleActionToString(BattleAction action) {
    switch(action) {
        case FORCE_ATTACK:
            return "force attack";
        case ATTACK:
            return "attack";
        case DEFEND:
            return "defend";
        case HEAL:
            return "heal";
        default:
            return "none";
    }


}

std::string repeat(const std::string& input, unsigned num) {
    std::string s;
    s.reserve(input.size() * num);
    while (num--) s += input;
    return s;
}

void Battle::render() {
    // remember screen size is defined in controller/enviroment.h

    // line 1
    AnsiPrint("\n", black, black);

    // life bar and name
    const int windowEdge = 1;
    const int lifeBarWidth = GAME_WINDOW_SIZE_X - windowEdge * 2; // 2 means left and right edge

    int playerHealthBlocks = (int) double(player->getHealth()) / double(player->getMaxHealth()) * lifeBarWidth;
    int enemyHealthBlocks = (int) double(enemy->getHealth()) / double(enemy->getMaxHealth()) * lifeBarWidth;

    std::string playerLifeBar = repeat("██", playerHealthBlocks) + repeat("__", (lifeBarWidth - playerHealthBlocks));
    std::string enemyLifeBar = repeat("__", (lifeBarWidth - enemyHealthBlocks)) + repeat("██", enemyHealthBlocks);

    // line 2
    AnsiPrint("  ", black, black);
    AnsiPrint(playerLifeBar.c_str(), blue, black);
    AnsiPrint("\n", black, black);

    // line 3
    AnsiPrint("  ", black, black);
    AnsiPrint(player->getName().c_str(), blue, black);
    AnsiPrint("\n", black, black);

    // line 4
    AnsiPrint("  ", black, black);
    AnsiPrint(std::string((GAME_WINDOW_SIZE_X - windowEdge * 2) * GAME_WINDOW_ONEBLOCK_WIDTH - enemy->getName().size(), ' ').c_str(), black, black);
    AnsiPrint(enemy->getName().c_str(), red, black);
    AnsiPrint("\n", black, black);

    // line 5
    AnsiPrint("  ", black, black);
    AnsiPrint(enemyLifeBar.c_str(), red, black);
    AnsiPrint("\n", black, black);

    // line 6~12
    AnsiPrint("\n\n\n\n\n\n\n", black, black);

    switch (state) {
        case ACTION_SELECTING: {
            // line 13 ~ 20
            AnsiPrint("  Please select your action:\n\n", white, black);
            AnsiPrint("    1) Force Attack\n", (actionPlayerSelected == FORCE_ATTACK ? yellow : white), black);
            AnsiPrint("    2) Attack\n", (actionPlayerSelected == ATTACK ? yellow : white), black);
            AnsiPrint("    3) Defend\n", (actionPlayerSelected == DEFEND ? yellow : white), black);
            AnsiPrint("    4) Heal\n\n", (actionPlayerSelected == HEAL ? yellow : white), black);
            AnsiPrint("  Press Enter to confirm.\n\n", white, black);

            break;
        }

        case TURN_END: {
            // line 13
            AnsiPrint("  You ", blue, black);
            AnsiPrint("performed the ", white, black);
            AnsiPrint(BattleActionToString(actionPlayerSelected).c_str(), yellow, black);
            AnsiPrint(" on the ", white, black);
            AnsiPrint(enemy->getName().c_str(), red, black);
            AnsiPrint(".\n", white, black);

            // line 14 15
            AnsiPrint("  ", black, black);
            AnsiPrint(enemy->getName().c_str(), red, black);
            AnsiPrint(" performed the ", white, black);
            AnsiPrint(BattleActionToString(actionEnemySelected).c_str(), yellow, black);
            AnsiPrint(" on ", white, black);
            AnsiPrint("You", blue, black);
            AnsiPrint(".\n\n", white, black);

            // line 16
            AnsiPrint("  You ", blue, black);
            AnsiPrint("dealt ", white, black);
            AnsiPrint(std::to_string(damageToEnemy).c_str(), yellow, black);
            AnsiPrint(" damage to ", white, black);
            AnsiPrint(enemy->getName().c_str(), red, black);
            AnsiPrint(".\n", white, black);

            // line 17 18
            AnsiPrint("  Enemy ", red, black);
            AnsiPrint("dealt ", white, black);
            AnsiPrint(std::to_string(damageToPlayer).c_str(), yellow, black);
            AnsiPrint(" damage to ", white, black);
            AnsiPrint("You", blue, black);
            AnsiPrint(".\n\n", white, black);

            // line 19 20
            AnsiPrint("  Press any key to continue.\n\n", white, black);
            break;
        }

        case ENEMY_DEAD: {
            // line 13
            AnsiPrint("  You ", blue, black);
            AnsiPrint("defeated ", white, black);
            AnsiPrint(enemy->getName().c_str(), red, black);
            AnsiPrint("!\n", blue, black);

            // line 14 ~ 20
            AnsiPrint("\n\n\n\n\n\n\n", black, black);
            break;
        }

        case PLAYER_DEAD: {
            // line 13
            AnsiPrint("  You ", red, black);
            AnsiPrint("were defeated by ", white, black);
            AnsiPrint(enemy->getName().c_str(), red, black);
            AnsiPrint("!\n", red, black);

            // line 14 ~ 20
            AnsiPrint("\n\n\n\n\n\n\n", black, black);
            break;
        }
    }
}
