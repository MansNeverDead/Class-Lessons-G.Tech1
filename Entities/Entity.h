#include "Vector2.h"
#include "State.h"

class Entity {
protected:
	int damage;
	string display;
	Vector2 position;
	State currentstate;
private:
	int HP;
public:
	virtual void runState() = 0;
};