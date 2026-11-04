#include <cstdlib>
#include <conio.h>
#include "../Map/Map.h"
#include "../States/State.h"
#include "Entity.h"
#include "Players/Player.h"
#include "Monsters/Zombie.h"

Player::Player(int hp, int attackValue, char displayValue, StateEnum startingState) 
: Entity(hp, attackValue, displayValue, startingState) {};

Zombie::Zombie(int hp, int attackValue, char displayValue, StateEnum startingState) 
: Entity(hp, attackValue, displayValue, startingState) {};


void Player::attacking(Entity& victim) {
    victim.receiveDamage(attack);
}
