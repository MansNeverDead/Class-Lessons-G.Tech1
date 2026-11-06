#include "Entity.h"
#include "Player.h"
#include "Game.h"
#include "Zombie.h"


using namespace std;

class Warrior: public Player {
protected:
    void attackingEnemies() override {
        for (int i = 0; i < Game::getInstance().getEntities().size(); i++) {
            Entity* monster = Game::getInstance().getEntities()[i];
            if (position == monster->getPosition()) {
                monster->receiveDamage(attack);
            }
        }
    };



public:
    using Player::Player;

    void update() {
        attackingEnemies();
    }

};