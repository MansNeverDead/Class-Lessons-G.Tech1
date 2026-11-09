#pragma once

#include "Enemie.h"

class Zombie: public Enemie {
private:

    Vector2 chooseDirection() override;
};
