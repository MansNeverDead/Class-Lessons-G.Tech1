// Console Adventure.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream> // Basics
#include <conio.h> // used to use _getch 
#include <tuple>
#include <fstream> // To open files
#include <string> // To make getline() to work

#include "States/State.h"
#include "States/MovingState.h"


using namespace std;

int map[22][22];





struct FSM {
    void (*test)(int, int);
};




bool isAttacking = false; bool* isAttackingPtr= &isAttacking;

void transition(Entity* entity, int futureState) {

    if (!(futureState < 5 || futureState > 0)) {
        cout << "the function that called this has a number that is out of bounds";
        abort();
        return;
    }
    entity->currentstate = futureState;
}

//Here we declare the functions, however because they are stored inside of backgroundFunctions they won't see it
//Hence we declare them here so the function can still be used while the code will be run inside of backgroundFunctions.

int level = 0;

enum ground {
    basicGround = 0,
    mountain = 1,
    river = 2,
    sortie = 3
};

int loopThroughEnemies(Entity oppsArray[7], int x, int y) {
    for (int i = 0; i < 7; i++) {
        if (x == oppsArray[i].x && y == oppsArray[i].y && oppsArray[i].alive) {
            return i;
        }
    }
    return -1;
}


bool touchingEnemy(Entity user, Entity array[7]) {
    for (int i = 0; i < 7; i++) {
        Entity opp = array[i];
        if (user.x == opp.x && user.y == opp.y && opp.alive) {
            return true;
        }
    }
    return false;
}

void runCurrentState(Entity* entity);

void spellHitEnemy(Entity enemyArray[7], Entity player) {
    int x = player.x - 1; int y = player.y - 1;
    for (int index = 0; index < 7; index++) {

        if (enemyArray[index].x <= player.x + 1 && enemyArray[index].x >= player.x - 1 && enemyArray[index].y <= player.y + 1 && enemyArray[index].y >= player.y - 1) {
            Entity* enemyPtr = &enemyArray[index];
            transition(enemyPtr, damaged);
            runCurrentState(enemyPtr);
        }
    }
}

void enemiesMoving(Entity* enemy, Entity player, Entity enemyArray[7]) {
    int stepX = 0;
    int stepY = 0;

    if (player.x < enemy->x) stepX = -1;
    else if (player.x > enemy->x) stepX = 1;

    if (player.y < enemy->y) stepY = -1;
    else if (player.y > enemy->y) stepY = 1;

    // 2. Try to move on X first, otherwise try Y
    if (stepX != 0 && canWalk(enemy->x + stepX, enemy->y)) {
        enemy->x += stepX;
    }
    else if (stepY != 0 && canWalk(enemy->x, enemy->y + stepY)) {
        enemy->y += stepY;
    }
}

void movingEntity(Entity* entity, Entity* player) {
        int addX = 0; int addY = 0;
        int tempMouvX; int tempMouvY;

        if (entity == player) {
            tie(addX, addY) = playerInput(isAttackingPtr);
            tempMouvX = player->x + addX;
            tempMouvY = player->y + addY;
            if (canMove(tempMouvX, tempMouvY, map)) {
                player->x = tempMouvX; player->y = tempMouvY;
            }
        }
        else {
            for (int i = 0; i < 7; i++) {
                enemiesMoving(&enemyArray[i], user, enemyArray);
            }
        }
    }




void dyingFunc(Entity* entity, Entity* user) {
    if (entity == user) {
        entity->alive = false;
        deathScreen();
    }
    else {
        entity->alive = false; 
    }
}

void runCurrentState(Entity* entity) {
    if (entity->currentstate == moving && userPtr->currentstate != attacked) {
        MovingState* moving = new MovingState();

        movingEntity(entity, userPtr);
    }
    else if (entity->currentstate == attacked) {
        spellHitEnemy(enemyArray, user);
    }
    else if (entity->currentstate == damaged) {
        recieveDamage(entity, 1);
    }
    else if (entity->currentstate == dying) {
        dyingFunc(entity, userPtr);
    }
}


int main() {

    int atLevel = 1;
    while (true) {
        transition(userPtr, moving);

        runCurrentState(userPtr);
        runCurrentState(enemyArray);



        if (touchingEnemy(user, enemyArray)) {
            transition(userPtr, damaged);
            runCurrentState(userPtr);
        }



    }
    
}

