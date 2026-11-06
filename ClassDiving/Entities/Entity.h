#pragma once
#include <vector>
#include <random>
#include "../Utilities/Vector2.h"
#include "../Utilities/Buffer.h"
#include "../Map/Map.h"
#include "../Game/Game.h"



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

	const int attack;
	bool isAttacking = false;
	char display;
	Vector2 position;
	vector<Tile_type> walkableTile;
	StateEnum currentState;
	int HP;
	int ID = rand();

	void changePosition(Vector2 newPosition) {
		position = newPosition;
	}

	void changeState(StateEnum newState) {
		currentState = newState;
	}

	bool checkTile(Vector2 pos); // is in Entity.cpp

	bool TryToMove(Vector2 dir);

	virtual Vector2 chooseDirection() = 0;

    virtual bool checkCollisions();

	virtual void FSM() = 0;

public:

	void mouvement(Vector2 tempMouvement) {
		tempMouvement = position + chooseDirection();
        if (!checkTile(tempMouvement)) {
            return;
        }
        changePosition(tempMouvement);
	};

	void draw() {
        //Buffer::getInstance().draw(display, position);
    };

	virtual void update() = 0;
	
	void receiveDamage(int value); // Is defined in Entity.cpp

	void die();

	void move();

	int getHP() {
		return HP;
	}

	Vector2 getPosition() {
		return position;
	};

	Entity(int hp, int damage, char displayValue, StateEnum startingState) : HP(hp), attack(damage), display(displayValue), currentState(startingState) {};
	~Entity() = default;
};
