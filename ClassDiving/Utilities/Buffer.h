#pragma once

#include <vector>

#include "Vector2.h"

using namespace std;

// It is a singleton
// Use something like : Buffer::getInstance().clear();
class Buffer{
private:
    Buffer() {}

    vector<char> buffer = {};

    static Vector2 Offset;

public:
    static Buffer& getInstance();

    void clear();
    
    void draw(char c, Vector2 coordinates);

    void print();
};