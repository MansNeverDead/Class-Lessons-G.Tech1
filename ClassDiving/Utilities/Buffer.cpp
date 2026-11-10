// Made by Arnaud 

#include "Buffer.h"
#include "../Game/Game.h"

Buffer& Buffer::getInstance(){
    static Buffer obj;
    return obj;
}

void Buffer::clear(){
    Buffer::getInstance().buffer.clear();
}
    
void Buffer::draw(char c, Vector2 coordinates){
    Buffer::getInstance().buffer[Game::getInstance().getMap().coordinatesToIndex(coordinates)] = c;
}

void Buffer::print(){
    vector<char>* vChar = &Buffer::getInstance().buffer;
    cout << string (vChar -> begin(), vChar -> end());
}