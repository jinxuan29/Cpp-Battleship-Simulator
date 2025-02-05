#include "../include/Frigate.h"
#include <iostream>
#include <cstdlib> // For rand()

Frigate::Frigate() : shotsFired(0), shipsDestroyed(0) {}

Frigate::Frigate(const Position &position, int lives, int reviveCount,
                 int shipDestroyedCount, const std::string &shipName,
                 const std::string &shipType, const std::string &teamName,
                 bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed), shotsFired(0), shipsDestroyed(0) {}

Frigate::~Frigate() { 
    std::cout << "Frigate Removed\n"; 
}

Frigate::Frigate(const Frigate &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
  this->shotsFired = other.shotsFired;
  this->shipsDestroyed = other.shipsDestroyed;
}

Frigate &Frigate::operator=(const Frigate &other) {
  if (this != &other) {
    this->setPosition(other.getPosition());
    this->setShipName(other.getShipName());
    this->setShipType(other.getShipType());
    this->setLives(other.getLives());
    this->setReviveCount(other.getReviveCount());
    this->setShipDestroyedCount(other.getShipDestroyedCount());
    this->shotsFired = other.shotsFired;
    this->shipsDestroyed = other.shipsDestroyed;
  }
  return *this;
}

void Frigate::shootingShip(Battlefield &battlefield) {
    Position target = getNextTargetPosition();
    int targetX = target.getXValuePosition();
    int targetY = target.getYValuePosition();

    std::cout << "Frigate shooting at position: (" << targetX << ", " << targetY << ")\n";

    // Check if the target position contains an enemy ship
    if (battlefield.checkForEnemyShip(targetX, targetY)) {
        shipsDestroyed++; // Increment the ships destroyed counter
        std::cout << "Ship destroyed! Total ships destroyed: " << shipsDestroyed << "\n"; // Ship destroyed
    } else {
        std::cout << "No ship at position: (" << targetX << ", " << targetY << ")\n"; // No ship at the target position
    }

    // Check if the frigate should upgrade to Corvette
    if (shouldUpgrade()) {
        upgradeShip();
    }
}

Ship* Frigate::upgradeShip() {
    std::cout << "Frigate has destroyed " << shipsDestroyed << " ships and is now upgrading to Corvette!\n";
    // Update ship type and behavior (e.g., random shooting)
    this->setShipType("Corvette");
    return this; // Return the upgraded ship
}

Position Frigate::getNextTargetPosition() {
    // Calculate the next target position based on the shooting sequence
    Position target = shootingSequence[shotsFired % 8];
    shotsFired++;
    return Position(this->getPosition().getXValuePosition() + target.getXValuePosition(), 
                    this->getPosition().getYValuePosition() + target.getYValuePosition());
}

bool Frigate::shouldUpgrade() const {
    return shipsDestroyed >= UPGRADE_THRESHOLD;
}

void Frigate::runShip(Battlefield &battlefield) {
    shootingShip(battlefield);
}