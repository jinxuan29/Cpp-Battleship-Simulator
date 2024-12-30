#pragma once

#include "../../action/MovingShip.h"
#include "../../action/RamShip.h"
#include "../../action/SeeingShip.h"
#include "../../action/ShootingShip.h"

class Destroyer : public MovingShip, public RamShip, public SeeingShip, public ShootingShip {
    Destroyer();

//  Destroyer(std::string shipName, int xPosition, int yPosition, int lives,
//          int reviveCount);

  Destroyer(const Position &position, int lives, int reviveCount,
       int shipDestroyedCount, const std::string &shipName,
       const std::string &shipType, const std::string &teamName,
       bool isDestroyed);

  ~Destroyer();

  Destroyer(const Destroyer &other);

  Destroyer &operator=(const Destroyer &other);

  void movingShip() override;

  void shootingShip() override;

  void seeingShip() override;

  void ramShip() override;
};