#include "../include/Corvette.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream>

Corvette::Corvette() {
  std::cout << "Corvette Created\n";
  // Seed the random number generator
  srand(static_cast<unsigned>(std::time(0)));
}

Corvette::Corvette(const Position &position, int lives, int reviveCount,
                   int shipDestroyedCount, const std::string &shipName,
                   const std::string &shipType, const std::string &teamName,
                   bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed) {
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
  Position target = getRandomTargetPosition();
  int targetX = target.getXValuePosition();
  int targetY = target.getYValuePosition();

  std::cout << "Corvette shooting at position: (" << targetX << ", " << targetY << ")\n";

  // Check if the target position contains an enemy ship
  if (battlefield.checkForEnemyShip(targetX, targetY)) {
    std::cout << "Ship destroyed at position: (" << targetX << ", " << targetY << ")\n"; // Ship destroyed
  } else {
    std::cout << "No ship at position: (" << targetX << ", " << targetY << ")\n"; // No ship at the target position
  }
}

Position Corvette::getRandomTargetPosition() const {
  // Define the 8 possible directions
  Position directions[8] = {
      Position(0, -1), // up
      Position(1, -1), // up-right
      Position(1, 0),  // right
      Position(1, 1),  // down-right
      Position(0, 1),  // down
      Position(-1, 1), // down-left
      Position(-1, 0), // left
      Position(-1, -1) // up-left
  };

  // Randomly select one of the 8 directions
  int randomIndex = std::rand() % 8;
  Position target = directions[randomIndex];

  // Calculate the target position relative to the Corvette's current position
  return Position(
      this->getPosition().getXValuePosition() + target.getXValuePosition(),
      this->getPosition().getYValuePosition() + target.getYValuePosition());
}

void Corvette::runShip(Battlefield &battlefield) {
  shootingShip(battlefield);
}

Ship *Corvette::upgradeShip() {
  std::cout << "Corvette is already the highest level ship!\n";
  return this; // Return the current ship since it cannot be upgraded further
}