#pragma once

#include "../../../utility/include/Position.h"
#include "../../action/ShootingShip.h"
#include "../include/Corvette.h"
#include <iostream>

class Frigate : public ShootingShip {
private:
  int firingDirectionIndex;
public:
  Frigate();

  Frigate(const Position &position, int lives, int reviveCount,
          int shipDestroyedCount, const std::string &shipName,
          const std::string &shipType, const std::string &teamName,
          bool isDestroyed, const char symbol);

  ~Frigate();

  Position shootingSequence[8] = {
      Position(0, -1), // up
      Position(1, -1), // up-right
      Position(1, 0),  // right
      Position(1, 1),  // down-right
      Position(0, 1),  // down
      Position(-1, 1), // down-left
      Position(-1, 0), // left
      Position(-1, -1) // up-left
  };



  Frigate(const Frigate &other);

  Frigate &operator=(const Frigate &other);

  void shootingShip(Battlefield &battlefield) override;

  Ship *upgradeShip() override;


  void runShip(Battlefield &battlefield) override;
 
  Ship *getupgradedShip() const { return this->upgradedShip; };
};