#include "../Utilities/Vector2.h"
#include "../States/State.h"
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
	const int attack;
	bool isAttacking = false;
	char display;
	Vector2 position;
	vector<Tile_type> walkableTile;
	StateEnum currentState;
	int HP;

	void changePosition(Vector2 newPosition) {
		position = newPosition;
	}

	void changeState(StateEnum newState) {
		currentState = newState;
	}

	virtual Vector2 chooseDirection() = 0;

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

	int getHP() {
		return HP;
	}

	bool* getAttackingPtr() {
        return &isAttacking;
    };
	
	int getDamage() {
		return attack;
	};

	Entity(int hp, int damage, char displayValue, StateEnum startingState) : HP(hp), attack(damage), display(displayValue), currentState(startingState) {};
	~Entity() = default;
};