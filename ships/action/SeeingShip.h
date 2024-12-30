#pragma once

#include "../shipType/include/Ship.h"

class SeeingShip: virtual public Ship{
    virtual void seeingShip() = 0; 
};