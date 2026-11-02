#pragma once

#include <iostream>
#include <vector>

#include "../Utilities/Vector2.h"
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

    Map map;

public:
    static Game& getInstance();

    Game_State game_state = playing;

    void Game_Loop();

    void change_map(Map new_map);
    
    Map get_map();
};