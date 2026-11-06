#pragma once

#include "../Entity.h"
#include "../../Map/Map.h"


class Player: public Entity {
protected:
    bool isAttacking = false;
    int tempMap[22][22];


    virtual void attackingEnemies();

    char verifyInput() {
        char c = ' ';
        if (c == 'z' || c == 'q' || c == 's' || c == 'd' || c == 'a') {
            return c;
        }
        return ' ';
    }

    Vector2 chooseDirection() override {
        Vector2 direction;
        isAttacking = false;
        char input = verifyInput();
        switch (input) {
            case 'z': direction.x = -1; break;
            case 'q': direction.y = -1; break;
            case 's': direction.x = 1;  break;
            case 'd': direction.y = 1;  break;
            case 'a': isAttacking = true;
        }
        return direction;
    }
};
