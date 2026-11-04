#pragma once

#include "../Entity.h"
#include "../../States/State.h"

class Zombie: public Entity {
private:

    
    void mouvement() override {

    };

public:
    Zombie(int hp, int attackValue, char displayValue, StateEnum startingState);
};
