#pragma once

#include <vector>
#include "../Utilities/Vector2.h"
#include "../Map/Map.h"

using namespace std;

class Entity {
protected:
	const int attack = 1;

	char display = ' ';

	Vector2 position;

	vector<Tile_type> walkableTile;

	int HP = 0;

	const int ID = rand();

	void changePosition(Vector2 newPosition);

	virtual Vector2 chooseDirection() = 0;

	bool CheckTile(Vector2 pos);

    virtual void CheckCollisions();

	bool tryToMove(Vector2 dir);

	void changeHP(int value);

	Entity(int hp, int attackValue, char displayValue);
public:
	void draw();

	virtual void update();

	void receiveDamage(int value);

	virtual void die();

	void move();

	int getHP();

	int getID();
	
	int getAttack();
	
	Vector2 getPosition();
	
	void setPos(Vector2 value);
};