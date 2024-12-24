#include "../include/Battleship.h"
#include <iostream>

Battleship::Battleship() {};

Battleship::Battleship(std::string shipName,int xPosition, int yPosition, int lives, int reviveCount){ 
  setShipName(shipName);
  setShipType("Battleship");
  setXPosition(xPosition);
  setYPosition(yPosition);
  setLives(lives = 3);
  setReviveCount(reviveCount);
  }

Battleship::~Battleship() {
  std::cout << "Battleship Removed";
}

Battleship::Battleship(const Battleship &other) {
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipTypes());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setXPosition(other.getXPosition());
  this->setYPosition(other.getYPosition());
}

Battleship &Battleship::operator=(const Battleship &other) {
  if (this != &other) {
    this->setShipName(other.getShipName());
    this->setShipType(other.getShipTypes());
    this->setLives(other.getLives());
    this->setReviveCount(other.getReviveCount());
    this->setXPosition(other.getXPosition());
    this->setYPosition(other.getYPosition());
    return *this;
  }
  return *this;
}

void Battleship::movingShip(){
    std::cout << "BattleShip move";
}

void Battleship::shootingShip() { std::cout << "Battleship shoot"; }

void Battleship::seeingRobot() { std::cout << "Battleship see"; }

void Battleship::ramShip() { std::cout << "Battleshhip ram"; }