#pragma once
#include "State.h"
#include "DamagedState.h"
#include "AttackingState.h"
#include "../Entities/Entity.h"
#include "Player.h"


class MovingState: public State {
private:

    

    void movingEntity(Entity& entity) {
        int x; int y; int tempMap[22][22];
        make_tuple(x, y) = playerInput(entity.isAttackingPtr());

        canMove(x, y, tempMap);

    }
    
public:
    void update(Entity& entity) override {
        movingEntity(entity);
    }

    void transition(Entity& entity) override {
        State* dmg = ;
        dmg->transition();

    }

};