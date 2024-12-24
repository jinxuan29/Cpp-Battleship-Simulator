#include "../include/Cruiser.h"
#include <iostream>

Cruiser::Cruiser() {};

Cruiser::Cruiser(std::string shipName,int xPosition, int yPosition, int lives, int reviveCount){ 
  setShipName(shipName);
  setShipType("Cruiser");
  setXPosition(xPosition);
  setYPosition(yPosition);
  setLives(lives = 3);
  setReviveCount(reviveCount);
  }

Cruiser::~Cruiser() {
  std::cout << "Cruiser Removed";
}

Cruiser::Cruiser(const Cruiser &other) {
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipTypes());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setXPosition(other.getXPosition());
  this->setYPosition(other.getYPosition());
}

Cruiser &Cruiser::operator=(const Cruiser &other) {
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

void Cruiser::movingShip(){
    std::cout << "Cruiser move";
}

void Cruiser::shootingShip() { std::cout << "Cruiser shoot"; }

void Cruiser::seeingRobot() { std::cout << "Cruiser see"; }

void Cruiser::ramShip() { std::cout << "Battleshhip ram"; }