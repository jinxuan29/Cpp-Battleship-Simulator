#include "../include/SuperShip.h"
#include <iostream>
#include <string>

SuperShip::SuperShip(std::string shipName, int xPosition, int yPosition,
                     int lives, int reviveCount) {
  setShipName(shipName);
  setShipType("SuperShip");
  setXPosition(xPosition);
  setYPosition(yPosition);
  setLives(lives = 3);
  setReviveCount(reviveCount);
}

SuperShip::SuperShip() {};

//SuperShip::SuperShip(std::string name){
//    setShipName(name);
//}

SuperShip::SuperShip(const SuperShip &other) {
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipTypes());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setXPosition(other.getXPosition());
  this->setYPosition(other.getYPosition());
};

SuperShip &SuperShip::operator=(const SuperShip &other) {
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

void SuperShip::movingShip() { std::cout << "SuperShip move"; }

void SuperShip::shootingShip() { std::cout << "SuperShip shoot"; }

void SuperShip::seeingRobot() { std::cout << "SuperShip see"; }

void SuperShip::ramShip() { std::cout << "SuperShip ram"; }