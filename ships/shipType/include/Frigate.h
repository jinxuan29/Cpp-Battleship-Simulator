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
      Position().Up(), // up
      Position().UpRight(), // up-right
      Position().UpLeft(),  // up-left
      Position().Down(),  // down
      Position().DownRight(), //down-right
      Position().DownLeft(), // down-left
      Position().Left(), // left
      Position().Right() // Right
  };



  Frigate(const Frigate &other);

  Frigate &operator=(const Frigate &other);

  void shootingShip(Battlefield &battlefield) override;

  Ship *upgradeShip() override;


  void runShip(Battlefield &battlefield) override;
 
  Ship *getupgradedShip() const { return this->upgradedShip; };
};