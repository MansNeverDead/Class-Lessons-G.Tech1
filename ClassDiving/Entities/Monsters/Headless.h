#pragma once

#include "Enemie.h"

class Headless: public Enemie {
private:

    Vector2 chooseDirection() override;
};
