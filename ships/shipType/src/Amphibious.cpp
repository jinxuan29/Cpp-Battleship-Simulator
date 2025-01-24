#include "../include/Amphibious.h"
#include <iostream>

Amphibious::Amphibious() {};

Amphibious::Amphibious(const Position &position, int lives, int reviveCount,
                       int shipDestroyedCount, const std::string &shipName,
                       const std::string &shipType, const std::string &teamName,
                       bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed) {}

Amphibious::~Amphibious() { std::cout << "Amphibious Removed"; }

Amphibious::Amphibious(const Amphibious &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
  this->setTeamName(other.getTeamName());
  this->setIsDestroyed(other.getIsDestroyed());
}

Amphibious &Amphibious::operator=(const Amphibious &other) {
  if (this != &other) {
    this->setPosition(other.getPosition());
    this->setShipName(other.getShipName());
    this->setShipType(other.getShipType());
    this->setLives(other.getLives());
    this->setReviveCount(other.getReviveCount());
    this->setShipDestroyedCount(other.getShipDestroyedCount());
    this->setTeamName(other.getTeamName());
    this->setIsDestroyed(other.getIsDestroyed());
  }
  return *this;
}

void Amphibious::movingShip() { std::cout << "Amphibious move"; }

void Amphibious::shootingShip() { std::cout << "Amphibious shoot"; }

void Amphibious::seeingShip() { std::cout << "Amphibious seeing"; }

void Amphibious::runShip() { std::cout << "Amphibious running"; }

void Amphibious::upgradeShip() { std::cout << "Amphibious upgrading"; }