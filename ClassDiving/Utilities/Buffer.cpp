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
    Buffer::getInstance().buffer[Game::getInstance().get_map().coordinates_to_index(coordinates)] = c;
}