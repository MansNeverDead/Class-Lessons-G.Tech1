// Made by Arnaud 

#include <string>
#include <math.h>
#include <vector>

#include "Map.h"
#include "../Utilities/Buffer.h"
#include "../Utilities/Parser.h"

using namespace std;

Tile_type* Map::map = nullptr;
Vector2 Map::pixelSize{ 22, 22 };
Vector2 Map::screenSize{ 22, 22 };

// returns a type thanks to the tileType Enum them being the following..
//ground = 0, mountain = 1, water = 2, rock = 3
Tile_type Map::getTile(Vector2 pos){
    return map[coordinatesToIndex(pos)];
}

int Map::coordinatesToIndex(Vector2 coordinates){
    return coordinates.y * screenSize.x + coordinates.x;
}

void Map::loadMap(string file_path){
    vector<Tile_type> newMap = Parser::loadMap(file_path, screenSize);
    copy( newMap.begin(), newMap.end(), map); ;
}

void Map::drawMap(){
    Vector2 coordinates;
    char character;

    for (int i = 0; i < screenSize.x * screenSize.y; i++) {

        // Calculate coordinates
        coordinates.x = i % screenSize.x;
        coordinates.y = floor(i / screenSize.x);

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

Vector2 Map::getScreenSize(){
    return screenSize;
}

Vector2 Map::getPixelSize(){
    return pixelSize;
}

void Map::setScreenSize(Vector2 value){
    screenSize = value;
}

void Map::setPixelSize(Vector2 value){
    pixelSize = value;
}