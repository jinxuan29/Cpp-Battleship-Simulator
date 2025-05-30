/**********|**********|**********|
Program: GameManager.cpp 

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


#include "../include/GameManager.h"
#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

GameManager::GameManager(std::string filename) { this->filename = filename; }
void GameManager::readFile(std::string filename) {
  this->width = 0;
  this->height = 0;

  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Failed to open the file: " << filename << "\n";
    Logger().logEvent("Failed to open the file: " + filename); // Log the error
    return;
  }

  int lineCount = 0;
  std::string tempLine;
  while (std::getline(file, tempLine)) {
    lineCount++;
  }
  file.clear();
  file.seekg(0, std::ios::beg);

  // Allocate memory for storing lines
  std::string *lines = new std::string[lineCount];

  // Read lines into the dynamic array
  int index = 0;
  while (std::getline(file, tempLine)) {
    lines[index++] = tempLine;
  }
  file.close();

  this->numberOfTeams = 0;

  for (int i = 0; i < lineCount; i++) {
    if (lines[i].find("iteration") != std::string::npos) {
      size_t pos = lines[i].find(" ");
      this->iteration = std::stoi(lines[i].substr(pos + 1));
      Logger().logEvent("Iteration: " +
                        std::to_string(this->iteration)); // Log the iteration
    }
    if (lines[i].find("width") != std::string::npos) {
      size_t pos = lines[i].find(" ");
      this->width = std::stoi(lines[i].substr(pos + 1));
      Logger().logEvent("Width: " +
                        std::to_string(this->width)); // Log the width
    }
    if (lines[i].find("height") != std::string::npos) {
      size_t pos = lines[i].find(" ");
      this->height = std::stoi(lines[i].substr(pos + 1));
      Logger().logEvent("Height: " +
                        std::to_string(this->height)); // Log the height
    }
    if (lines[i].find("Team") != std::string::npos) {
      this->numberOfTeams++;
      Logger().logEvent("Team found: " + lines[i]); // Log the team information
    }
  }

  // Team Variable
  this->teamName = new std::string[numberOfTeams];
  this->teamNumTypeShip = new int[numberOfTeams];
  this->numberOfPerShip = new std::string *[numberOfTeams];
  int currentTeam = 0;

  // read file again cuz last time read file are used to get the number of team
  // to initialize the array, probably has better way of doing this
  std::ifstream file2(filename);
  if (!file2.is_open()) {
    Logger().logEvent("Failed to open the file: " + filename);
    std::cerr << "Failed to open the file: " << filename << "\n";
    return;
  }

  for (int i = 0; i < lineCount; i++) {
    if (lines[i].find("Team") != std::string::npos) {
      std::istringstream iss(lines[i]);
      std::string token;
      iss >> token; // "Team"
      iss >> this->teamName[currentTeam];
      iss >> this->teamNumTypeShip[currentTeam];
      this->numberOfPerShip[currentTeam] =
          new std::string[this->teamNumTypeShip[currentTeam]];
      for (int j = 0; j < this->teamNumTypeShip[currentTeam]; j++) {
        i++;
        if (i >= lineCount) {
          break;
        }
        this->numberOfPerShip[currentTeam][j] = lines[i];
      }
      currentTeam++;
    }
  }

  Logger().logEvent("Width: " + std::to_string(width));
  Logger().logEvent("Height: " + std::to_string(height));
  std::cout << numberOfTeams << "\n";
  std::cout << "Width: " << width << "\n"
            << "Height: " << height << "\n";

  // create battlefield and get it from lines
  this->battlefieldMap = new char *[height];
  for (int i = 0; i < height; i++) {
    this->battlefieldMap[i] = new char[width];
  }

  for (int i = lineCount - height, row = 0; i < lineCount && row < height;
       i++, row++) {
    std::istringstream iss(lines[i]);
    for (int col = 0; col < width; col++) {
      iss >> this->battlefieldMap[row][col];
    }
  }

  Logger().logEvent("Number of Teams: " + std::to_string(this->numberOfTeams));
  for (int i = 0; i < this->numberOfTeams; ++i) {
    Logger().logEvent("Team " + this->teamName[i] + " has " +
                      std::to_string(this->teamNumTypeShip[i]) + " ships:");
    for (int j = 0; j < this->teamNumTypeShip[i]; ++j) {
      Logger().logEvent("  " + this->numberOfPerShip[i][j]);
    }
  }

  std::cout << "Number of Teams: " << this->numberOfTeams << std::endl;
  for (int i = 0; i < this->numberOfTeams; ++i) {
    std::cout << "Team " << this->teamName[i] << " has "
              << this->teamNumTypeShip[i] << " ships:" << std::endl;
    for (int j = 0; j < this->teamNumTypeShip[i]; ++j) {
      std::cout << "  " << this->numberOfPerShip[i][j] << std::endl;
    }
  }
  delete[] lines;
}

void GameManager::addShipToActivityLinkList() {
  int maxShips = 0;
  for (int i = 0; i < numberOfTeams; i++) {
    if (teams[i]->getNumShip() > maxShips) {
      maxShips = teams[i]->getNumShip();
    }
  }

  for (int i = 0; i < maxShips; i++) {
    for (int j = 0; j < numberOfTeams; j++) {
      Ship **teamShips = teams[j]->getTeamShipsArray();
      int numShips = teams[j]->getNumShip();

      // Check if the current team has a ship at index
      if (i < numShips && teamShips[i]) {
        shipActivityLinkList.push_back(teamShips[i]);
      }
    }
  }
}

// void GameManager::displayShipActivityLinkList() const {
//   std::cout << "Ship Activity Link List:\n";
//   shipActivityLinkList.print(); // print function only works for ship class
//                                 // despite being template
// }

// all ships pointer had to change as well since its pointing to null
void GameManager::addDestroyedShipIntoQueue() {
  for (int i = 0; i < totalShipsAcrossAllTeams; i++) {
    if (allShips[i] && allShips[i]->getIsDestroyed() &&
        allShips[i]->getLives() > 0) {
      bool existInQueue = false;
      for (int j = 0; j < shipRespawnQueue.getSize(); j++) {
        if (shipRespawnQueue.peekAt(j) ==
            allShips[i]) { // ship ady inside the queue
          existInQueue = true;
          break;
        }
      }

      if (!existInQueue) {
        shipRespawnQueue.enqueue(allShips[i]);
      }
    }
  }
}

void GameManager::removeDestroyShipFromLinkList() {
  Logger().logEvent("Removing destroyed ships from the link list...");
  std::cout << "Removing destroyed ships from the link list...\n";
  for (int i = shipActivityLinkList.getSize() - 1; i >= 0; i--) {
    if (shipActivityLinkList.get(i)->getIsDestroyed() ||
        shipActivityLinkList.get(i)->getLives() < 1) {
      Logger().logEvent("Removing ship: " +
                        shipActivityLinkList.get(i)->getShipName());
      std::cout << "Removing ship: "
                << shipActivityLinkList.get(i)->getShipName() << "\n";
      shipActivityLinkList.remove(i);
    }
  }
  Logger().logEvent("Removal complete");
  std::cout << "Removal complete.\n";
}

void GameManager::respawnShip(Battlefield &battlefield) {
  // Attempt to respawn up to 2 ships from the respawn queue
  for (int i = 0; i < 2; i++) {
    if (!shipRespawnQueue.isEmpty()) {
      Ship *nextShip = shipRespawnQueue.peek();
      nextShip->setIsDestroyed(false);
      Logger().logEvent("Ship Respawn: " + nextShip->getShipName());
      std::cout << std::endl
                << "Ship Respawn: " << nextShip->getShipName() << std::endl;
      battlefield.placeShipIntoBattlefield(nextShip);
      nextShip->setLives(nextShip->getLives() - 1);
      nextShip->setReviveCount(nextShip->getReviveCount()+1);
      Logger().logEvent("Ship Lives: " + std::to_string(nextShip->getLives()));
      std::cout << std::endl
                << "Ship Lives: " << nextShip->getLives() << std::endl;
      shipActivityLinkList.push_back(nextShip);
      shipRespawnQueue.dequeue();
    } else {
      Logger().logEvent("No Ship on Respawn Queue");
      std::cout << "No Ship on Respawn Queue";
      break;
    }
  }
}

void GameManager::runGame() {
  readFile(this->filename);

  // Initialize battlefield
  Battlefield battlefield(this->battlefieldMap, this->width, this->height);
  battlefield.setIslandPosition();

  // Initialize teams
  std::cout << numberOfTeams << std::endl;

  this->teams = new Team *[numberOfTeams];
  this->totalShipsAcrossAllTeams = 0;

  // Calculate the total number of ships across all teams
  for (int i = 0; i < numberOfTeams; i++) {
    int totalNumberofShips = 0;
    for (int j = 0; j < teamNumTypeShip[i]; j++) {
      std::string shipDetails = this->numberOfPerShip[i][j];
      std::string shipType;
      char shipLogo;
      int numberOfShip;

      std::istringstream iss(shipDetails);
      iss >> shipType >> shipLogo >> numberOfShip;

      totalNumberofShips += numberOfShip;
    }
    teams[i] = new Team(teamName[i]);
    teams[i]->setTeamShipsArraySize(totalNumberofShips);
    this->totalShipsAcrossAllTeams += totalNumberofShips;
  }

  // Create a single array to hold all ships
  this->allShips = new Ship *[totalShipsAcrossAllTeams]();
  int shipIndex = 0;

  // Create ship objects and add them to the combined array
  for (int i = 0; i < numberOfTeams; i++) {
    for (int j = 0; j < teamNumTypeShip[i]; j++) {
      std::string shipDetails = this->numberOfPerShip[i][j];
      std::string shipType;
      char shipLogo;
      int numberOfShip;

      std::istringstream iss(shipDetails);
      iss >> shipType >> shipLogo >> numberOfShip;

      for (int k = 0; k < numberOfShip; k++) {
        Ship *ship = nullptr;

        if (shipType == "Amphibious") {
          ship = new Amphibious();
        } else if (shipType == "Corvette") {
          ship = new Corvette();
        } else if (shipType == "Cruiser") {
          ship = new Cruiser();
        } else if (shipType == "Destroyer") {
          ship = new Destroyer();
        } else if (shipType == "Frigate") {
          ship = new Frigate();
        } else if (shipType == "Supership") {
          ship = new SuperShip();
        } else if (shipType == "Battleship") {
          ship = new Battleship();
        } else {
          std::cerr << "Unknown ship type: " << shipType << std::endl;
        }

        if (ship) { // Check if 'ship' is not nullptr
          std::string shipName =
              teamName[i] + "_" + shipType + "_" + std::to_string(k);
          ship->setSymbol(shipLogo);
          ship->setTeamName(teamName[i]);
          ship->setShipName(shipName);
          ship->setShipType(shipType);
          ship->setShipDestroyedCount(0);
          ship->setReviveCount(0);
          ship->setLives(3);
          ship->setIsDestroyed(false);

          teams[i]->addShip(ship);      // Add the ship to the team
          allShips[shipIndex++] = ship; // Add the ship to the combined array
        } else {
          throw std::runtime_error("Ship not initialized during run game "
                                   "function. Maybe ship type does not exist.");
        }
      }
    }
  }

  // Place all ships into the battlefield
  battlefield.placeShipIntoBattlefield(allShips, totalShipsAcrossAllTeams);
  battlefield.display();

  for (int i = 0; i < numberOfTeams; i++) {
    teams[i]->displayTeamShips();
  }
  addShipToActivityLinkList();
  shipActivityLinkList.print();

  // game starts here
  int i = 0;
  while (i < iteration) {
    Logger().logEvent("Iteration " + std::to_string(i + 1));
    std::cout << "Iteration:" << i + 1 << std::endl;

    if (i != 0) {
      respawnShip(battlefield);
    }

    battlefield.updateBattlefield();
    // TODO if ship hit another ship but that ship lives is ady 0 juz ignore it
    shipActivityLinkList.RunShip(battlefield, this->allShips,
                                 this->totalShipsAcrossAllTeams);

    addDestroyedShipIntoQueue();

    // Remove destroyed ships from the link list
    removeDestroyShipFromLinkList();

    std::cout << "\n Remaining ships after removal:\n";
    shipActivityLinkList.print();

    // take the first two ship in queue to respawn. does not work on the first
    // round
    Logger().logEvent("Ship Queue: ");
    std::cout << std::endl << "Ship Queue:";
    shipRespawnQueue.print();
    std::cout << std::endl;

    i++;
  }
  int *teamRemainingShips = new int[numberOfTeams](); // Initialize to zero
  std::string *teamNames = new std::string[numberOfTeams];

  // Count remaining ships for each team
  for (int j = 0; j < totalShipsAcrossAllTeams; j++) {
    if (allShips[j] && !allShips[j]->getIsDestroyed() &&
        !(allShips[j]->getLives() < 1)) {
      std::string teamName = allShips[j]->getTeamName();
      bool found = false;

      // Find the index of the team in the array
      for (int k = 0; k < numberOfTeams; k++) {
        if (teamNames[k] == teamName) {
          teamRemainingShips[k]++;
          found = true;
          break;
        }
      }

      // If the team is not yet in the array, add it
      if (!found) {
        for (int k = 0; k < numberOfTeams; k++) {
          if (teamNames[k].empty()) {
            teamNames[k] = teamName;
            teamRemainingShips[k]++;
            break;
          }
        }
      }

      // Log details of each remaining ship
      Logger().logEvent(
          "  Ship Name: " + allShips[j]->getShipName() + ", Symbol: " +
          std::string(1, allShips[j]->getSymbol()) + ", Position: (" +
          std::to_string(allShips[j]->getPosition().getXValuePosition()) +
          ", " +
          std::to_string(allShips[j]->getPosition().getYValuePosition()) + ")");
      std::cout << "  Ship Name: " << allShips[j]->getShipName()
                << ", Symbol: " << allShips[j]->getSymbol() << ", Position: ("
                << allShips[j]->getPosition().getXValuePosition() << ", "
                << allShips[j]->getPosition().getYValuePosition() << ")\n";
    }
  }

  // Find the team with the most remaining ships
  int maxRemainingShips = -1;
  std::string winningTeam;
  bool isDraw = false;

  for (int k = 0; k < numberOfTeams; k++) {
    if (!teamNames[k].empty()) {
      std::cout << "Team " << teamNames[k] << " has " << teamRemainingShips[k]
                << " remaining ships.\n";
      Logger().logEvent("Team " + teamNames[k] + " has " +
                        std::to_string(teamRemainingShips[k]) +
                        " remaining ships.");

      if (teamRemainingShips[k] > maxRemainingShips) {
        maxRemainingShips = teamRemainingShips[k];
        winningTeam = teamNames[k];
        isDraw = false; // Reset draw flag if we find a new max
      } else if (teamRemainingShips[k] == maxRemainingShips &&
                 maxRemainingShips != -1) {
        isDraw = true; // Set draw flag if there's a tie
      }
    }
  }

  // Output the winning team
  if (maxRemainingShips > 0) {
    if (isDraw) {
      Logger().logEvent(
          "No winning team. Both teams have the same amount of ships.");
      std::cout
          << "\nNo winning team. Both teams have the same amount of ships.\n";
    } else {
      Logger().logEvent("\nWinning Team: " + winningTeam + " with " +
                        std::to_string(maxRemainingShips) +
                        " remaining ships.");
      std::cout << "\nWinning Team: " << winningTeam << " with "
                << maxRemainingShips << " remaining ships.\n";
    }
  } else {
    Logger().logEvent("No winning team. All ships are destroyed.");
    std::cout << "\nNo winning team. All ships are destroyed.\n";
  }

  // Clean up dynamically allocated arrays
  delete[] teamRemainingShips;
  delete[] teamNames;
}
GameManager::~GameManager() {
  if (battlefieldMap) {
    for (int i = 0; i < height; i++) {
      delete[] battlefieldMap[i];
    }
    delete[] battlefieldMap;
    battlefieldMap = nullptr;
  }

  if (allShips) {
    for(int i = 0; i<totalShipsAcrossAllTeams; i++){
      if(allShips[i] != nullptr){
        delete allShips[i];
        allShips[i] = nullptr;
      }
    }
    delete[] allShips;
    allShips = nullptr;
  }

  if (teams) {
    for (int i = 0; i < numberOfTeams; i++) {
      delete teams[i];
    }
    delete[] teams;
    teams = nullptr;
  }

  if (numberOfPerShip) {
    for (int i = 0; i < numberOfTeams; i++) {
      delete[] numberOfPerShip[i];
    }
    delete[] numberOfPerShip;
    numberOfPerShip = nullptr;
  }

  if (teamName) {
    delete[] teamName;
    teamName = nullptr;
  }

  if (teamNumTypeShip) {
    delete[] teamNumTypeShip;
    teamNumTypeShip = nullptr;
  }
}