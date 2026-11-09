#pragma once

#include <string>

#include "../Utilities/Vector2.h"
#include "../Entities/Entity.h"

using namespace std;

class Parser{
private:
    static string Get_word(string phrase, int position);

public:
    static vector<Entity*> loadEntity(Vector2 level_pos);

    static vector<Tile_type> loadMap(string file_path, Vector2 Screen_Size);
};

