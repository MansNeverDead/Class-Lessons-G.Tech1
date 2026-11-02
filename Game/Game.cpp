#include "Game.h"

Game& Game::getInstance() {
    static Game obj;
    return obj;
}

void Game::change_map(Map new_map){
    Game::getInstance().map = new_map;
}
    
Map Game::get_map(){
    return Game::getInstance().map;
}