#pragma once

#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>
#include <string>
#include <fstream>
#include <math.h> 
#include <vector>

#include "../Utilities/Vector2.h"

using namespace std;

enum Tile_type {ground, mountain, water, rock};

class Map{
private:
    static Tile_type* map;

    static Vector2 Screen_Size;

    static Vector2 Pixel_Size;

public:
    Tile_type get_tile(Vector2 pos);

    int coordinates_to_index(Vector2 coordinates);

    void Load_Map(string file_path);

    void Draw_Map();
};

