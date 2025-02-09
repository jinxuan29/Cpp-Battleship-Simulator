/**********|**********|**********|
Program: Cruiser.cpp 

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



#include "../include/Cruiser.h"
#include <iostream>

Cruiser::Cruiser(): Ship(Position(), 3, 0, 0, "", "Cruiser", "", false, '0') {};;

Cruiser::Cruiser(const Position &position, int lives, int reviveCount,
                 int shipDestroyedCount, const std::string &shipName,
                 const std::string &shipType, const std::string &teamName,
                 bool isDestroyed, const char symbol)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed, symbol){}

Cruiser::~Cruiser() {
  std::cout << "Cruiser Removed \n";
  //if (this->upgradedShip!=nullptr) {
  //  delete upgradedShip;
  //  upgradedShip = nullptr;
  //}
}

Cruiser::Cruiser(const Cruiser &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
  this->upgradedShip = other.upgradedShip;
}

Cruiser &Cruiser::operator=(const Cruiser &other) {
  if (this != &other) {
    this->setPosition(other.getPosition());
    this->setShipName(other.getShipName());
    this->setShipType(other.getShipType());
    this->setLives(other.getLives());
    this->setReviveCount(other.getReviveCount());
    this->setShipDestroyedCount(other.getShipDestroyedCount());
    this->upgradedShip = other.upgradedShip;
  }
  return *this;
}

void Cruiser::ramShip(Battlefield &battlefield) {
  Logger logger;
  std::string message = getShipName() + " is preparing to ram.";
  logger.logEvent(message);
  std::cout << message << std::endl;

  Ship *target = seeingShip(battlefield);
  Position currentPos = getPosition();
  Position bestMove = currentPos;

  if (target) {
    bestMove = target->getPosition();

    target->setIsDestroyed(true);
    this->setShipDestroyedCount(this->getShipDestroyedCount() + 1);

    message = getShipName() + " has rammed  " + target->getShipName() + "!";
    logger.logEvent(message);
    std::cout << message << std::endl;
  } else {
    bool moved = false;
    for (int dx = -1; dx <= 1 && !moved; dx++) {
      for (int dy = -1; dy <= 1 && !moved; dy++) {
        int newX = currentPos.getXValuePosition() + dx;
        int newY = currentPos.getYValuePosition() + dy;

        if (battlefield.isValidPosition(newX, newY) &&
            !battlefield.isIsland(newX, newY) &&
            !battlefield.checkForEnemyShip(newX, newY)) {

          bestMove = Position(newX, newY);
          moved = true;
        }
      }
    }

    if (!moved) {
      message = getShipName() + " is trapped and cannot move.";
      logger.logEvent(message);
      std::cout << message << std::endl;
      return;
    }
  }

  setPosition(bestMove);
  message = getShipName() + " moved to (" +
            std::to_string(bestMove.getXValuePosition()) + ", " +
            std::to_string(bestMove.getYValuePosition()) + ")";
  logger.logEvent(message);
  std::cout << message << std::endl;
}

Ship *Cruiser::seeingShip(Battlefield &battlefield) {
  Logger logger;
  std::string message = getShipName() + " is scanning for enemy ships.";
  logger.logEvent(message);
  std::cout << message << std::endl;

  Position currentPos = getPosition();

  // Scan 3x3
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      int newX = currentPos.getXValuePosition() + dx;
      int newY = currentPos.getYValuePosition() + dy;

      if (battlefield.isValidPosition(newX, newY) &&
          !battlefield.isIsland(newX, newY)) {
        Ship *enemy = battlefield.checkForEnemyShip(newX, newY);
        if (enemy && enemy->getTeamName() != this->getTeamName()) {
          message =
              getShipName() + " spotted enemy ship: " + enemy->getShipName();
          logger.logEvent(message);
          std::cout << message << std::endl;
          return enemy;
        }
      }
    }
  }
  message = getShipName() + " found no enemies nearby.";
  logger.logEvent(message);
  std::cout << message << std::endl;
  return nullptr; 
}

void Cruiser::runShip(Battlefield &battlefield) {
  ramShip(battlefield);
  std::cout << "Cruiser running";
}

Ship *Cruiser::upgradeShip() {
  if (getShipDestroyedCount() >= 3) {
    //if (this->upgradedShip) {
    //  delete upgradedShip;
    //  upgradedShip = nullptr;
    //}
    std::string message = getShipName() + " has been upgraded to Destroyer!";
    Logger().logEvent(message);
    std::cout << getShipName() << "has been upgraded to Destroyer!\n";
    this->upgradedShip = new Destroyer(
        this->getPosition(), this->getLives(), this->getReviveCount(), 0,
        this->getShipName(), "Destroyer", this->getTeamName(),
        this->getIsDestroyed(), this->getSymbol());
    return upgradedShip;
  }
  return nullptr;
}
