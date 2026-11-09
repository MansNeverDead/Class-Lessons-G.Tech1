#include <conio.h>
#include <iostream>
#include "Player.h"
#include "../Entity.h"
#include "../../Map/Map.h"

using namespace std;

char Player::verifyInput() {
    char c = _getch();
    if (c == 'z' || c == 'q' || c == 's' || c == 'd' || c == 'a') {
        return c;
    }
    return ' ';
};

// Doesn't need any Input, and returns the direction put in by the user.
Vector2 Player::chooseDirection() {
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
};


void Player::die() {
    system("cls");
    cout << "..   ..   .....   ..   ..      ......   .......  .......  ......" << endl;
    cout << "..   ..  ..   ..  ..   ..      ..   ..    ...    ..       ..   .." << endl;
    cout << " .. ..   ..   ..  ..   ..      ..   ..    ...    ..       ..   .." << endl;
    cout << "  ...    ..   ..  ..   ..      ..   ..    ...    ......   ..   .." << endl;
    cout << "  ...    ..   ..  ..   ..      ..   ..    ...    ..       ..   .." << endl;
    cout << "  ...    ..   ..  ..   ..      ..   ..    ...    ..       ..   .." << endl;
    cout << "  ...     .....    .....       ......   .......  .......  ......" << endl;
    exit(0);
};


void Player::update() {
    FSM();
};

Player::Player(int x, int y, char displayValue) : Entity(x, y, displayValue) {}