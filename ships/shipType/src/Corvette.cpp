#include "../include/Corvette.h"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

Corvette::Corvette() {
    std::cout << "Corvette Created\n";
    // Seed the random number generator
    std::srand(std::time(0));
}

Corvette::Corvette(const Position &position, int lives, int reviveCount,
                   int shipDestroyedCount, const std::string &shipName,
                   const std::string &shipType, const std::string &teamName,
                   bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed) {
    // Seed the random number generator
    std::srand(std::time(0));
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

void Corvette::shootingShip() {
    Position target = getRandomTargetPosition();
    std::cout << "Corvette shooting at position: (" << target.getXValuePosition() << ", " << target.getYValuePosition() << ")\n";

    // Simulate shooting logic (e.g., check if target is a ship, destroy it, etc.)
    // Log the action and result as part of the simulation
}

Position Corvette::getRandomTargetPosition() const { 
    // Define the 8 possible directions
    Position directions[8] = {
        Position(0, -1),  // up
        Position(1, -1),  // up-right
        Position(1, 0),   // right
        Position(1, 1),   // down-right
        Position(0, 1),   // down
        Position(-1, 1),  // down-left
        Position(-1, 0),  // left
        Position(-1, -1)  // up-left
    };

    // Randomly select one of the 8 directions
    int randomIndex = std::rand() % 8;
    Position target = directions[randomIndex];

    // Calculate the target position relative to the Corvette's current position
    return Position(this->getPosition().getXValuePosition() + target.getXValuePosition(), 
                    this->getPosition().getYValuePosition() + target.getYValuePosition());
}

void Corvette::runShip(){
    shootingShip();
}

void Corvette::upgradeShip() {
    std::cout << "Corvette is already the highest level ship!\n";
}