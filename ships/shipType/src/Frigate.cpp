/**********|**********|**********|
Program: Frigate.cpp

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



#include "../include/Frigate.h"
#include <cstdlib> // For rand()
#include <iostream>
#include <utility>

Frigate::Frigate() : firingDirectionIndex(0) {}

Frigate::Frigate(const Position &position, int lives, int reviveCount,
                 int shipDestroyedCount, const std::string &shipName,
                 const std::string &shipType, const std::string &teamName,
                 bool isDestroyed, const char symbol)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed, symbol), firingDirectionIndex(0) {}

Frigate::~Frigate() {
  //if (this->upgradedShip != nullptr) {
  //  delete upgradedShip;
  //  upgradedShip = nullptr;
  //}
  std::cout << "Frigate Removed\n";
}

Frigate::Frigate(const Frigate &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
  this->upgradedShip = other.upgradedShip;
  this->firingDirectionIndex = other.firingDirectionIndex;
}

Frigate &Frigate::operator=(const Frigate &other) {
  if (this != &other) {
    this->setPosition(other.getPosition());
    this->setShipName(other.getShipName());
    this->setShipType(other.getShipType());
    this->setLives(other.getLives());
    this->setReviveCount(other.getReviveCount());
    this->setShipDestroyedCount(other.getShipDestroyedCount());
    this->upgradedShip = other.upgradedShip;
    this->firingDirectionIndex = other.firingDirectionIndex;
  }
  return *this;
}

void Frigate::shootingShip(Battlefield &battlefield) {
  Logger logger;
  std::string message = getShipName() + " is preparing to shoot.";
  logger.logEvent(message);
  std::cout << message << std::endl;

  Position currentPos = getPosition();
  Position targetPos = currentPos + shootingSequence[firingDirectionIndex];

  Ship *target = battlefield.checkForEnemyShip(targetPos.getXValuePosition(),
                                               targetPos.getYValuePosition());

  if (target && target->getTeamName() != getTeamName()) {
    message = getShipName() + " has hit " + target->getShipName() + " at (" +
              std::to_string(targetPos.getXValuePosition()) + ", " +
              std::to_string(targetPos.getYValuePosition()) + ")";
    logger.logEvent(message);
    std::cout << message << std::endl;

    target->setIsDestroyed(true);
    setShipDestroyedCount(getShipDestroyedCount() + 1);
  } else {
    message = getShipName() + " missed at (" +
              std::to_string(targetPos.getXValuePosition()) + ", " +
              std::to_string(targetPos.getYValuePosition()) + ")";
    logger.logEvent(message);
    std::cout << message << std::endl;
  }

  firingDirectionIndex = (firingDirectionIndex + 1) % 8;
}

Ship *Frigate::upgradeShip() {
  if (getShipDestroyedCount() >= 3) {
    Logger logger;
    std::string message = getShipName() + " has been upgraded to Corvette!";
    logger.logEvent(message);
    std::cout << message << std::endl;

    upgradedShip =
        new Corvette(std::move(*this));

    return upgradedShip;
  }
  return nullptr;
}

void Frigate::runShip(Battlefield &battlefield) { shootingShip(battlefield); }
