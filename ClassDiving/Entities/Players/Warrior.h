#pragma once

#include "../Entity.h"
#include "Player.h"
#include "Game.h"
#include "Zombie.h"


using namespace std;

class Warrior: public Player {
protected:
    void CheckCollisions() override {
        for (int i = 0; i < Game::getInstance().getEntities().size(); i++) {
            Entity* monster = Game::getInstance().getEntities()[i];
            if (position == monster->getPosition()) {
                monster->receiveDamage(attack);
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
        mouvement();
        CheckCollisions();
    }

public:
    using Player::Player;

    void update() {
        FSM();
    }

};