#include "Entity.h"
#include "Player.h"
#include "Mage.h"
#include "Warrior.h"
#include "Game.h"

class Paladin: public Mage, public Warrior {
public:
    Paladin(int hp, int attackValue, char displayValue, StateEnum startingState);    
};