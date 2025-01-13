#pragma once
#include "../../ships/shipType/include/Ship.h"

class Battlefield {
private:
  int width; // width of the baattlefield (columns)
  int height; // height of the battlefield (row)
  int numberOfIsland; // total number of island in the battlefield
  char **grid; // 2d array of char to represetation the battlefield 
  int **islandPosition;  // 2d array of all coords of the island in battlefield


  Ship ***shipGrid;

public:
  Battlefield(int w, int h);
  Battlefield(char **grid, int width, int height);
  ~Battlefield();

  void display() const; // print the battlefield
  void placeIsland(int x, int y, char symbol); // place all the island into battlefield
  void setIslandPosition(); // set island position into battlefield
  void printIslandPosition(); // print all island position in (x,y) in battlefield
};