// Made by Arnaud 

#include <fstream>
#include <string>
#include <vector>

#include "Parser.h"
#include "Vector2.h"
#include "../Entities/Monsters/Zombie.h"
#include "../Entities/Monsters/Headless.h"
#include "../Entities/Monsters/Swimmer_Zombie.h"
#include "../Game/Game.h"

vector<Tile_type> Parser::loadMap(string file_path, Vector2 Screen_Size){

    vector<Tile_type> map;

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

    return map;
}

// Biggest brain on earth
void Parser::loadEntity(Vector2 level_pos){
    ifstream inputFile("entity" + to_string(level_pos.x) + to_string(level_pos.y) + ".txt");

    string line;

    string type;

    while (getline(inputFile, line)) {

        type = Get_word(line, 1);

        if (type == "Headless"){
            Headless* headless = new Headless(2, 1, 'R');

            Vector2 newPos = 
            {stoi(Get_word(line, 2)),
            stoi(Get_word(line, 3))};

            headless -> setPos(newPos);

            Game::getInstance().getEntities().push_back(headless);
        }

        else if (type == "Zombie"){
            Zombie* zombie = new Zombie(1, 1, 'X');

            Vector2 newPos = 
            {stoi(Get_word(line, 2)),
            stoi(Get_word(line, 3))};

            zombie -> setPos(newPos);

            Game::getInstance().getEntities().push_back(zombie);
        }

        else if (type == "Swimmer"){
            SwimmerZombie* swimmer = new SwimmerZombie(1, 1, 'B');

            Vector2 newPos = 
            {stoi(Get_word(line, 2)),
            stoi(Get_word(line, 3))};

            swimmer -> setPos(newPos);

            Game::getInstance().getEntities().push_back(swimmer);
        }
    };

    inputFile.close();
};

// Simply genious
string Parser::Get_word(string phrase, int position){
    string word;

    int word_number = 1;

    for (int i = 0; i < size(phrase); i++){
        if (phrase[i] == ' '){
            if (position == word_number){
                return word;
            }
            else {
                word = "";
                word_number ++;
            }
        }
        else {
            word += phrase[i];
        }
    };
    
    return word;
}