#include "../include/Ship.h"
#include <string>

// Position setters and getters
void Ship::setXPosition(int xPosition) { this->xPosition = xPosition; }

void Ship::setYPosition(int yPosition) { this->yPosition = yPosition; }

int Ship::getXPosition() const { return this->xPosition; }

int Ship::getYPosition() const { return this->yPosition; }

// Lives setters and getters
void Ship::setLives(int lives) { this->lives = lives; }
int Ship::getLives() const { return lives; }

// Revive count setters and getters
void Ship::setReviveCount(int reviveCount) { this->reviveCount = reviveCount; }
int Ship::getReviveCount() const { return reviveCount; }

// Ship name setters and getters
void Ship::setShipName(std::string shipName) { this->shipName = shipName; }
std::string Ship::getShipName() const { return shipName; }

// Ship type setters and getters
void Ship::setShipType(std::string shipType) { this->shipType = shipType; }
std::string Ship::getShipTypes() const { return shipType; }

// Ship actions
void Ship::movingShip() { std::cout << "ship moving"; }
void Ship::shootingShip() { std::cout << "ship shooting"; }
void Ship::seeingRobot()  { std::cout << "ship seeing"; }
void Ship::ramShip()  { std::cout << "ship ramming"; }
