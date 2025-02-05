#pragma once

#include "../../../utility/include/Position.h"
#include "../../action/ShootingShip.h"
#include <string>

class Corvette : public ShootingShip {
private:
  Ship *upgradedShip;
  Position getRandomTargetPosition() const;

public:
  Corvette();

  Corvette(const Position &position, int lives, int reviveCount,
           int shipDestroyedCount, const std::string &shipName,
           const std::string &shipType, const std::string &teamName,
           bool isDestroyed, const char symbol);

  ~Corvette();

  Corvette(const Corvette &other);

  Corvette &operator=(const Corvette &other);

  void shootingShip(Battlefield &battlefield) override;

  void runShip(Battlefield &battlefield) override;

  Ship *upgradeShip() override;

  Ship *getupgradedShip() const { return this->upgradedShip; }
};