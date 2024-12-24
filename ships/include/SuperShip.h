#pragma once

#include "Ship.h"
#include <string>
class SuperShip : public Ship {

public:
  SuperShip();

   SuperShip(std::string shipName, int xPosition, int yPosition, int lives,
            int reviveCount);

  ~SuperShip();

  SuperShip(const SuperShip &other);

  SuperShip &operator=(const SuperShip &other);

  void movingShip() override;

  void shootingShip() override;

  void seeingRobot() override;

  void ramShip() override;
};