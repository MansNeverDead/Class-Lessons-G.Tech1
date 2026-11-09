#pragma once

#include <iostream>
#include <vector>

#include "../Utilities/Vector2.h"
#include "../Entities/Entity.h"
#include "../Entities/Players/Player.h"
#include "../Map/Map.h"

using namespace std;

enum Game_State {playing, pause, game_over, quit};

// It is a singleton
// Use something like : Game::getInstance().get_map();
class Game{
private:
    Game() {}

    void Update();

    void Draw();

    void Init();

    void Menu(string big_display, string instruction);

    Map map;

    vector<Entity*> entityList;

    vector<Player*> players;

public:
    static Game& getInstance();

    Game_State game_state = playing;

    void Game_Loop();

    void change_map(Map new_map);
    
    Map get_map();
    
    vector<Entity*> getEntities();

    vector<Player*> get_players();
};