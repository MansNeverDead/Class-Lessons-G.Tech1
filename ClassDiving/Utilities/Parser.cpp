#include <fstream>
#include <string>
#include <vector>

#include "Parser.h"
#include "Vector2.h"

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
vector<Entity*> Parser::Load_Entity(Vector2 level_pos){
    ifstream inputFile("entity" + to_string(level_pos.x) + to_string(level_pos.y) + ".txt");

    string line;

    string type;

    while (getline(inputFile, line)) {

        type = Get_word(line, 1);

        if (type == "Door"){
            Door* door = new Door;

            door -> init(
                Vector2{stoi(Get_word(line, 2)), stoi(Get_word(line, 3))},
                black_hole,
                'D', 
                Vector2{0, 0}, 
                {},
                1
            );

            door -> level_pos.x = stoi(Get_word(line, 4));
            door -> level_pos.y = stoi(Get_word(line, 5));

            door -> player_pos.x = stoi(Get_word(line, 6));
            door -> player_pos.y = stoi(Get_word(line, 7));

            entitys.push_back(door);
        }

        else if (type == "Zombie"){
            Zombie* zombie = new Zombie;

            zombie -> init(
                Vector2{stoi(Get_word(line, 2)), stoi(Get_word(line, 3))},
                week_bokoblin,
                'B', 
                Vector2{0, 0}, 
                {ground},
                2
            );

            entitys.push_back(zombie);
        }

        else if (type == "Octo"){
            Octo* octo = new Octo;

            octo -> init(
                Vector2{stoi(Get_word(line, 2)), stoi(Get_word(line, 3))},
                bright_octorock,
                'O', 
                Vector2{stoi(Get_word(line, 4)), stoi(Get_word(line, 5))}, 
                {ground},
                2
            );

            octo -> last_dir.inverse();

            entitys.push_back(octo);
        }

        else if (type == "Zora"){
            Zora* zora = new Zora;

            zora -> init(
                Vector2{stoi(Get_word(line, 2)), stoi(Get_word(line, 3))},
                scary_blood,
                'Z', 
                Vector2{stoi(Get_word(line, 4)), stoi(Get_word(line, 5))}, 
                {water},
                2
            );

            zora -> last_dir.inverse();

            entitys.push_back(zora);
        }

        else if (type == "Sword"){
            Sword* sword = new Sword;

            sword -> init(
                Vector2{stoi(Get_word(line, 2)), stoi(Get_word(line, 3))},
                yellow_bonus,
                'S', 
                Vector2{0, 0}, 
                {},
                1
            );

            entitys.push_back(sword);
        }

        else if (type == "Bow"){
            Bow* bow = new Bow;

            bow -> init(
                Vector2{stoi(Get_word(line, 2)), stoi(Get_word(line, 3))},
                yellow_bonus,
                'B', 
                Vector2{0, 0}, 
                {},
                1
            );

            entitys.push_back(bow);
        }

        else if (type == "Mage"){
            Mage* mage = new Mage;

            mage -> init(
                Vector2{stoi(Get_word(line, 2)), stoi(Get_word(line, 3))},
                magical_purple,
                'M', 
                Vector2{0, 0}, 
                {},
                1
            );

            entitys.push_back(mage);
        }
        // I love this function, but still seem not optimised for the 130 lines it need... 
    }

    inputFile.close();
}

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
    }
    
    return word;
}