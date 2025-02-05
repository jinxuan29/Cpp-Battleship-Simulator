#include "../include/Amphibious.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Amphibious::Amphibious() {};

Amphibious::Amphibious(const Position &position, int lives, int reviveCount,
                       int shipDestroyedCount, const std::string &shipName,
                       const std::string &shipType, const std::string &teamName,
                       bool isDestroyed, const char symbol)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed, symbol) {}

Amphibious::~Amphibious() {
  Logger().logEvent("Amphibious Removed");
  std::cout << "Amphibious Removed";
}

Amphibious::Amphibious(const Amphibious &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
  this->setTeamName(other.getTeamName());
  this->setIsDestroyed(other.getIsDestroyed());
}

Amphibious &Amphibious::operator=(const Amphibious &other) {
  if (this != &other) {
    this->setPosition(other.getPosition());
    this->setShipName(other.getShipName());
    this->setShipType(other.getShipType());
    this->setLives(other.getLives());
    this->setReviveCount(other.getReviveCount());
    this->setShipDestroyedCount(other.getShipDestroyedCount());
    this->setTeamName(other.getTeamName());
    this->setIsDestroyed(other.getIsDestroyed());
  }
  return *this;
}

// Shooting Function - Random fire in 8 directions
void Amphibious::shootingShip(Battlefield &battlefield) {
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

  bool hit = battlefield.checkForEnemyShip(shootingTarget.getXValuePosition(),
                                           shootingTarget.getYValuePosition());

  // If an enemy ship is found, destroy it
  if (hit) {
    message = getShipName() + " has hit a ship!";
    logger.logEvent(message);
    std::cout << getShipName() << " has hit a ship!";
    this->setShipDestroyedCount(getShipDestroyedCount() + 1);
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

void Amphibious::seeingShip(Battlefield &battlefield) {
  Logger logger;
  std::string message = getShipName() + " is looking at its current position";
  logger.logEvent(message);
  std::cout << getShipName() << " is looking at its current position\n";

  Position current = getPosition();
  message = getShipName() + " current position: (" +
            std::to_string(current.getXValuePosition()) + "," +
            std::to_string(current.getYValuePosition()) + ")";
  logger.logEvent(message);
  std::cout << getShipName() << " current position: ("
            << current.getXValuePosition() << "," << current.getYValuePosition()
            << ")";
}

void Amphibious::movingShip(Battlefield &battlefield) {
  Logger logger;
  std::string message = getShipName() + " is moving";
  logger.logEvent(message);
  std::cout << getShipName() << " is moving\n";

  Position possibleDirections[4] = {Position().Up(), Position().Down(),
                                    Position().Left(), Position().Right()};

  bool availableDirections[4] = {true, true, true, true};
  int remainingDirections = 4;

  while (remainingDirections > 0) {
    int randomIndex;
    do {
      // srand(time(0));
      randomIndex = rand() % 4;
    } while (!availableDirections[randomIndex]);

    Position randomDirection = possibleDirections[randomIndex];
    Position newPosition = getPosition() + randomDirection;

    if (battlefield.isValidPosition(newPosition.getXValuePosition(),
                                    newPosition.getYValuePosition())) {
      setPosition(newPosition);
      message = getShipName() + " moved to (" +
                std::to_string(newPosition.getXValuePosition()) + ", " +
                std::to_string(newPosition.getYValuePosition()) + ")";
      logger.logEvent(message);
      std::cout << getShipName() << " moved to ("
                << newPosition.getXValuePosition() << ", "
                << newPosition.getYValuePosition() << ")\n";
      return;
    } else {
      message = getShipName() + " could not move to (" +
                std::to_string(newPosition.getXValuePosition()) + ", " +
                std::to_string(newPosition.getYValuePosition()) +
                "), it's either an island or out of bounds. Retrying";
      // logger.logEvent(message);
      std::cout << getShipName() << " could not move to ("
                << newPosition.getXValuePosition() << ", "
                << newPosition.getYValuePosition()
                << "), it's either an island or out of bounds. Retrying\n";
    }
    availableDirections[randomIndex] = false;
    remainingDirections--;
  }
  message = getShipName() + " is trapped and cannot move.";
  logger.logEvent(message);
  std::cout << getShipName() << " is trapped and cannot move.\n";
}

void Amphibious::runShip(Battlefield &battlefield) {
  seeingShip(battlefield);
  movingShip(battlefield);
  shootingShip(battlefield);
  shootingShip(battlefield);
}

Ship *Amphibious::upgradeShip() {
  if (getShipDestroyedCount() >= 1) {
    std::string message = getShipName() + " has been upgraded to SuperShip!";
    Logger().logEvent(message);
    std::cout << getShipName() << "has been upgraded to SuperShip!\n";
    Ship *supership =
        new SuperShip(this->getPosition(), this->getLives(),
                      this->getReviveCount(), 0, this->getShipName(),
                      "SuperShip", this->getTeamName(), this->getIsDestroyed(), this->getSymbol());
    return supership;
  }
  return nullptr;
}
