#include "../include/Ship.h"
#include <string>

Ship::Ship(const Position& position, int lives, int reviveCount, int shipDestroyedCount,
           const std::string& shipName, const std::string& shipType,
           const std::string& teamName, bool isDestroyed)
    : position(position), lives(lives), reviveCount(reviveCount),
      shipDestroyedCount(shipDestroyedCount), shipName(shipName),
      shipType(shipType), teamName(teamName), isDestroyed(isDestroyed) {}

Position Ship::getPosition() const { return position; }
void Ship::setPosition(const Position &position) { this->position = position; }

void Ship::setLives(int lives) { this->lives = lives; }
int Ship::getLives() const { return lives; }

void Ship::setReviveCount(int reviveCount) { this->reviveCount = reviveCount; }
int Ship::getReviveCount() const { return reviveCount; }

void Ship::setShipDestroyedCount(int shipDestroyedCount) {
  this->shipDestroyedCount = shipDestroyedCount;
}

int Ship::getShipDestroyedCount() const { return shipDestroyedCount; }

void Ship::setShipName(std::string shipName) { this->shipName = shipName; }
std::string Ship::getShipName() const { return shipName; }

void Ship::setShipType(std::string shipType) { this->shipType = shipType; }
std::string Ship::getShipTypes() const { return shipType; }

void Ship::setIsDestroyed(bool isDestroyed) { this->isDestroyed = isDestroyed; }

bool Ship::getIsDestroyed() const { return isDestroyed; }
