/**********|**********|**********|
Program: Team.cpp / Team.h

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


#include "../include/Team.h"
#include <iostream>

Team::Team(std::string teamName) {
  this->teamName = teamName;

  // to avoid the memory be filled if garbage memory if its not filled with any
  // object yet
  // the () in the new Ship*[numship] assigns all the pointer into nullptr.
  // for (int i = 0; i < numShips; i++) {
  //  teamShips[i] = nullptr;
  //}
}

void Team::setTeamShipsArraySize(int numShips) {
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

std::string Team::getName() const { return this->teamName; }

void Team::displayTeamShips() const {
  for (int i = 0; i < this->numShip; i++) {

    Logger logger;

    logger.logEvent(teamShips[i]->getSymbol());
    logger.logEvent(teamShips[i]->getTeamName());
    logger.logEvent(teamShips[i]->getShipName());
    logger.logEvent(
        "Position: (" +
        std::to_string(teamShips[i]->getPosition().getXValuePosition()) + ", " +
        std::to_string(teamShips[i]->getPosition().getYValuePosition()) + ")");
    std::cout << teamShips[i]->getSymbol() << "\n";
    std::cout << teamShips[i]->getTeamName() << "\n";
    std::cout << teamShips[i]->getShipName() << "\n";
    std::cout << "Position: ("
              << teamShips[i]->getPosition().getXValuePosition() << ", "
              << teamShips[i]->getPosition().getYValuePosition() << ")\n";
  }
}

Ship **Team::getTeamShipsArray() const { return this->teamShips; }

int Team::getNumShip() const { return this->numShip; }

Team::~Team() {
  if (teamShips) {
    for (int i = 0; i < numShip; i++) {
      if (teamShips[i]) {
        //delete teamShips[i];
        teamShips[i] = nullptr;
      }
    }
    delete[] teamShips;
    teamShips = nullptr;
  }
}
