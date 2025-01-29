#include "../include/SuperShip.h"
#include <iostream>

SuperShip::SuperShip() {}

SuperShip::SuperShip(const Position &position, int lives, int reviveCount,
                     int shipDestroyedCount, const std::string &shipName,
                     const std::string &shipType, const std::string &teamName,
                     bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed) {}

SuperShip::~SuperShip() { std::cout << "SuperShip Removed"; }

SuperShip::SuperShip(const SuperShip &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
}

SuperShip &SuperShip::operator=(const SuperShip &other) {
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

void SuperShip::movingShip() { 
    std::cout << "SuperShip move"; 
}

void SuperShip::shootingShip() { 
    std::cout << "SuperShip shoot"; 
}

void SuperShip::seeingShip() { 
    std::cout << "SuperShip seeing"; 
}

void SuperShip::runShip() { 
    std::cout << "SuperShip running"; 
}

// ADDED: SuperShip shoots at **three** random locations per turn
void SuperShip::shootingShip() {
    std::cout << "SuperShip shoots at 3 random positions!" << std::endl;
    
    for (int i = 0; i < 3; i++) {
        int randomX = (rand() % 10) - 5; // Random offset in range [-5,5]
        int randomY = (rand() % 10) - 5; // Random offset in range [-5,5]
        Position targetPos = {getPosition().x + randomX, getPosition().y + randomY};
        shootAt(targetPos); // Call helper function
    }
}