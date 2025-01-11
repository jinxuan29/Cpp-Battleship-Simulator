#pragma once
#include "../../ships/shipType/include/Ship.h"

class Battlefield {
private:
  int width;
  int height;
  int numberOfIsland;
  char **grid;
  int **islandPosition;
  Ship ***shipGrid;

public:
  Battlefield(int w, int h);
  Battlefield(char **grid, int width, int height);
  ~Battlefield();

  void display() const;
  void placeIsland(int x, int y, char symbol);
  void setIslandPosition();
  void printIslandPosition();
};