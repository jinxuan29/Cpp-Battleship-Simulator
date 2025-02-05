#pragma once

#include "../../action/MovingShip.h"
#include "../../action/RamShip.h"
#include "../../action/SeeingShip.h"
#include "../../action/ShootingShip.h"

class Destroyer : public MovingShip,
                  public RamShip,
                  public SeeingShip,
                  public ShootingShip {
public:
  Destroyer();

  //  Destroyer(std::string shipName, int xPosition, int yPosition, int lives,
  //          int reviveCount);

  Destroyer(const Position &position, int lives, int reviveCount,
            int shipDestroyedCount, const std::string &shipName,
            const std::string &shipType, const std::string &teamName,
            bool isDestroyed, const char symbol);

  ~Destroyer();

  Destroyer(const Destroyer &other);

  Destroyer &operator=(const Destroyer &other);

  void movingShip(Battlefield &battlefield) override;

  void shootingShip(Battlefield &battlefield) override;

  void seeingShip(Battlefield &battlefield) override;

  void ramShip(Battlefield &battlefield) override;

  void runShip(Battlefield &battlefield) override;

  Ship *upgradeShip() override;
};