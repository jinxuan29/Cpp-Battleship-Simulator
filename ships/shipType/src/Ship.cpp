#include "../include/Ship.h"
#include <string>

Ship::Ship()
    : position(Position()), lives(3), reviveCount(0), shipDestroyedCount(0),
      shipName(""), shipType(""), teamName(""), isDestroyed(false), symbol('0') {}

Ship::Ship(const Position &position, int lives, int reviveCount,
           int shipDestroyedCount, const std::string &shipName,
           const std::string &shipType, const std::string &teamName,
           bool isDestroyed, char symbol)
    : position(position), lives(lives), reviveCount(reviveCount),
      shipDestroyedCount(shipDestroyedCount), shipName(shipName),
      shipType(shipType), teamName(teamName), isDestroyed(isDestroyed), symbol(symbol) {}

Ship::Ship(Ship &&other)
    : position(other.position), lives(other.lives),
      reviveCount(other.reviveCount), shipDestroyedCount(0),
      shipName(other.shipName), shipType(other.shipType),
      teamName(other.teamName), isDestroyed(other.isDestroyed) {};

Position Ship::getPosition() const { return position; }
void Ship::setPosition(const Position &position) { this->position = position; }
void Ship::setPosition(int x, int y) { this->position = Position(x, y); }

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
std::string Ship::getShipType() const { return shipType; }

void Ship::setIsDestroyed(bool isDestroyed) { this->isDestroyed = isDestroyed; }

bool Ship::getIsDestroyed() const { return isDestroyed; }

void Ship::setTeamName(std::string teamName) { this->teamName = teamName; }

std::string Ship::getTeamName() const { return teamName; }

void Ship::setSymbol(char symbol) { this->symbol = symbol; }

char Ship::getSymbol() const { return symbol; }