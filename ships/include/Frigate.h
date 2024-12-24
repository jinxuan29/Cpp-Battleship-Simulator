#pragma once

#include "Ship.h"
#include <string>
class Frigate : public Ship {

public:
  Frigate();

  Frigate(std::string shipName, int xPosition, int yPosition, int lives,
            int reviveCount);

  ~Frigate();

  Frigate(const Frigate &other);

  Frigate &operator=(const Frigate &other);

  void movingShip() override;

  void shootingShip() override;

  void seeingRobot() override;

  void ramShip() override;
};