#include "../include/Destroyer.h"
#include <iostream>
#include <string>

Destroyer::Destroyer(std::string shipName, int xPosition, int yPosition,
                     int lives, int reviveCount) {
  setShipName(shipName);
  setShipType("Destroyer");
  setXPosition(xPosition);
  setYPosition(yPosition);
  setLives(lives = 3);
  setReviveCount(reviveCount);
}

Destroyer::Destroyer() {};

//Destroyer::Destroyer(std::string name){
//    setShipName(name);
//}

Destroyer::Destroyer(const Destroyer &other) {
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipTypes());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setXPosition(other.getXPosition());
  this->setYPosition(other.getYPosition());
};

Destroyer &Destroyer::operator=(const Destroyer &other) {
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
};

void Destroyer::movingShip() { std::cout << "Destroyer move"; }

void Destroyer::shootingShip() { std::cout << "Destroyer shoot"; }

void Destroyer::seeingRobot() { std::cout << "Destroyer see"; }

void Destroyer::ramShip() { std::cout << "Destroyer ram"; }