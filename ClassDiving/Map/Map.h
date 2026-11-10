// Made by Arnaud 

#pragma once

#include <string>

#include "../Utilities/Vector2.h"

using namespace std;

enum Tile_type {ground, mountain, water, rock};

class Map{
private:
    static Tile_type* map;

    static Vector2 screenSize;

    static Vector2 pixelSize;

public:
    Tile_type getTile(Vector2 pos);

    int coordinatesToIndex(Vector2 coordinates);

    void loadMap(string file_path);

    void drawMap();

    Vector2 getScreenSize();

    Vector2 getPixelSize();

    void setScreenSize(Vector2);

    void setPixelSize(Vector2);
};

