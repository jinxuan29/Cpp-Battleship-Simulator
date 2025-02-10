/**********|**********|**********|
Program: Destroyer.cpp

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



#include "../include/Destroyer.h"
#include <iostream>
#include <string>
#include <utility>

Destroyer::Destroyer() {}

Destroyer::Destroyer(const Position &position, int lives, int reviveCount,
                     int shipDestroyedCount, const std::string &shipName,
                     const std::string &shipType, const std::string &teamName,
                     bool isDestroyed, const char symbol)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed, symbol){}

Destroyer::~Destroyer() {
  std::cout << "Destroyer Removed \n";
  //if (upgradedShip) {
  //  delete upgradedShip;
  //  upgradedShip = nullptr;
  //}
}

Destroyer::Destroyer(const Destroyer &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
  this->upgradedShip = other.upgradedShip;
}

Destroyer &Destroyer::operator=(const Destroyer &other) {
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

Destroyer::Destroyer(Ship &&other) : Ship(std::move(other)) {
  this->setShipType("Destroyer");
  this->setShipDestroyedCount(0);
}

void Destroyer::shootingShip(Battlefield &battlefield) {
  Logger logger;
  std::string message = getShipName() + " is shooting";
  logger.logEvent(message);
  std::cout << getShipName() << " is shooting\n";

  Position currentPos = this->getPosition();

  // Generate a random position within city block distance <= 5
  Position shootingOffset;
  do {
    shootingOffset = Position().getRandomPositionFrom8Position();
  } while (abs(shootingOffset.getXValuePosition()) +
               abs(shootingOffset.getYValuePosition()) >
           5);

  Position shootingTarget = currentPos + shootingOffset;

  Ship *hit = battlefield.checkForEnemyShip(shootingTarget.getXValuePosition(),
                                            shootingTarget.getYValuePosition());

  if (hit && (hit->getTeamName() != this->getTeamName())) {
    message = getShipName() + " has hit " + hit->getShipName() + " at " +
              std::to_string(hit->getPosition().getXValuePosition()) + "," +
              std::to_string(hit->getPosition().getYValuePosition());
    logger.logEvent(message);
    std::cout << message;
    this->setShipDestroyedCount(getShipDestroyedCount() + 1);
    hit->setIsDestroyed(true);
  } else {
    message = getShipName() + " missed at (" +
              std::to_string(shootingTarget.getXValuePosition()) + ", " +
              std::to_string(shootingTarget.getYValuePosition()) + ")";
    logger.logEvent(message);
    std::cout << getShipName() << " missed at ("
              << shootingTarget.getXValuePosition() << ", "
              << shootingTarget.getYValuePosition() << ")\n";
  }
}

Ship *Destroyer::seeingShip(Battlefield &battlefield) {
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

void Destroyer::ramShip(Battlefield &battlefield) {
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

void Destroyer::runShip(Battlefield &battlefield) {
  shootingShip(battlefield);
  shootingShip(battlefield);
  ramShip(battlefield);
}

Ship *Destroyer::upgradeShip() {
  if (getShipDestroyedCount() >= 3) {  
    std::string message = getShipName() + " has been upgraded to SuperShip!";
    Logger().logEvent(message);
    std::cout << getShipName() << "has been upgraded to SuperShip!\n";
    this->upgradedShip = new SuperShip(std::move(*this));
    return upgradedShip;
  }
  return nullptr;
}