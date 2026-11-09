#include <string>
#include <math.h>
#include <vector>

#include "Map.h"
#include "../Utilities/Buffer.h"
#include "../Utilities/Parser.h"

using namespace std;

Tile_type* Map::map = nullptr;
Vector2 Map::Screen_Size{ 22, 22 };

Tile_type Map::get_tile(Vector2 pos){
    return map[coordinates_to_index(pos)];
}

int Map::coordinates_to_index(Vector2 coordinates){
    return coordinates.y * Screen_Size.x + coordinates.x;
}

void Map::Load_Map(string file_path){
    vector<Tile_type> newMap = Parser::Load_Map(file_path, Screen_Size);
    copy( newMap.begin(), newMap.end(), map); ;
}

void Map::Draw_Map(){
    Vector2 coordinates;
    char character;

    for (int i = 0; i < Screen_Size.x * Screen_Size.y; i++) {

        // Calculate coordinates
        coordinates.x = i % Screen_Size.x;
        coordinates.y = floor(i / Screen_Size.x);

        // Calculate What to draw
        switch (map[i]){
            case ground:
                character = '.';
                break;
            case mountain:
                character = 'A';
                break;
            case water:
                character = '~';
                break;
            case rock:
                character = 'R';
                break;
        }

        Buffer::getInstance().draw(character, coordinates);
    }
}

Vector2 Map::get_Screen_Size(){
    return Screen_Size;
}

Vector2 Map::get_Pixel_Size(){
    return Pixel_Size;
}

void Map::set_Screen_Size(Vector2 value){
    Screen_Size = value;
}

void Map::set_Pixel_Size(Vector2 value){
    Pixel_Size = value;
}