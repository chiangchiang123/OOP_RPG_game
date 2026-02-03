#include "gameobject.h"
using namespace std;


// Add your code to implement the GameObject class here.

GameObject::GameObject(Position initialPosition, int maxHealth, int attack, string name)
:position(initialPosition), maxHealth(maxHealth), health(maxHealth), attack(attack), name(name){

}

GameObject::~GameObject(){

}

Position GameObject::getPosition(){
    return position;
}

void GameObject::setPosition(Position position){
    //this->position.positionX = position.getX();
    //this->position.positionY = position.getY();
    this->position = position;
}

int GameObject::getHealth(){
    return health;
}

int GameObject::getMaxHealth(){
    return maxHealth;
}

string GameObject::getName(){
    return name;
}

int GameObject::getAttack(){
    return attack;
}

void GameObject::hurt(int damage){
    health = health - damage;
    if(health < 0){
        health = 0;
    }
}

void GameObject::heal_way(int amount){
    health = health + amount;
    if(health > maxHealth){
        health = maxHealth;
    }
}

void GameObject::changeability(){
    maxHealth = maxHealth * 2;
    attack = attack * 2;
    health = maxHealth;
}
