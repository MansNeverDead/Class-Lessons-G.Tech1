#include <algorithm>
#include <vector>

#include "Enemie.h"
#include "../../Game/Game.h"

using namespace std;

void Enemie::die() {
    vector<Entity*> entitys = Game::getInstance().getEntities();
    entitys.erase(
    remove_if(entitys.begin(), entitys.end(), [&](Entity* const & monster) {
        return monster -> getID() == ID;
    }),
    entitys.end());
}

void Enemie::CheckCollisions(){
    vector<Player*> players = Game::getInstance().getPlayers();
    for (int i = 0; i < players.size(); i++){
        if (players[i] -> getPosition() == position){
            players[i] -> receiveDamage(attack);
            die();
        }
    }
}

Enemie::Enemie(int x, int y, char displayValue)
    : Entity(x, y, displayValue) {} 