#include "../include/Corvette.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream>

Corvette::Corvette() {
  std::cout << "Corvette Created\n";
}

Corvette::Corvette(const Position &position, int lives, int reviveCount,
                   int shipDestroyedCount, const std::string &shipName,
                   const std::string &shipType, const std::string &teamName,
                   bool isDestroyed, const char symbol)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed, symbol) {
  // Seed the random number generator
  srand(static_cast<unsigned>(std::time(0)));
}

Corvette::~Corvette() {
  std::cout << "Corvette Removed\n";
}

Corvette::Corvette(const Corvette &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
}

Corvette &Corvette::operator=(const Corvette &other) {
  if (this != &other) {
    this->setPosition(other.getPosition());
    this->setShipName(other.getShipName());
    this->setShipType(other.getShipType());
    this->setLives(other.getLives());
    this->setReviveCount(other.getReviveCount());
    this->setShipDestroyedCount(other.getShipDestroyedCount());
  }
  return *this;
}

void Corvette::shootingShip(Battlefield &battlefield) {
    Logger logger;
    std::string message = getShipName() + " is preparing to shoot.";
    logger.logEvent(message);
    std::cout << message << std::endl;

    Position currentPos = getPosition();

    
    Position targetPos = currentPos + Position().getRandomPositionFrom8Position(); 

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
}

void Corvette::runShip(Battlefield &battlefield) {
  shootingShip(battlefield);
}

Ship *Corvette::upgradeShip() {
  std::cout << "Corvette is already the highest level ship!\n";
  return nullptr; // Return the current ship since it cannot be upgraded further
}