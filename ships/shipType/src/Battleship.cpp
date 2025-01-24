#include "../include/Battleship.h"
#include <iostream>

Battleship::Battleship() {};

Battleship::Battleship(const Position &position, int lives, int reviveCount,
                       int shipDestroyedCount, const std::string &shipName,
                       const std::string &shipType, const std::string &teamName,
                       bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed) {}

Battleship::~Battleship() { std::cout << "Battleship Removed"; }

Battleship::Battleship(const Battleship &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
}

Battleship &Battleship::operator=(const Battleship &other) {
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

void Battleship::seeingShip() { std::cout << "Battleship see"; }

void Battleship::movingShip() { std::cout << "BattleShip move"; }

void Battleship::shootingShip() { std::cout << "Battleship shoot"; }

void Battleship::runShip() {
  if (this->getPosition().getYValuePosition() != 0) {

    Position newPosition = this->getPosition() + Position().Up();
    this->setPosition(newPosition); 
  }
  this->setSymbol(']');  
  std::cout << "Battleship running";
}

void Battleship::upgradeShip() { std::cout << "Battleship upgrading"; }