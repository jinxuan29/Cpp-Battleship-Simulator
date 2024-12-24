#include "../include/Amphibious.h"
#include <iostream>

Amphibious::Amphibious() {};

Amphibious::Amphibious(std::string shipName,int xPosition, int yPosition, int lives, int reviveCount){ 
  setShipName(shipName);
  setShipType("Amphibious");
  setXPosition(xPosition);
  setYPosition(yPosition);
  setLives(lives = 3);
  setReviveCount(reviveCount);
  }

Amphibious::~Amphibious() {
  std::cout << "Amphibious Removed";
}

Amphibious::Amphibious(const Amphibious &other) {
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipTypes());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setXPosition(other.getXPosition());
  this->setYPosition(other.getYPosition());
}

Amphibious &Amphibious::operator=(const Amphibious &other) {
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

void Amphibious::movingShip(){
    std::cout << "Amphibious move";
}

void Amphibious::shootingShip() { std::cout << "Amphibious shoot"; }

void Amphibious::seeingRobot() { std::cout << "Amphibious see"; }

void Amphibious::ramShip() { std::cout << "Battleshhip ram"; }