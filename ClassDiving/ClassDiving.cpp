// Console Adventure.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream> // Basics
#include <conio.h> // used to use _getch 
#include <tuple>
#include <fstream> // To open files
#include <string> // To make getline() to work

using namespace std;

int map[22][22];

enum StateMachine {
    moving = 0,
    attacking = 1,
    attacked = 2,
    damaged = 3,
    dying = 4,
};

struct Entity {
    int x;
    int y;
    char display = '0';
    int HP;
    int damage;
    bool alive = true;
    int currentstate = moving;
};

struct FSM {
    void (*test)(int, int);
};


Entity user{ 0, 0, 'H', 1, 1 }; Entity* userPtr = &user;

Entity enemyArray[7]{
    {0, 0, 'X', 1, 1 },
    {0, 0, 'X', 1, 1 },
    {0, 0, 'X', 1, 1 },
    {0, 0, 'X', 1, 1 },
    {0, 0, 'X', 1, 1 },
    {0, 0, 'X', 1, 1 },
    {0, 0, 'X', 1, 1 } };

int addX = 0; int addY = 0;
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

char translator(int num) {
    if (num == basicGround) {
        return '.';
    }
    else if (num == mountain) {
        return 'A';
    }
    else if (num == river) {
        return '~';
    }
    else if (num == sortie) {
        return 'E';
    }
    else {
        return '.';
    }
}

int loopThroughEnemies(Entity oppsArray[7], int x, int y) {
    for (int i = 0; i < 7; i++) {
        if (x == oppsArray[i].x && y == oppsArray[i].y && oppsArray[i].alive) {
            return i;
        }
    }
    return -1;
}

void visualiseMap(int lengthX, int heightY, int map[22][22], Entity user, Entity oppsArray[7]) {
    system("cls");
    cout << "Use Z/Q/S/D to move!" << endl;
    for (int x = 0; x < lengthX; x++) {
        for (int y = 0; y < heightY; y++) {
            int enemyIndex = loopThroughEnemies(oppsArray, x, y);
            if (user.currentstate == attacked && x <= user.x + 1 && x >= user.x - 1 && y <= user.y + 1 && y >= user.y - 1 && !(x == user.x && y == user.y)) {
                if (map[x][y] == 0) {
                    cout << '*' << ' ';
                }
                else {
                    cout << translator(map[x][y]) << ' ';
                }
            }
            else if (enemyIndex != -1) {
                cout << oppsArray[enemyIndex].display << ' ';
            }
            else if (x == user.x && y == user.y) {
                cout << user.display << ' ';
            }
            else {
                cout << translator(map[x][y]) << ' ';
            }
        }
        cout << endl;
    }
}

void reviveEnemies(Entity array[7]) {
    for (int i = 0; i < 7; i++) {
        array[i].alive = true;
    }
}

void getMap(string levelName, int grid[22][22], Entity* player, Entity* enemies) {
    string path = levelName + ".txt";
    ifstream file(path);
    if (!file) {
        cerr << "Cannot open file\n";
        return;
    }

    string line;

    int enemiesIndex = 0;

    for (int x = 0; x < 22 && getline(file, line); x++) {
        for (int y = 0; y < 22 && y < (int)line.size(); y++) {
            grid[x][y] = line[y] - '0';
            if (line[y] == '4') {
                player->x = x; player->y = y;
            }
            if (line[y] == '5') {
                enemies[enemiesIndex].x = x; enemies[enemiesIndex].y = y;
                enemiesIndex++;
            }
        }
    }
    reviveEnemies(enemyArray);
}

bool canMove(int x, int y, const int map[22][22]) {
    if (map[x][y] == basicGround) {
        return true;
    } else {
        return false;
    }
}
void deathScreen() {
    system("cls");
    cout << "..   ..   .....   ..   ..      ......   .......  .......  ......" << endl;
    cout << "..   ..  ..   ..  ..   ..      ..   ..    ...    ..       ..   .." << endl;
    cout << " .. ..   ..   ..  ..   ..      ..   ..    ...    ..       ..   .." << endl;
    cout << "  ...    ..   ..  ..   ..      ..   ..    ...    ......   ..   .." << endl;
    cout << "  ...    ..   ..  ..   ..      ..   ..    ...    ..       ..   .." << endl;
    cout << "  ...    ..   ..  ..   ..      ..   ..    ...    ..       ..   .." << endl;
    cout << "  ...     .....    .....       ......   .......  .......  ......" << endl;
    cout << "Do you want to try again?\n y = oui\n n= Non" << endl;
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        getMap("Level1", map, userPtr, enemyArray);
        level = 0;
    }
    else if (choice == 'n' || choice == 'N') {
        exit(0);
    }
    else { 
        cout << "t'as eu une crise cardiaque ou tu n'sais pas lire?" << endl;
        exit(0);
    }

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

void beatLevel(int x, int y, int map[22][22], int* level, Entity* userPtr, Entity* enemyArray) {
    if (map[x][y] == 3 && *level == 1) {
        reviveEnemies(enemyArray);
        getMap("Level2", map, userPtr, enemyArray);
        *level = 2;
    }
    else if (map[x][y] == 3 && *level == 2) {
        reviveEnemies(enemyArray);
        getMap("Level3", map, userPtr, enemyArray);
        *level = 3;
    }
    else if (map[x][y] == 3 && *level == 3) {
        system("cls");
        cout << "You won...\nYou beat every level..\nYou outbested my every attempt at making you lose...\nYou beated the odds and won.\nSo cheer, celebrate like no tomorrow, for the Winner takes it ALL.";
        abort();
    }

    return;
}

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

bool canWalk(int x, int y) {
    if (x < 0 || x >= 22 || y < 0 || y >= 22) return false;  
    if (map[x][y] != basicGround) return false;            

    for (int i = 0; i < 7; i++) {                            
        if (enemyArray[i].x == x && enemyArray[i].y == y) return false;
    }
    return true;
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


int verifyInput() {
    char c = _getch();
    if (c == 'z' || c == 'q' || c == 's' || c == 'd' || c == 'a') {
        return c;
    }
    return NULL;
}

tuple <int, int> playerInput(bool* isAttacking) {
    int x = 0; int y = 0;
    char input = verifyInput();
    if (input == 'z') {
        x = x - 1;
        return make_tuple(x, y);
    }
    else if (input == 'q') {
        y = y - 1;
        return make_tuple(x, y);
    }
    else if (input == 's') {
        x = x + 1;
        return make_tuple(x, y);
    }
    else if (input == 'd') {
        y = y + 1;
        return make_tuple(x, y);
    }
    else if (input == 'a') {
        transition(userPtr, attacked);
        runCurrentState(userPtr);
    }
    return make_tuple(NULL, NULL);
}

void recieveDamage(Entity* victim, int damage) {
    victim->HP = victim->HP - damage;
    if (victim->HP <= 0) {
        transition(victim, dying);
        runCurrentState(victim);
    }
    else {
        transition(victim, moving);
        runCurrentState(victim);
    }
};

void dyingFunc(Entity* entity, Entity* user) {
    if (entity == user) {
        entity->alive = false;
        deathScreen();
    }
    else {
        entity->alive = false; 
    }
}

void movingEntity(Entity* entity, Entity* player) {
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

void runCurrentState(Entity* entity) {
    if (entity->currentstate == moving && userPtr->currentstate != attacked) {
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

    getMap("Level1", map, userPtr, enemyArray);
    //makeMap(22, 22, map);
    visualiseMap(22, 22, map, user, enemyArray);

    int atLevel = 1;
    while (true) {
        transition(userPtr, moving);

        runCurrentState(userPtr);
        runCurrentState(enemyArray);

        beatLevel(userPtr->x, userPtr->y, map, &atLevel, userPtr, enemyArray);


        if (touchingEnemy(user, enemyArray)) {
            transition(userPtr, damaged);
            runCurrentState(userPtr);
        }


        visualiseMap(22, 22, map, user, enemyArray);

    }
    
}

