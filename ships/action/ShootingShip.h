#pragma once

#include "../shipType/include/Ship.h"
#include "../../game/include/Battlefield.h"

class ShootingShip: virtual public Ship{
    virtual void shootingShip(Battlefield &battlefield) = 0; 
};