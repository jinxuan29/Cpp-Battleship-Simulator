#pragma once

#include "../shipType/include/Ship.h"

class MovingShip: virtual public Ship{
    virtual void movingShip() = 0; 
};