#pragma once

#include "Ship.h"
#include <string>
class Cruiser : public Ship {

public:
  Cruiser();

  Cruiser(std::string shipName, int xPosition, int yPosition, int lives,
            int reviveCount);

  ~Cruiser();

  Cruiser(const Cruiser &other);

  Cruiser &operator=(const Cruiser &other);

  void movingShip() override;

  void shootingShip() override;

  void seeingRobot() override;

  void ramShip() override;
};