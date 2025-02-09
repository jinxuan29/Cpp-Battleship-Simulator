/**********|**********|**********|
Program: Ship.h

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
#include <iostream>

class Battlefield;

class Ship {
private:
  Position position;      // Position (x,y) of the ship
  int lives;              // Revive count of the ship
  int reviveCount;        // Number of time ship has been revived
  int shipDestroyedCount; // Number of Ship destroyed
  std::string shipName;   // Name of Ship, its configured to named in a format
                          // "TeamName_ShipType_ID" the ID is start from 0
                          // Example A_Battleship_0

  std::string shipType; // Type of ship
  std::string teamName; // Team Name of the ship
  bool isDestroyed;     // Check if ship is destroyed
  char symbol;          // Symbol of ship displayed in battlefield

protected:
  Ship *upgradedShip = nullptr;

public:
  Ship();

  Ship(const Position &position, int lives, int reviveCount,
       int shipDestroyedCount, const std::string &shipName,
       const std::string &shipType, const std::string &teamName,
       bool isDestroyed, char symbol);

  virtual ~Ship() = default;

  Ship(Ship &&other);

  void setPosition(const Position &positiion);
  void setPosition(int x, int y);
  Position getPosition() const;

  void setLives(int lives = 3);
  int getLives() const;

  void setReviveCount(int reviveCount);
  int getReviveCount() const;

  void setShipDestroyedCount(int shipDestroyedCount = 0);
  int getShipDestroyedCount() const;

  void setShipName(std::string shipName);
  std::string getShipName() const;

  void setShipType(std::string shipType);
  std::string getShipType() const;

  void setTeamName(std::string teamName);
  std::string getTeamName() const;

  void setIsDestroyed(bool isDestroyed = false);
  bool getIsDestroyed() const;

  void setSymbol(char symbol);
  char getSymbol() const;

  virtual void runShip(Battlefield &battlefield) = 0; // run ship set of action.
  virtual Ship *upgradeShip() = 0; // unsure to put it here ot battlefield class
};
