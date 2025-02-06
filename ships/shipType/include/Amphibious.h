#ifndef AMPHIBIOUS_H
#define AMPHIBIOUS_H

#include "../../../game/include/Battlefield.h"
#include "../../action/MovingShip.h"
#include "../../action/SeeingShip.h"
#include "../../action/ShootingShip.h"
#include "SuperShip.h"
#include <cstddef>
#include <cstdlib> // For rand ()

// can move in sea and land ifk if tht rammming or moving
class Amphibious : public MovingShip, public ShootingShip, public SeeingShip { 
private:
public:
  Amphibious();

  // Amphibious(std::string shipName, int xPosition, int yPosition, int lives,
  //            int reviveCount);

  Amphibious(const Position &position, int lives, int reviveCount,
             int shipDestroyedCount, const std::string &shipName,
             const std::string &shipType, const std::string &teamName,
             bool isDestroyed, const char symbol);

  ~Amphibious();

  Amphibious(const Amphibious &other);

  Amphibious &operator=(const Amphibious &other);

  Ship *getupgradedShip() const { return this->upgradedShip; };

  void movingShip(Battlefield &battlefield) override;

  void shootingShip(Battlefield &battlefield) override;

  Ship *seeingShip(Battlefield &battlefield) override;

  void runShip(Battlefield &battlefield) override;

  Ship *upgradeShip() override;
};
#endif // AMPHIBIOUS_H
