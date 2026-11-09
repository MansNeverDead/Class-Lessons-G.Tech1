#include <vector>

#include "../Utilities/Vector2.h"
#include "../Map/Map.h"
#include "../Utilities/Buffer.h"
#include "../Game/Game.h"
#include "Entity.h"

using namespace std;

void Entity::changePosition(Vector2 newPosition) {
	position = newPosition;
}

bool Entity::CheckTile(Vector2 pos){
	Tile_type tile = Game::getInstance().getMap().getTile(pos);
	for (int i = 0; i < walkableTile.size(); i++) {
		if (walkableTile[i] == tile){
			return true;
		}
	}
	return false;
}

bool Entity::tryToMove(Vector2 dir){
	Vector2 new_pos = position + dir;

	if (CheckTile(new_pos)){
		position = new_pos;
		return true;
	}

	return false;
}

void Entity::changeHP(int value){
	if (value <= 0) {
		die();
	} else {
		HP = value;
   	};
}

void Entity::draw(){
	Buffer::getInstance().draw(display, position);
}

void Entity::update(){
	move();
}

void Entity::receiveDamage(int value) {
	if (value <= 0){
		changeHP(HP - value);
	}
}

void Entity::move(){
	while (!tryToMove(chooseDirection()));
}

int Entity::getHP() {
	return HP;
}

int Entity::getID() {
	return ID;
}
	
int Entity::getAttack() {
	return attack;
};

void Entity::setPos(Vector2 value){
    position = value;
}

Vector2 Entity::getPosition() {
	return position;
}

void Entity::CheckCollisions() {}

Entity::Entity(int x, int y, char displayValue)
    : position{ x, y }, display(displayValue) {} 

void Entity::die() {
	return;
}
	