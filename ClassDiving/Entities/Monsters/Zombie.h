#pragma once

#include "../Entity.h"

class Zombie: public Entity {
private:

    Vector2 chooseDirection() override;
};
