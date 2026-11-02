#include "Game.h"

Game& Game::getInstance() {
    static Game obj;
    return obj;
}

void Game::Game_Loop(){
    while (game_state != quit) {
        Update();
        Draw();
    }
}

void Game::Update(){

}

void Game::Draw(){

}

void Game::change_map(Map new_map){
    Game::getInstance().map = new_map;
}
    
Map Game::get_map(){
    return Game::getInstance().map;
}