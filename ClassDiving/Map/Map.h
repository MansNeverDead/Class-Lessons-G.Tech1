#pragma once

#include <string>

#include "../Utilities/Vector2.h"

using namespace std;

enum Tile_type {ground, mountain, water, rock};

class Map{
private:
    static Tile_type* map;

    static Vector2 Screen_Size;

    static Vector2 Pixel_Size;

public:
    Tile_type getTile(Vector2 pos);

    int coordinates_to_index(Vector2 coordinates);

    void Load_Map(string file_path);

    void Draw_Map();

    Vector2 get_Screen_Size();

    Vector2 get_Pixel_Size();

    void set_Screen_Size(Vector2);

    void set_Pixel_Size(Vector2);
};

