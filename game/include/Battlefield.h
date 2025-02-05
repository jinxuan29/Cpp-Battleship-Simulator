#pragma once
#include "../../ships/shipType/include/Ship.h"
#include "../../utility/include/Logger.h"

class Battlefield {
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

  void display() const; // print the battlefield
  bool isIsland(int x, int y) const; // check if position is an island
  void placeIsland(int x, int y,
                   char symbol); // place all the island into battlefield
  void setIslandPosition();      // set island position into battlefield
  void printIslandPosition()
      const; // print all island position in (x,y) in battlefield
  void placeShipArrayIntoBattlefield(
      Ship **ship, int numShips); // place array of ship into the battlefield
  void placeShipIntoBattlefield(Ship *ship); // place ship (one only for respawn
                                             // queue) back into battlefield
  void updateBattlefield(); // update the current state of the battlefield
  bool isValidPosition(int x, int y) const;
  Ship* checkForEnemyShip(int x, int y); // Check if a ship is at (x, y)
  //Ship* randomlyPickAShipFromBattlefield(); // randomly get a ship from the battlefield

  /*
     on the ship shoot function check if it hits any ship using
     using ship position and check if the ship isDestroyed

     so
     if(ship.getPosition == shootPosition ) then only shoot
  */
};