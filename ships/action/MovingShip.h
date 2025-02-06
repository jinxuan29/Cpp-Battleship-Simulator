#pragma once

#include "../shipType/include/Ship.h"
#include "../../game/include/Battlefield.h"

class MovingShip: virtual public Ship{
    virtual void movingShip(Battlefield &battlefield) = 0; 
    public:
    virtual ~MovingShip() = default;
};