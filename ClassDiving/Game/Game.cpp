#include <string>
#include "Game.h"
#include "../Utilities/Buffer.h"

Game& Game::getInstance() {
    static Game obj;
    return obj;
}

void Game::Game_Loop(){
    Init();
    while (game_state != quit) {
        switch (game_state) {
            case playing:
                Update();
                Draw();
                break;
            case pause:
                Menu("PAUSE", "Press c to Continue /nPress q to Quit");
                break;
            case game_over:
                Menu("GAME OVER", "Press c to Restart /nPress q to Quit");
                Init();
                break;
            default:
                break;
        }
    }
}

void Game::Update(){
    for (int i = 0; i < entityList.size(); i++) {
        entityList[i] -> update();
    }
}

void Game::Draw(){
    map.drawMap();

    for (int i = 0; i < entityList.size(); i++) {
        entityList[i] -> draw();
    }

    Buffer::getInstance().print();
}

void Game::Menu(string big_display, string instruction){
    Buffer::getInstance().clear();
    cout << big_display;
    string input = "";
    while (true) {
        cin >> input;
        if (input == "c"){
            game_state = playing;
            return;
        }
        if (input == "q"){
            game_state = quit;
            return;
        }
    }
}

void Game::Init(){
    players[0] = new Warrior(1,1,'W');

    map = *new Map;

    map.loadMap("Level1");
}

void Game::change_map(Map new_map){
    Game::getInstance().map = new_map;
}
    
Map Game::get_map(){
    return Game::getInstance().map;
}
    
vector<Entity*> Game::getEntities(){
    return entityList;
}