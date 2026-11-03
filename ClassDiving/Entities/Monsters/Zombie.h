#include "Entity.h"
#include "State.h"

class Zombie: public Entity {
private:

    
    void mouvement() override {

    };

public:
    virtual void runState() = 0;
	virtual void transition(State newState) = 0;
}
