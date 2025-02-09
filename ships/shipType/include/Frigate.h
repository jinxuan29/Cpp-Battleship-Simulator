/**********|**********|**********|
Program: Frigate.h

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
#include "../../action/ShootingShip.h"
#include "../include/Corvette.h"
#include <iostream>

class Frigate : public ShootingShip {
private:
  int firingDirectionIndex;
public:
  Frigate();

  Frigate(const Position &position, int lives, int reviveCount,
          int shipDestroyedCount, const std::string &shipName,
          const std::string &shipType, const std::string &teamName,
          bool isDestroyed, const char symbol);

  ~Frigate();

  Position shootingSequence[8] = {
      Position().Up(), // up
      Position().UpRight(), // up-right
      Position().UpLeft(),  // up-left
      Position().Down(),  // down
      Position().DownRight(), //down-right
      Position().DownLeft(), // down-left
      Position().Left(), // left
      Position().Right() // Right
  };



  Frigate(const Frigate &other);

  Frigate &operator=(const Frigate &other);

  void shootingShip(Battlefield &battlefield) override;

  Ship *upgradeShip() override;


  void runShip(Battlefield &battlefield) override;
 
  Ship *getupgradedShip() const { return this->upgradedShip; };
};