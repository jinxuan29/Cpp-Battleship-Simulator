#include "../include/Frigate.h"
#include <iostream>
#include <string>

Frigate::Frigate(){}

Frigate::Frigate(const Position &position, int lives, int reviveCount,
                 int shipDestroyedCount, const std::string &shipName,
                 const std::string &shipType, const std::string &teamName,
                 bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed) {}

Frigate::~Frigate() { std::cout << "Frigate Removed"; }

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

void Frigate::shootingShip() { std::cout << "Frigate shoot"; }

void Frigate::ramShip() { std::cout << "Frigate ram"; }

void Frigate::runShip() { std::cout << "Frigate running"; }

void Frigate::upgradeShip() { std::cout << "Frigate upgrading"; }