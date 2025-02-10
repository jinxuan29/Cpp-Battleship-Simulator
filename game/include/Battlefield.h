/**********|**********|**********|
Program: Battlefield.h

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
#include "../../ships/shipType/include/Ship.h"
#include "../../utility/include/Logger.h"

class Battlefield
{
private:
  int width;              // width of the baattlefield (columns)
  int height;             // height of the battlefield (row)
  int numberOfIsland;     // total number of island in the battlefield
  int totalNumberOfShips; // total number of ships in the battlefield
  char **grid;            // 2d array of char to represetation the battlefield
  int **islandPosition;   // 2d array of all coords of the island in battlefield
  Ship **battlefieldShip; // array of ships that currently in the battlefield

public:
  Battlefield(int w, int h);
  Battlefield(char **grid, int width, int height);
  ~Battlefield();

  // Getter methods for width and height
  int getWidth() const;
  int getHeight() const;

  void display() const;              // print the battlefield
  bool isIsland(int x, int y) const; // check if position is an island
  void placeIsland(int x, int y,
                   char symbol); // place all the island into battlefield
  void setIslandPosition();      // set island position into battlefield
  void printIslandPosition()
      const; // print all island position in (x,y) in battlefield
  void placeShipIntoBattlefield(
      Ship **ship, int numShips);            // place array of ship into the battlefield
  void placeShipIntoBattlefield(Ship *ship); // place ship (one only for respawn
                                             // queue) back into battlefield
  void updateBattlefield();                  // update the current state of the battlefield
  bool isValidPosition(int x, int y) const;
  Ship *checkForShip(int x, int y); // Check if a ship is at (x, y)
  bool replaceShipInBattlefieldShipByName(std::string &shipname, Ship *ship);
  Ship **getBattlefieldShipArray();
  void printBattlefieldShipArray();
  // Ship* randomlyPickAShipFromBattlefield(); // randomly get a ship from the battlefield

  /*
     on the ship shoot function check if it hits any ship using
     using ship position and check if the ship isDestroyed

     so
     if(ship.getPosition == shootPosition ) then only shoot
  */
};