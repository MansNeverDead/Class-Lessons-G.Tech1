#include "../Entity.h"
#include "Player.h"
#include "../../Game/Game.h"

using namespace std;

class Mage: public Player {
protected:
    void CheckCollisions() override {
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

    void mouvement() {
        Vector2 tempMouvement = position + chooseDirection();
        Map* e = new Map();
        if (!tryToMove(chooseDirection())) {
            return;
        } else {
            position = tempMouvement;
        }
    }
    
    void FSM() override {
        if (isAttacking) {
            CheckCollisions();
        } else {
            mouvement();
        }
    }

public:
    using Player::Player;

    void update() override {
        FSM();
    }
};