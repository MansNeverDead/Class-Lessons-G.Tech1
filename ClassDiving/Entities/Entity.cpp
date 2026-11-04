#include <cstdlib>
#include <conio.h>
#include "../Map/Map.h"
#include "../States/State.h"
#include "Entity.h"
#include "Players/Player.h"
#include "Monsters/Zombie.h"

// ---------- Player ----------
void Player::update() {
    int dx = 0, dy = 0;
    switch (_getch()) {
        case 'z': position.x = -1; break;
        case 'q': position.y = -1; break;
        case 's': position.x = 1;  break;
        case 'd': position.y = 1;  break;
        case 'a': attacking(world); return;
        default: return;
    }
}

void Player::attacking(Entity& victim) {
    victim.receiveDamage(attack);
}

void Player::onDeath(World& world) {
    alive = false;
    world.playerDied = true;     // main decides what to do (death screen)
}

// ---------- Zombie ----------
void Zombie::update(World& world) {
    int stepX = (world.player.x > x) - (world.player.x < x);
    int stepY = (world.player.y > y) - (world.player.y < y);

    if (stepX != 0 && world.canWalk(x + stepX, y))      x += stepX;
    else if (stepY != 0 && world.canWalk(x, y + stepY)) y += stepY;
}

void Zombie::onDeath(World&) {
    alive = false;
}