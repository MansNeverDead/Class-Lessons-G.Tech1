//Made by Akiliano

#include "Warrior.h"


using namespace std;

void Warrior::CheckCollisions() {
    for (int i = 0; i < Game::getInstance().getEntities().size(); i++) {
        Entity* monster = Game::getInstance().getEntities()[i];
        if (position == monster->getPosition()) {
            monster->receiveDamage(attack);
        }
    }
};

void Warrior::mouvement() {
    Vector2 tempMouvement = position + chooseDirection();
    Map* e = new Map();
    if (!tryToMove(chooseDirection())) {
        return;
    } else {
        position = tempMouvement;
    }
}

void Warrior::FSM() {
    mouvement();
    CheckCollisions();
}

void Warrior::update() {
    FSM();
}

