// Made by Arnaud 

#include "Vector2.h"

bool operator==(const Vector2 vectorA, const Vector2 vectorB) {
    return vectorA.x == vectorB.x && vectorA.y == vectorB.y;
}

bool operator!=(const Vector2 vectorA, const Vector2 vectorB) {
    return !(vectorA.x == vectorB.x && vectorA.y == vectorB.y);
}

Vector2 operator+(Vector2 vectorA, const Vector2 vectorB) {
    Vector2 temp;
    temp.x = vectorA.x + vectorB.x; 
    temp.y = vectorA.y + vectorB.y;
    return temp;
}

Vector2 operator-(Vector2 vectorA, const Vector2 vectorB) {
    Vector2 temp;
    temp.x = vectorA.x - vectorB.x; 
    temp.y = vectorA.y - vectorB.y;
    return temp;
}

void Vector2::inverse() {
    x = 0 - x;
    y = 0 - y;
}