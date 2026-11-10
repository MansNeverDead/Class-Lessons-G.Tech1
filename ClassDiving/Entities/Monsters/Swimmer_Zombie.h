// Made by Arnaud 

#pragma once

#include "Zombie.h"
#include "../Swimmer.h"

class SwimmerZombie : public Zombie, public Swimmer {
public:
    /*SwimmerZombie(){
        walkableTile = get_walkable_tiles();
    }*/
    using Zombie::Zombie;
};
