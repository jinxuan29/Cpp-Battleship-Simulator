/**********|**********|**********|
Program: Amphibious.cpp

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

#include "../include/Amphibious.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <utility>

Amphibious::Amphibious()
    : Ship(Position(), 3, 0, 0, "", "Amphibious", "", false, '0') {};

Amphibious::Amphibious(const Position &position, int lives, int reviveCount,
                       int shipDestroyedCount, const std::string &shipName,
                       const std::string &shipType, const std::string &teamName,
                       bool isDestroyed, const char symbol)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed, symbol) {}

Amphibious::~Amphibious() {
  // Logger().logEvent("Amphibious Removed");
  std::cout << "Amphibious Removed \n";

  /// if (this->upgradedShip != nullptr) {
  ///   delete this->upgradedShip;
  ///   upgradedShip = nullptr;
  /// }
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
  this->upgradedShip = other.getupgradedShip();
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
    this->upgradedShip = other.getupgradedShip();
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

  Ship *hit = battlefield.checkForShip(shootingTarget.getXValuePosition(),
                                       shootingTarget.getYValuePosition());

  // If an enemy ship is found, destroy it
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

Ship *Amphibious::seeingShip(Battlefield &battlefield) {
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
  return nullptr;
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
      randomIndex = rand() % 4;
    } while (!availableDirections[randomIndex]);

    Position randomDirection = possibleDirections[randomIndex];
    Position newPosition = getPosition() + randomDirection;

    int newX = newPosition.getXValuePosition();
    int newY = newPosition.getYValuePosition();

    if (battlefield.isValidPosition(newX, newY) &&
        !battlefield.checkForShip(newX, newY)) {
      setPosition(newPosition);
      message = getShipName() + " moved to (" + std::to_string(newX) + ", " +
                std::to_string(newY) + ")";
      logger.logEvent(message);
      std::cout << getShipName() << " moved to (" << newX << ", " << newY
                << ")\n";
      return;
    } else {
      message =
          getShipName() + " could not move to (" + std::to_string(newX) + ", " +
          std::to_string(newY) +
          "), it's either occupied, an island, or out of bounds. Retrying";
      logger.logEvent(message);
      std::cout
          << getShipName() << " could not move to (" << newX << ", " << newY
          << "), it's either occupied, an island, or out of bounds. Retrying\n";
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

  if (getShipDestroyedCount() >= 3) {
    std::string message = getShipName() + " has been upgraded to SuperShip!";
    Logger().logEvent(message);
    std::cout << getShipName() << " has been upgraded to SuperShip!\n";

    try {
      this->upgradedShip = new SuperShip(std::move(*this));

      return this->upgradedShip;
    } catch (const std::bad_alloc &) {
      std::cerr << "Memory allocation failed for SuperShip\n";
      this->upgradedShip = nullptr;
    } catch (...) {
      std::cerr << "Unknown error occurred while upgrading to SuperShip\n";
      this->upgradedShip = nullptr;
    }
  }

  return nullptr;
}
