#include "../include/Frigate.h"
#include <iostream>
#include <string>

Frigate::Frigate() : shotsFired(0), shipsDestroyed(0) {}

Frigate::Frigate(const Position &position, int lives, int reviveCount,
                 int shipDestroyedCount, const std::string &shipName,
                 const std::string &shipType, const std::string &teamName,
                 bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed), shotsFired(0), shipsDestroyed(0) {}

Frigate::~Frigate() { std::cout << "Frigate Removed\n"; }

Frigate::Frigate(const Frigate &other) : Ship(other) {
    this->shotsFired = other.shotsFired;
    this->shipsDestroyed = other.shipsDestroyed;
}

Frigate &Frigate::operator=(const Frigate &other) {
    if (this != &other) {
        Ship::operator=(other);
        this->shotsFired = other.shotsFired;
        this->shipsDestroyed = other.shipsDestroyed;
    }
    return *this;
}

void Frigate::shootingShip() {
    Position target = getNextTargetPosition();
    std::cout << "Frigate shooting at position: (" << target.x << ", " << target.y << ")\n";

    // Simulate shooting logic (e.g., check if target is a ship, destroy it, etc.)
    // If a ship is destroyed, increment shipsDestroyed
    shipsDestroyed++;

    // Check if the frigate should upgrade to Corvette
    if (shouldUpgrade()) {
        upgradeToCorvette();
    }
}

void Frigate::upgradeToCorvette() {
    std::cout << "Frigate upgraded to Corvette!\n";
    // Update ship type and behavior (e.g., random shooting)
    this->setShipType("Corvette");
}

Position Frigate::getNextTargetPosition() {
    // Calculate the next target position based on the shooting sequence
    Position target = shootingSequence[shotsFired % 8];
    shotsFired++;
    return Position(this->getPosition().x + target.x, this->getPosition().y + target.y);
}

bool Frigate::shouldUpgrade() const {
    return shipsDestroyed >= UPGRADE_THRESHOLD;
}