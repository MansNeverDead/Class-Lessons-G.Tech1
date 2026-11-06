#pragma once

#include <vector>

#include "../Map/Map.h"

class Swimmer{
public:
    vector<Tile_type> get_walkable_tiles();
};
