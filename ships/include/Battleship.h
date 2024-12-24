#pragma once

#include "Ship.h"
#include <string>

class Battleship : public Ship {

private:
public:
  Battleship();

  Battleship(std::string shipName, int xPosition, int yPosition, int lives,
             int reviveCount);

  ~Battleship();

  Battleship(const Battleship &other);

  Battleship &operator=(const Battleship &other);

  void movingShip() override;

  void shootingShip() override;

  void seeingRobot() override;

  void ramShip() override;
};
