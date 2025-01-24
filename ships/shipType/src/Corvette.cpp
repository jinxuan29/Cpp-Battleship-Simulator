#include "../include/Corvette.h"
#include <iostream>
#include <string>

Corvette::Corvette() { std::cout << "Corvette Created"; }

Corvette::Corvette(const Position &position, int lives, int reviveCount,
                   int shipDestroyedCount, const std::string &shipName,
                   const std::string &shipType, const std::string &teamName,
                   bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed) {}

Corvette::~Corvette() { std::cout << "Corvette Removed"; }

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

void Corvette::shootingShip() { std::cout << "Corvette shoot"; }

void Corvette::runShip() { std::cout << "Corvette running"; }

void Corvette::upgradeShip() { std::cout << "Corvette upgrading"; }