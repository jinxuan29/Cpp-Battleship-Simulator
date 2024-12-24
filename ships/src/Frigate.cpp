#include "../include/Frigate.h"
#include <iostream>
#include <string>

Frigate::Frigate(std::string shipName, int xPosition, int yPosition,
                     int lives, int reviveCount) {
  setShipName(shipName);
  setShipType("Frigate");
  setXPosition(xPosition);
  setYPosition(yPosition);
  setLives(lives = 3);
  setReviveCount(reviveCount);
}

Frigate::Frigate() {};

//Frigate::Frigate(std::string name){
//    setShipName(name);
//}

Frigate::Frigate(const Frigate &other) {
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipTypes());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setXPosition(other.getXPosition());
  this->setYPosition(other.getYPosition());
};

Frigate &Frigate::operator=(const Frigate &other) {
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

void Frigate::movingShip() { std::cout << "Frigate move"; }

void Frigate::shootingShip() { std::cout << "Frigate shoot"; }

void Frigate::seeingRobot() { std::cout << "Frigate see"; }

void Frigate::ramShip() { std::cout << "Frigate ram"; }