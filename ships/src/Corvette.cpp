#include "../include/Corvette.h"
#include <iostream>
#include <string>

Corvette::Corvette(std::string shipName, int xPosition, int yPosition,
                     int lives, int reviveCount) {
  setShipName(shipName);
  setShipType("Corvette");
  setXPosition(xPosition);
  setYPosition(yPosition);
  setLives(lives = 3);
  setReviveCount(reviveCount);
}

Corvette::Corvette() {};

//Corvette::Corvette(std::string name){
//    setShipName(name);
//}

Corvette::Corvette(const Corvette &other) {
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipTypes());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setXPosition(other.getXPosition());
  this->setYPosition(other.getYPosition());
};

Corvette &Corvette::operator=(const Corvette &other) {
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

void Corvette::movingShip() { std::cout << "Corvette move"; }

void Corvette::shootingShip() { std::cout << "Corvette shoot"; }

void Corvette::seeingRobot() { std::cout << "Corvette see"; }

void Corvette::ramShip() { std::cout << "Corvette ram"; }