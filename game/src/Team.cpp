#include "../include/Team.h"
#include <iostream>

Team::Team(std::string teamName) {
  this->teamName = teamName;

  // to avoid the memory be filled if garbage memory if its not filled with any
  // object yet
  // the () in the new Ship*[numship] assigns all the pointer into nullptr.
  //for (int i = 0; i < numShips; i++) {
  //  teamShips[i] = nullptr;
  //}
}

void Team::setTeamShipsArraySize(int numShips){
  this->numShip = numShips;
  this->teamShips = new Ship *[numShips]();
}

void Team::addShip(Ship *ship) {
  for (int i = 0; i < this->numShip; i++) {
    if (!teamShips[i]) {
      teamShips[i] = ship;
      break;
    }
  }
}

void Team::getName() { std::cout << this->teamName; }

void Team::displayTeamShips(){
  for (int i = 0; i<this->numShip; i++) {
     teamShips[i]->runShip(); 
     std::cout << "\n";
  }
}

Team::~Team() {
  if (teamShips) {
    for (int i = 0; i < numShip; i++) {
      if (teamShips[i]) {
    delete teamShips[i];
    teamShips[i] = nullptr;
      }
    }
    delete[] teamShips;
    teamShips = nullptr;
  }
}
