#pragma once

#include "../Utilities/Vector2.h"
#include "../Map/Map.h"
#include <vector>

using namespace std;

enum StateEnum {
    moving = 0,
    attacking = 1,
    attacked = 2,
    damaged = 3,
    dying = 4,
	swimming
};

class Entity {
protected:
	const int attack = 1;
	bool isAttacking = false;
	char display = ' ';
	Vector2 position;
	vector<Tile_type> walkableTile;
	StateEnum currentState;
	int HP = 0;
	const int ID = 0;

	void changePosition(Vector2 newPosition) {
		position = newPosition;
	}

	void changeState(StateEnum newState) {
		currentState = newState;
	}

	virtual Vector2 chooseDirection();

	virtual bool CheckTile(Vector2 pos);

	//This to check and hurt the enemy
    virtual void CheckCollisions();

	virtual bool TryToMove(Vector2 dir);

	void changeHP(int value);

public:

	virtual void runState() = 0;
	virtual void mouvement() = 0;
	virtual void transition(int newState) = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	

	void receiveDamage(int value) {
		HP -= value;
		if (HP <= 0) {
			transition(dying);
		} else {
			transition(moving);
    	};
	}

	virtual void die();

	virtual void move();

	int getHP() {
		return HP;
	}

	int getID() {
		return ID;
	}

	bool* getAttackingPtr() {
        return &isAttacking;
    };
	
	int getAttack() {
		return attack;
	};

	Vector2 getPosition();
};