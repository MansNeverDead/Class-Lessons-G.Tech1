#include "Vector2.h"

bool operator==(const Vector2 vectorA, const Vector2 vectorB){
    return vectorA.x == vectorB.x and vectorA.y == vectorB.y;
}

bool operator!=(const Vector2 vectorA, const Vector2 vectorB){
    return not (vectorA.x == vectorB.x and vectorA.y == vectorB.y);
}

Vector2 operator+(Vector2 vectorA, const Vector2 vectorB){
    Vector2 temp;
    temp.x = vectorA.x + vectorB.x; 
    temp.y = vectorA.y + vectorB.y;
    return temp;
}