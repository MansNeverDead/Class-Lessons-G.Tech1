#pragma once

#include <iostream>
#include <vector>

#include "../Utilities/Vector2.h"
#include "../Utilities/Buffer.h"
#include "../Entities/Entity.h"
#include "../Map/Map.h"

using namespace std;

enum Game_State {playing, pause, game_over, quit};

// It is a singleton
// Use something like : Game::getInstance().get_map();
class Game{
protected:

    void Update();

    void Draw();

    void Init();

    void Menu(string big_display, string instruction);

    Map map;

    vector<Entity*> entityList;

public:

    Game() {};
    static Game& getInstance();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    Game_State game_state = playing;

    void Game_Loop();

    void change_map(Map new_map);
    
    Map get_map();
    
    vector<Entity*> getEntities();

    //void remove_dead_entities();
};