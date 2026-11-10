#include "Mage.h"

using namespace std;

void Mage::CheckCollisions() {
    Vector2 area[8] = {
        {position.x-1, position.y-1}, {position.x, position.y-1}, {position.x+1, position.y -1},
        {position.x-1, position.y}, {position.x+1, position.y},
        {position.x-1, position.y+1}, {position.x, position.y+1}, {position.x+1, position.y+1}
        };
    for (int i = 0; i < Game::getInstance().getEntities().size(); i++) {
        Entity* monster = Game::getInstance().getEntities()[i];
        for (int i = 0; i < 8; i++) {
            if (area[i] == monster->getPosition()) {
                monster->receiveDamage(attack);
            }
        }
    }
};

void Mage::mouvement() {
    Vector2 tempMouvement = position + chooseDirection();
    Map* e = new Map();
    if (!tryToMove(chooseDirection())) {
        return;
    } else {
        position = tempMouvement;
    }
}

void Mage::FSM() {
    if (isAttacking) {
        CheckCollisions();
    } else {
        mouvement();
    }
}

void Mage::update() {
    FSM();
}
