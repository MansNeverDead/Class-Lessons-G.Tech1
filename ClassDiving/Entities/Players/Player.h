//Made by Akiliano

#pragma once
#include <conio.h>
#include "../Entity.h"
#include "../../Map/Map.h"


class Player: public Entity {
protected:
    bool isAttacking = false;
    int tempMap[22][22];

    char verifyInput();

    // Doesn't need any Input, and returns the direction put in by the user.
    Vector2 chooseDirection() override;

    // Here is where it'll check if the Player should recieve damage, move or other.
    virtual void FSM() = 0; 

    void die() override;

public:
    // this is when you initialise them at the start
    Player(int hp, int attackValue, char displayValue);
    
    virtual void update() override;
};
