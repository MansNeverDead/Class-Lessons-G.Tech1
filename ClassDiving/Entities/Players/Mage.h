#pragma once

#include "../Entity.h"
#include "Player.h"
#include "../../Game/Game.h"

using namespace std;

class Mage: public Player {
protected:
    void CheckCollisions() override;

    void mouvement();
    
    void FSM() override;

public:
    using Player::Player;

    void update() override;
};