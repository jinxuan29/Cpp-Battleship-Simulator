#include "../include/Frigate.h"
#include <iostream>
#include <string>

Frigate::Frigate(){}

Frigate::Frigate(const Position &position, int lives, int reviveCount,
                 int shipDestroyedCount, const std::string &shipName,
                 const std::string &shipType, const std::string &teamName,
                 bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed), shotsFired(0), shipsDestroyed(0) {}

Frigate::~Frigate() { std::cout << "Frigate Removed\n"; }

Frigate::Frigate(const Frigate &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipTypes());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
}

Frigate &Frigate::operator=(const Frigate &other) {
  if (this != &other) {
    this->setPosition(other.getPosition());
    this->setShipName(other.getShipName());
    this->setShipType(other.getShipTypes());
    this->setLives(other.getLives());
    this->setReviveCount(other.getReviveCount());
    this->setShipDestroyedCount(other.getShipDestroyedCount());
  }
  return *this;
}

void Frigate::shootingShip() {
    Position target = getNextTargetPosition();
    std::cout << "Frigate shooting at position: (" << target.getXValuePosition() << ", " << target.getYValuePosition() << ")\n";

    // Simulate shooting logic (e.g., check if target is a ship, destroy it, etc.)
    // For demonstration purposes, assume the shot always destroys a ship
    bool isShipDestroyed = true; // Replace with actual logic to check if a ship is destroyed

    if (isShipDestroyed) {
        shipsDestroyed++; // Increment the ships destroyed counter
        std::cout << "Ship destroyed! Total ships destroyed: " << shipsDestroyed << "\n";
    }

    // Check if the frigate should upgrade to Corvette
    if (shouldUpgrade()) {
        upgradeToCorvette();
    }
}

void Frigate::upgradeToCorvette() {
    std::cout << "Frigate has destroyed " << shipsDestroyed << " ships and is now upgrading to Corvette!\n";
    // Update ship type and behavior (e.g., random shooting)
    this->setShipType("Corvette");
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