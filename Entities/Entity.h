#include <iostream>

#include "../Utilities/Vector2.h"

using namespace std;

class Entity {
protected:
	int damage;
	string display;
	Vector2 position;
private:
	int HP;
public:
	virtual void runState() = 0;
	
    void Update();

    void Draw();
};