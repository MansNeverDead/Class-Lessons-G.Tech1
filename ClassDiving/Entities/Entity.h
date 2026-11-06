#pragma once

#include "../Utilities/Vector2.h"
#include "../Map/Map.h"
#include "../Utilities/Buffer.h"
#include "../Game/Game.h"
#include <vector>

using namespace std;

class Entity {
protected:
	const int attack = 1;

	char display = ' ';

	Vector2 position;

	vector<Tile_type> walkableTile;

	int HP = 0;

	const int ID = 0;

	void changePosition(Vector2 newPosition) {
		position = newPosition;
	}

	virtual Vector2 chooseDirection();

	bool CheckTile(Vector2 pos){
		Tile_type tile = Game::getInstance().get_map().get_tile(pos);
		for (int i = 0; i < walkableTile.size(); i++) {
			if (walkableTile[i] == tile){
				return true;
			}
		}
		return false;
	}

	//This to check and hurt the enemy
    virtual void CheckCollisions();

	bool TryToMove(Vector2 dir){
		Vector2 new_pos = position + dir;

		if (CheckTile(new_pos)){
			position = new_pos;
			return true;
		}

		return false;
	}

	void changeHP(int value){
		if (value <= 0) {
			die();
		} else {
			HP = value;
    	};
	}

public:

	void draw(){
		Buffer::getInstance().draw(display, position);
	}

	virtual void update(){
		move();
	}

	void receiveDamage(int value) {
		if (value <= 0){
			changeHP(HP - value);
		}
	}

	virtual void die();

	void move(){
		while (!TryToMove(chooseDirection()));
	}

	int getHP() {
		return HP;
	}

	int getID() {
		return ID;
	}
	
	int getAttack() {
		return attack;
	};

	Vector2 getPosition();
};