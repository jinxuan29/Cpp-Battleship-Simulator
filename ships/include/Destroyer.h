#pragma once

#include "Ship.h"
#include <string>
class Destroyer : public Ship {

public:
  Destroyer();

  Destroyer(std::string shipName, int xPosition, int yPosition, int lives,
            int reviveCount);

  ~Destroyer();

  Destroyer(const Destroyer &other);

  Destroyer &operator=(const Destroyer &other);

  void movingShip() override;

  void shootingShip() override;

  void seeingRobot() override;

  void ramShip() override;
};