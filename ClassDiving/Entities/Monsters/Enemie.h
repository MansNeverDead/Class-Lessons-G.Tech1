#pragma once

#include "../Entity.h"

class Enemie: public Entity {
protected:

    void die() override;

    void CheckCollisions() override;
    
public:
    Enemie(int hp, int attackValue, char displayValue);
};
