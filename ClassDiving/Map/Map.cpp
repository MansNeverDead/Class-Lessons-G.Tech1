#include <cmath>
#include <fstream>

#include "Map.h"
#include "../Utilities/Buffer.h"

using namespace std;


Tile_type Map::get_tile(Vector2 pos){
    return map[coordinates_to_index(pos)];
}

int Map::coordinates_to_index(Vector2 coordinates){
    return coordinates.y * Screen_Size.x + coordinates.x;
}

void Map::Load_Map(string file_path){

    ifstream inputFile(file_path);

    string line;

    int y = 0;

    Tile_type tile;

    while (getline(inputFile, line) && y < Screen_Size.y) {
        for (int i = 0; i < Screen_Size.x; i++) {
            switch (line[i]) {
                case 'A':
                    tile = mountain;
                    break;
                case '~':
                    tile = water;
                    break;
                case 'R':
                    tile = rock;
                    break;
                default :
                    tile = ground;
                    break;
            }

            map[i + y * Screen_Size.x] = tile;
            
        }
        y += 1;
    }

    inputFile.close();
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