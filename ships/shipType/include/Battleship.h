/**********|**********|**********|
Program: Battleship.h

Course: Object Oriented Programing and Data Structure 
Trimester: 2410
Name: Yen Jin Xuan
ID: 242UC243R3
Lecture Section: TC
Tutorial Section: TT1L
Email: yen.jin.xuan@student.mmu.edu.my
Phone: 01633131910

Course: Object Oriented Programing and Data Structure 
Trimester: 2410
Name: Nishant A/L Kesavan 
ID: 241UC2407W
Lecture Section: TC1L
Tutorial Section: TT1L
Email: NISHANT.KESAVAN@student.mmu.edu.my
Phone: 019-8960477

Course: Object Oriented Programing and Data Structure 
Trimester: 2410
Name: Raveen A/L PARAMASIWAM 
ID: 241UC24180
Lecture Section: TC1L
Tutorial Section: TT1L
Email: RAVEEN.AL.PARAMASIWAM@student.mmu.edu.my
Phone: 017-6476584
**********|**********|**********/


#pragma once

#include "../../../utility/include/Position.h"
#include "../../action/MovingShip.h"
#include "../../action/SeeingShip.h"
#include "../../action/ShootingShip.h"
#include "../include/Destroyer.h"

class Battleship : public MovingShip, public ShootingShip, public SeeingShip {



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
