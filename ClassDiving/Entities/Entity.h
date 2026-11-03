#include "../Utilities/Vector2.h"
#include "../States/State.h"

enum StateMachine {
    moving = 0,
    attacking = 1,
    attacked = 2,
    damaged = 3,
    dying = 4,
	swimming
};

class Entity {
protected:
	int damage;
	bool isAttacking;
	string display;
	Vector2 position;
	StateMachine currentState;
	int HP;
public:
	virtual void runState() = 0;
	virtual void mouvement() = 0;
	virtual void transition(State newState) = 0;

	int getHP() {
		return HP;
	}

	void changeHP(int value) {
		HP = value;
	}

	void changePosition(Vector2 newPosition) {
		position = newPosition;
	}

	void changeState(StateMachine newState) {
		currentState = newState;
	}

	bool* isAttackingPtr() {
        return &isAttacking;
    };
	
	int getDamage() {
		return damage;
	}

	void changeDamage(int value) {
		damage = value;
	}
};