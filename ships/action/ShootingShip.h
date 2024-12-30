#pragma once

#include "../shipType/include/Ship.h"

class ShootingShip: virtual public Ship{
    virtual void shootingShip() = 0; 
};