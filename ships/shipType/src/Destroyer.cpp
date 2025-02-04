#include "../include/Destroyer.h"
#include <iostream>
#include <string>

Destroyer::Destroyer() {}

Destroyer::Destroyer(const Position &position, int lives, int reviveCount,
                     int shipDestroyedCount, const std::string &shipName,
                     const std::string &shipType, const std::string &teamName,
                     bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed) {}

Destroyer::~Destroyer() { std::cout << "Destroyer Removed"; }

Destroyer::Destroyer(const Destroyer &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
}

Destroyer &Destroyer::operator=(const Destroyer &other) {
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

void Destroyer::movingShip(Battlefield &battlefield) { std::cout << "Destroyer move"; }

void Destroyer::shootingShip(Battlefield &battlefield) { std::cout << "Destroyer shoot"; }

void Destroyer::seeingShip(Battlefield &battlefield) { std::cout << "Destroyer see"; }

void Destroyer::ramShip(Battlefield &battlefield) { std::cout << "Destroyer ram"; }

void Destroyer::runShip(Battlefield &battlefield) { std::cout << "Destroyer running"; }

void Destroyer::upgradeShip() { std::cout << "Destroyer upgrading"; }