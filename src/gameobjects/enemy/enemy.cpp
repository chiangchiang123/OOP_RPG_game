#include "enemy.h"
using namespace std;

// add your code to implement the Enemy class here

Enemy::Enemy(Position initialPosition, int health, int attack, string name):GameObject(initialPosition, health, attack, name){

}

Enemy::Enemy(Position initialPosition, int health, int attack, string name, bool lastBoss):GameObject(initialPosition, health, attack, name), lastBoss(lastBoss){

}

Enemy::~Enemy(){

}

bool Enemy::isLastBoss(){
    return lastBoss;
}
