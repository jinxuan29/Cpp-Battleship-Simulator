#pragma once

#include "../../../game/include/Battlefield.h"
#include "../../action/MovingShip.h"
#include "../../action/RamShip.h"
#include "../../action/SeeingShip.h"
#include "../../action/ShootingShip.h"
#include <cstdlib> // For rand()
#include <utility>

class Battlefield;

class SuperShip : public RamShip, public SeeingShip, public ShootingShip {

public:
  SuperShip();

  //  SuperShip(std::string shipName, int xPosition, int yPosition, int lives,
  //          int reviveCount);

  SuperShip(const Position &position, int lives, int reviveCount,
            int shipDestroyedCount, const std::string &shipName,
            const std::string &shipType, const std::string &teamName,
            bool isDestroyed, const char symbol);

  ~SuperShip();

  SuperShip(Ship &&other);

  void shootingShip(Battlefield &battlefield) override;

  Ship *seeingShip(Battlefield &battlefield) override;

  void ramShip(Battlefield &battlefield) override;

  void runShip(Battlefield &battlefield) override;

  Ship *upgradeShip() override;
};