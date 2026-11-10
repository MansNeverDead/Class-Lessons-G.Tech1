// Made by Arnaud 

#include <algorithm>
#include <cstdlib>
#include <math.h>

#include "Zombie.h"
#include "../../Game/Game.h"

using namespace std;

Vector2 Zombie::chooseDirection(){
    Vector2 dir;
    Vector2 distance;

    dir = position - Game::getInstance().getPlayers()[1]->getPosition();
    distance = {abs(dir.x), abs(dir.y)};
    dir = {clamp(dir.x, -1, 1), clamp(dir.y, -1, 1)};

    if (distance.x >= distance.y){
        dir.y = 0;
    } else {
        dir.x = 0;
    }

    return dir;
}

