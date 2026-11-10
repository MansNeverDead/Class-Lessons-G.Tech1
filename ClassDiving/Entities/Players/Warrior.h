#pragma once
#include "../Entity.h"
#include "Player.h"
#include "../../Game/Game.h"
#include "../Monsters/Zombie.h"


using namespace std;

class Warrior: public Player {
protected:
    void CheckCollisions() override;
    
    void mouvement();

    void FSM() override;

public:
    using Player::Player;

    void update() override;

};