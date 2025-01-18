#pragma once

#include "../../action/MovingShip.h"
#include "../../action/RamShip.h"
#include "../../action/SeeingShip.h"

class Cruiser : public MovingShip, public RamShip,public SeeingShip {

public:
  Cruiser();

//  Cruiser(std::string shipName, int xPosition, int yPosition, int lives,
//          int reviveCount);


  Cruiser(const Position &position, int lives, int reviveCount,
       int shipDestroyedCount, const std::string &shipName,
       const std::string &shipType, const std::string &teamName,
       bool isDestroyed);

  ~Cruiser();

  Cruiser(const Cruiser &other);

  Cruiser &operator=(const Cruiser &other);

  Ship *upgradeShip(Ship *shipObj);

  void movingShip() override;

  void seeingShip() override;

  void ramShip() override;
  
  void runShip() override;

  void upgradeShip() override;
};