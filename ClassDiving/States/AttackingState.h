#pragma once
#include "State.h"
#include "Entity.h"
#include "MovingState.h"

class AttackingState: public State {
private:
    void damageEntity(Entity& entity) {
        entity.changeHP(entity.getDamage());
    };

public:
    void update(Entity& entity) override {
        damageEntity(entity);
        transition(entity, MovingState())
    };

    void transition(Entity& entity) override {
        return;
    };
}