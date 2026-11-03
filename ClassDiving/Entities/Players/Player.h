#include "State.h"
#include "Entity.h"

class Player: public Entity {
private:
    bool isAttacking = false;
    int tempMap[22][22];

    bool canMove(Vector2 position, int map[22][22]) {
    if (map[position.x][position.y] == basicGround) {
        return true;
    } else {
        return false;
    }}

    char verifyInput() {
        char c = _getch();
        if (c == 'z' || c == 'q' || c == 's' || c == 'd' || c == 'a') {
            return c;
        }
        return NULL;
    }

    Vector2 playerInput(bool* isAttacking) {
        Vector2 direction;
        char input = verifyInput();
        if (input == 'z') {
            direction.x = -1;
            *isAttacking = false;
            return direction;
        }
        else if (input == 'q') {
            direction.y = -1;
            *isAttacking = false;
            return direction;
        }
        else if (input == 's') {
            direction.x = 1;
            *isAttacking = false;
            return direction;
        }
        else if (input == 'd') {
            direction.y = 1;
            *isAttacking = false;
            return direction;
        }
        else if (input == 'a') {
            *isAttacking = true;
        }
        return direction;
    }

    void mouvement() override {
        Vector2 tempMouvement = position + playerInput(&isAttacking);

        if (canMove(tempMouvement, tempMap)) {
            position = tempMouvement;
        }
    };

    void attacking(Entity& victim) {
        victim.changeHP(damage);
    };

    void runTime(Entity& victim) {
        if (!isAttacking) {
            mouvement();
        } 
        else { 
            attacking(victim);
        };
    }

public:
    void runState() override {
        mouvement();
    };

};
