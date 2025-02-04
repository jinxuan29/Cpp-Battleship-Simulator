#pragma once

#include "../shipType/include/Ship.h"
#include "../../game/include/Battlefield.h"

class SeeingShip: virtual public Ship{
    virtual void seeingShip(Battlefield &battlefield) = 0; 
};