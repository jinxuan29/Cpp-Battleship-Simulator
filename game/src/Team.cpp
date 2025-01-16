#include "../include/Team.h"
#include <iostream>

Team::Team(std::string teamName, int numShips) {
  this->teamName = teamName;
  this->nummShip = numShips;
  this->teamShips = new Ship *[numShips];

  for (int i = 0; i < numShips; i++) {
    teamShips[i] = nullptr; // Initialize to avoid accessing garbage memory
  }
}

void Team::addShip(Ship *ship) {
  for (int i = 0; i < this->nummShip; i++) {
    if (!teamShips[i]) {
      teamShips[i] = ship;
      break;
    }
  }
}

void Team::getName() { std::cout << this->teamName; }

Team::~Team() {
  if (teamShips) {
    for (int i = 0; i < nummShip; i++) {
      if (teamShips[i]) {
        delete teamShips[i];
        teamShips[i] = nullptr;
      }
    }
    delete[] teamShips;
    teamShips = nullptr;
  }
  std::cout << "Destroyed team: " << teamName << "\n";
}
