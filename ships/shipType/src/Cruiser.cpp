#include "../include/Cruiser.h"
#include <iostream>

Cruiser::Cruiser() {};

Cruiser::Cruiser(const Position &position, int lives, int reviveCount,
                 int shipDestroyedCount, const std::string &shipName,
                 const std::string &shipType, const std::string &teamName,
                 bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed) {}

Cruiser::~Cruiser() { std::cout << "Cruiser Removed"; }

Cruiser::Cruiser(const Cruiser &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
}

Cruiser &Cruiser::operator=(const Cruiser &other) {
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

void Cruiser::movingShip() { std::cout << "Cruiser move"; }
void Cruiser::seeingShip() { std::cout << "Cruiser see"; }

void Cruiser::ramShip() { std::cout << "Cruiser ram"; }

void Cruiser::runShip() { std::cout << "Cruiser running"; }

void Cruiser::upgradeShip() { std::cout << "Cruiser upgrading"; }