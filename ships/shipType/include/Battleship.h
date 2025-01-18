#pragma once

#include "../../action/MovingShip.h"
#include "../../action/ShootingShip.h"
#include "../../action/SeeingShip.h"

class Battleship : public MovingShip, public ShootingShip, public SeeingShip {

private:
public:
  Battleship();

 // Battleship(std::string shipName, int xPosition, int yPosition, int lives,
 //            int reviveCount);

  Battleship(const Position &position, int lives, int reviveCount,
       int shipDestroyedCount, const std::string &shipName,
       const std::string &shipType, const std::string &teamName,
       bool isDestroyed);

  ~Battleship();

  Battleship(const Battleship &other);

  Battleship &operator=(const Battleship &other);

  void seeingShip() override;

  void movingShip() override;

  void shootingShip() override;

  void runShip() override;

  void upgradeShip() override;
};
