#pragma once

#include "../Entity.h"

class Headless: public Entity {
private:

    Vector2 chooseDirection() override;
};
