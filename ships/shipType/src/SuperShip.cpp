#include "../include/SuperShip.h"
#include <iostream>

SuperShip::SuperShip() {};

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
  this->setShipType(other.getShipTypes());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
}

SuperShip &SuperShip::operator=(const SuperShip &other) {
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

void SuperShip::movingShip() { std::cout << "SuperShip move"; }

void SuperShip::seeingShip() { std::cout << "SuperShip see"; }

void SuperShip::ramShip() { std::cout << "SuperShip ram"; }

void SuperShip::shootingShip() { std::cout << "SuperShip shoot"; }

void SuperShip::runShip() { std::cout << "SuperShip running"; }

void SuperShip::upgradeShip() { std::cout << "SuperShip upgrading"; }