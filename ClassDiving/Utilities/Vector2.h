#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <fstream>
#include <math.h> 
#include <vector>

using namespace std;

struct Vector2{
    int x;
    int y;

    void inverse(){
        x = 0 - x;
        y = 0 - y;
    }

};

bool operator==(const Vector2 vectorA, const Vector2 vectorB){
    return vectorA.x == vectorB.x && vectorA.y == vectorB.y;
}

bool operator!=(const Vector2 vectorA, const Vector2 vectorB){
    return !(vectorA.x == vectorB.x && vectorA.y == vectorB.y);
}

Vector2 operator+(const Vector2 vectorA, const Vector2 vectorB){
    Vector2 temp;
    temp.x = vectorA.x + vectorB.x; 
    temp.y = vectorA.y + vectorB.y;
    return temp;
}
