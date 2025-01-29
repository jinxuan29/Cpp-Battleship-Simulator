#pragma once

#include "../../action/MovingShip.h"
#include "../../action/RamShip.h"
#include "../../action/SeeingShip.h"
#include "../../action/ShootingShip.h"
#include "../..include/Battlefield.h"
#include <cstdlib> // For rand()

class SuperShip : public MovingShip,
                  public RamShip,
                  public SeeingShip,
                  public ShootingShip {
              
private : 
      // Added: Helper function for shooting at a position
      bool shootAt(const Position &pos);
public:
  SuperShip();

  //  SuperShip(std::string shipName, int xPosition, int yPosition, int lives,
  //          int reviveCount);

  SuperShip(const Position &position, int lives, int reviveCount,
            int shipDestroyedCount, const std::string &shipName,
            const std::string &shipType, const std::string &teamName,
            bool isDestroyed);

  ~SuperShip();

  SuperShip(const SuperShip &other);

  SuperShip &operator=(const SuperShip &other);

  void movingShip() override;

  void shootingShip() override;

  void seeingShip() override;

  void ramShip() override;

  void runShip() override;

  void upgradeShip() override;
};