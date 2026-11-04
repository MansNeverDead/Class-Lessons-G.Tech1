#include "../../States/State.h"
#include "../Entity.h"
#include "../../Map/Map.h"


class Player: public Entity {
private:
    bool isAttacking = false;
    int tempMap[22][22];

    bool canMove(Vector2 position, int map[22][22]) {
    if (map[position.x][position.y] == ground) {
        return true;
    } else {
        return false;
    }}

    char verifyInput() {
        char c = _getch();
        if (c == 'z' || c == 'q' || c == 's' || c == 'd' || c == 'a') {
            //return c;
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

    void mouvement() override {
        Vector2 tempMouvement = position + chooseDirection();

        if (canMove(tempMouvement, tempMap)) {
            position = tempMouvement;
        }
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
    // this is when you initialise them at the start
    Player(int hp, int attackValue, char displayValue, StateEnum startingState);

    void runState() override {
        mouvement();
    };

    void update() override {};

    void attacking(Entity& victim) {
        victim.receiveDamage(attack);
    };
};
