#include "Entity.h"

class Swimmer: public Entity {
    virtual void runState() = 0;
	virtual void mouvement() = 0;
	virtual void transition(int newState) = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
}