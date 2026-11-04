#pragma once

#include <cstdlib>

#include "../Entity.h"

class Monster: public Entity {
private:
    int id = rand();

public:
    Monster(int hp, int attackValue, char displayValue, StateEnum startingState);
};
