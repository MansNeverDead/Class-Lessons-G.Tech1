#include <cstdlib>
#include <math.h>

#include "Headless.h"

using namespace std;

Vector2 Headless::chooseDirection(){
    Vector2 dir;

    switch (rand() % 4) {
        case 0:
            dir.x++;
            break;
        case 1:
            dir.x--;
            break;
        case 2:
            dir.y++;
            break;
        case 3:
            dir.y--;
            break;
    }

    return dir;
}


