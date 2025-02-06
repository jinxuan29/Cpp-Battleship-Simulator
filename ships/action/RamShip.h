#pragma once

#include "../shipType/include/Ship.h"
#include "../../game/include/Battlefield.h"

class RamShip: virtual public Ship{
    virtual void ramShip(Battlefield &battlefield) = 0; 
 public:
    
    virtual ~RamShip() = default;
};