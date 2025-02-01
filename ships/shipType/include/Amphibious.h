#pragma once

#include "../../action/MovingShip.h"
#include "../../action/ShootingShip.h"
#include "../../action/SeeingShip.h"
#include "../../../game/include/Battlefield.h"
#include <cstdlib> // For rand ()

// can move in sea and land ifk if tht rammming or moving
class Amphibious : public MovingShip, public ShootingShip, public SeeingShip {

private:

    // Helper functions
    bool shootAt(const Position &pos);
     
public:
  Amphibious();

 // Amphibious(std::string shipName, int xPosition, int yPosition, int lives,
 //            int reviveCount);

  Amphibious(const Position &position, int lives, int reviveCount,
       int shipDestroyedCount, const std::string &shipName,
       const std::string &shipType, const std::string &teamName,
       bool isDestroyed);

  ~Amphibious();

  Amphibious(const Amphibious &other);

  Amphibious &operator=(const Amphibious &other);

  void movingShip() override;

  void shootingShip() override;

  void seeingShip() override;

  void runShip() override;

  void upgradeShip() override;

  
};
