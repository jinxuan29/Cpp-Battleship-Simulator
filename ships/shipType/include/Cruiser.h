#pragma once

#include "../../action/RamShip.h"
#include "../../action/SeeingShip.h"
#include "../include/Destroyer.h"

class Cruiser : public RamShip, public SeeingShip {
private:
  Ship *upgradedShip = nullptr;

public:
  Cruiser();

  //  Cruiser(std::string shipName, int xPosition, int yPosition, int lives,
  //          int reviveCount);

  Cruiser(const Position &position, int lives, int reviveCount,
          int shipDestroyedCount, const std::string &shipName,
          const std::string &shipType, const std::string &teamName,
          bool isDestroyed, const char symbol);

  ~Cruiser();

  Cruiser(const Cruiser &other);

  Cruiser &operator=(const Cruiser &other);

  Ship *seeingShip(Battlefield &battlefield) override;

  void ramShip(Battlefield &battlefield) override;

  void runShip(Battlefield &battlefield) override;

  Ship *upgradeShip() override;

  Ship *getupgradedShip() const { return this->upgradedShip; };
};