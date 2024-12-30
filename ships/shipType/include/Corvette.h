#pragma once

#include "../../action/ShootingShip.h"


class Corvette :  public ShootingShip {
    Corvette();

//  Corvette(std::string shipName, int xPosition, int yPosition, int lives,
//          int reviveCount);

  Corvette(const Position &position, int lives, int reviveCount,
       int shipDestroyedCount, const std::string &shipName,
       const std::string &shipType, const std::string &teamName,
       bool isDestroyed);

  ~Corvette();

  Corvette(const Corvette &other);

  Corvette &operator=(const Corvette &other);

  void shootingShip() override;
};