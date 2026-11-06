#pragma once

#include <random>
#include "../Entity.h"

class Zombie: public Entity {
private:
    int ID = rand();
    
	void update() override {

    };

    Vector2 chooseDirection() override {

    };

public:
    int getID() {
        return ID;
    };

    Zombie() : Entity(0, 0, 'X', moving) {};
    Zombie(int hp, int attackValue, char displayValue, StateEnum startingState);
};
