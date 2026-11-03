#include <cstdlib>
#include <conio.h>
#include "../Map/Map.h"
#include "../States/State.h"
#include "Entity.h"
#include "Players/Player.h"
#include "Monsters/Zombie.h"

void Entity::receiveDamage(int amount, World& world) {
    HP -= amount;
    if (HP <= 0) {
        transition(dying);
        onDeath(world);       // virtual call: Player or Zombie version runs
    } else {
        transition(moving);
    }
}

// ---------- Player ----------
void Player::update(World& world) {
    int dx = 0, dy = 0;
    switch (_getch()) {
        case 'z': dx = -1; break;
        case 'q': dy = -1; break;
        case 's': dx = 1;  break;
        case 'd': dy = 1;  break;
        case 'a': attack(world); return;
        default: return;
    }
    if (world.isGround(x + dx, y + dy)) {   // player may step onto a zombie (= gets hit)
        x += dx;
        y += dy;
    }
}

void Player::attack(World& world) {
    transition(attacked);
    for (auto& z : world.zombies) {
        if (z.alive && std::abs(z.x - x) <= 1 && std::abs(z.y - y) <= 1)
            z.receiveDamage(damage, world);
    }
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