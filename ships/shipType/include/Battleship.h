#pragma once

#include "../../../utility/include/Position.h"
#include "../../action/MovingShip.h"
#include "../../action/SeeingShip.h"
#include "../../action/ShootingShip.h"
#include "../include/Destroyer.h"

class Battleship : public MovingShip, public ShootingShip, public SeeingShip {

private:
  Ship *upgradedShip = nullptr;

public:
  Battleship();

  // Battleship(std::string shipName, int xPosition, int yPosition, int lives,
  //            int reviveCount);

  Battleship(const Position &position, int lives, int reviveCount,
             int shipDestroyedCount, const std::string &shipName,
             const std::string &shipType, const std::string &teamName,
             bool isDestroyed, const char symbol);

  ~Battleship();

  Battleship(const Battleship &other);

  Battleship &operator=(const Battleship &other);

  Ship *getupgradedShip() const { return this->upgradedShip; };

  Ship *seeingShip(Battlefield &battlefield) override;

  void movingShip(Battlefield &battlefield) override;

  void shootingShip(Battlefield &battlefield) override;

  void runShip(Battlefield &battlefield) override;

  Ship *upgradeShip() override;
};
