#pragma once

#include "../../action/RamShip.h"
#include "../../action/ShootingShip.h"

class Frigate : public RamShip, public ShootingShip {
    Frigate();

//  Frigate(std::string shipName, int xPosition, int yPosition, int lives,
//          int reviveCount);

  Frigate(const Position &position, int lives, int reviveCount,
       int shipDestroyedCount, const std::string &shipName,
       const std::string &shipType, const std::string &teamName,
       bool isDestroyed);

  ~Frigate();

  Frigate(const Frigate &other);

  Frigate &operator=(const Frigate &other);

  void shootingShip() override;

  void ramShip() override;
};