#pragma once

#include "../shipType/include/Ship.h"

class RamShip: virtual public Ship{
    virtual void ramShip() = 0; 
};