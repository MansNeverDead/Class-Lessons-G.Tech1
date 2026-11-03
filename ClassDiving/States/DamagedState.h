#include "State.h"
#include "../Entities/Entity.h"

class DamagedState: public State {
protected:
    void recieveDamage(Entity* victim, int damage) {
        victim->HP = victim->HP - damage;
        if (victim->HP <= 0) {
            transition(victim, dying);
            runCurrentState(victim);
        }
        else {
            transition(victim, moving);
            runCurrentState(victim);
        }
    };

    void checkHP(Entity* victim) {
        if (victim->HP <= 0) {
            transition(victim, dying);
        }
    } 

public:
    void update() override {
        
    }

    void transition() override {
        cout << "ew";
    }
}