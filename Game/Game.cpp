#include "Game.h"

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
                Menu("PAUSE", "Press c to Continue /nPress q to Quit");
                Init();
                break;
            default:
                break;
        }
    }
}

void Game::Update(){
    
}

void Game::Draw(){

}

void Game::Menu(string big_display, string instruction){

}

void Game::Init(){

}

void Game::change_map(Map new_map){
    Game::getInstance().map = new_map;
}
    
Map Game::get_map(){
    return Game::getInstance().map;
}