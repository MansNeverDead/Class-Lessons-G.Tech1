#include <cstdlib>
#include <conio.h>
#include "../Map/Map.h"
#include "Entity.h"
#include "Players/Player.h"
#include "Monsters/Zombie.h"

void Entity::receiveDamage(int value) {
    HP -= value;
}

bool Entity::checkTile(Vector2 pos) {
		if (Game::getInstance().get_map().get_tile(pos) == ground) {
			return true;
		}
		return false;
	};

Player::Player(int hp, int attackValue, char displayValue, StateEnum startingState) 
: Entity(hp, attackValue, displayValue, startingState) {};

Zombie::Zombie(int hp, int attackValue, char displayValue, StateEnum startingState) 
: Entity(hp, attackValue, displayValue, startingState) {};


