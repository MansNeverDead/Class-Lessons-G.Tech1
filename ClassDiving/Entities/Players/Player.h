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

    // Doesn't need any Input, and returns the direction put in by the user.
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
            default:;
        }
        return direction;
    }

    // Here is where it'll check if the Player should recieve damage, move or other.
    virtual void FSM() = 0; 

    void die() override {
        system("cls");
        cout << "..   ..   .....   ..   ..      ......   .......  .......  ......" << endl;
        cout << "..   ..  ..   ..  ..   ..      ..   ..    ...    ..       ..   .." << endl;
        cout << " .. ..   ..   ..  ..   ..      ..   ..    ...    ..       ..   .." << endl;
        cout << "  ...    ..   ..  ..   ..      ..   ..    ...    ......   ..   .." << endl;
        cout << "  ...    ..   ..  ..   ..      ..   ..    ...    ..       ..   .." << endl;
        cout << "  ...    ..   ..  ..   ..      ..   ..    ...    ..       ..   .." << endl;
        cout << "  ...     .....    .....       ......   .......  .......  ......" << endl;
        exit(0);
    }

public:
    // this is when you initialise them at the start
    Player(int hp, int attackValue, char displayValue);
    
    void update() override {
        FSM();
    };
};
