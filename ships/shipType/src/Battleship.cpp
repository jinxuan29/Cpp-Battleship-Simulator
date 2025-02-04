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

void Battleship::seeingShip(Battlefield &battlefield) { std::cout << "Battleship see"; }

void Battleship::movingShip(Battlefield &battlefield) { std::cout << "BattleShip move"; }

void Battleship::shootingShip(Battlefield &battlefield) { std::cout << "Battleship shoot"; }

void Battleship::runShip(Battlefield &battlefield) { std::cout << "Battleship running"; }

void Battleship::upgradeShip() { std::cout << "Battleship upgrading"; }