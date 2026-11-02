#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>
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
