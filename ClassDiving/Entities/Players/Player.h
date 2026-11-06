#include <conio.h>
#include "../Entity.h"
#include "../../Map/Map.h"


class Player: public Entity {
protected:
    bool isAttacking = false;
    int tempMap[22][22];


    virtual void attackingEnemies();

    char verifyInput() {
        char c = _getch();
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
            case 'a': isAttacking = true; return;
            default: return;
        }
        return direction;
    }

    void FSM() override {
        if (isAttacking) {
            attackingEnemies();
        }
        else {
            mouvement(chooseDirection());
        }
    }


public:
    // this is when you initialise them at the start
    Player(int hp, int attackValue, char displayValue, StateEnum startingState);

    void update() override {
        FSM();
    };
};
