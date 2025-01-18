#include "../include/Battlefield.h"
#include <ctime>
#include <iostream>

Battlefield::Battlefield(int width, int height) : width(width), height(height) {
  grid = new char *[height];
  for (int i = 0; i < height; i++) {
    grid[i] = new char[width];

    for (int j = 0; j < width; j++) {
      grid[i][j] = '0';
    }
  }
}

Battlefield::Battlefield(char **grid, int width, int height)
    : width(width), height(height), numberOfIsland(0), islandPosition(nullptr) {
  this->grid = new char *[height];
  for (int i = 0; i < height; i++) {
    this->grid[i] = new char[width];
    for (int j = 0; j < width; j++) {
      this->grid[i][j] = grid[i][j];
    }
  }
}

// Battlefield::Battlefield(char** grid){
//   this->grid = grid;
// }

void Battlefield::display() const {
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      std::cout << grid[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

void Battlefield::setIslandPosition() {
  int numberOfIsland = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (grid[i][j] == '1') {
        numberOfIsland++;
      }
    }
  }
  this->numberOfIsland = numberOfIsland;
  // get island position and store inside islandposition array
  this->islandPosition = new int *[numberOfIsland];
  for (int i = 0; i < numberOfIsland; i++) {
    this->islandPosition[i] = new int[2];
  }
  int currentIndex = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (grid[i][j] == '1') {
        this->islandPosition[currentIndex][0] = i;
        this->islandPosition[currentIndex][1] = j;
        currentIndex++;
      }
    }
  }
}

// only works after running the setIslandPosition function
// starts from 0 instead of 1 
void Battlefield::printIslandPosition(){
  std::cout << "Island Positions:\n";
  for (int i = 0; i<this->numberOfIsland;i++) {
    std::cout<< this->islandPosition[i][0] << ":" << this->islandPosition[i][1] << "\n"; 
  }
}

void Battlefield::placeIsland(int x, int y, char symbol) {
  grid[x][y] = symbol;
  display();
}

void Battlefield::placeShipIntoBattlefield(Ship** ships, int numShips) {
  srand(time(0)); 

  int emptyPositions = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (grid[i][j] == '0') {
        emptyPositions++;
      }
    }
  }

  if (emptyPositions < numShips) {
    std::cerr << "Error: Not enough empty positions to place all ships.\n";
    return;
  }

  for (int i = 0; i < numShips; i++) {
    if (!ships[i]) {
      std::cerr << "Error: Ship at index " << i << " is null.\n";
      continue;
    }

    bool placed = false;
    int attempts = 0;
    const int maxAttempts = width * height; 

    while (!placed && attempts < maxAttempts) {
      
      int x = rand() % height; 
      int y = rand() % width;  

      bool isIsland = false;

      for (int j = 0; j < numberOfIsland; j++) {
        if (islandPosition[j][0] == x && islandPosition[j][1] == y) {
          isIsland = true;
          break;
        }
      }

      if (!isIsland && grid[x][y] == '0') {
        grid[x][y] = ships[i]->getSymbol();
        placed = true;

        ships[i]->setPosition(Position(x, y));
      }

      attempts++;
    }

    if (!placed) {
      std::cerr << "Error: Could not place ship " << i << " after " << maxAttempts << " attempts.\n";
    }
  }
}

Battlefield::~Battlefield() {
  if (this->grid) {
    for (int i = 0; i < height; i++) {
      delete[] this->grid[i];
    }
    delete[] this->grid;
    this->grid = nullptr;
  }

  if (this->islandPosition) {
    for (int i = 0; i <this->numberOfIsland ; i++) {
      delete[] this->islandPosition[i];
    }
    delete[] this->islandPosition;
    this->islandPosition = nullptr;
  }
}