#include "../include/SuperShip.h"
#include <iostream>

SuperShip::SuperShip() {}

SuperShip::SuperShip(const Position &position, int lives, int reviveCount,
                     int shipDestroyedCount, const std::string &shipName,
                     const std::string &shipType, const std::string &teamName,
                     bool isDestroyed)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed) {}

SuperShip::~SuperShip() { std::cout << "SuperShip Removed"; }

SuperShip::SuperShip(const SuperShip &other)
{
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
}

SuperShip &SuperShip::operator=(const SuperShip &other)
{
  if (this != &other)
  {
    this->setPosition(other.getPosition());
    this->setShipName(other.getShipName());
    this->setShipType(other.getShipType());
    this->setLives(other.getLives());
    this->setReviveCount(other.getReviveCount());
    this->setShipDestroyedCount(other.getShipDestroyedCount());
  }
  return *this;
}

void SuperShip::movingShip(Battlefield &battlefield)
{
  std::cout << "move Ship";
}

void SuperShip::shootingShip(Battlefield &battlefield)
{
  std::cout << getShipName() << " is shooting at 3 random positions!\n";

  for (int i = 0; i < 3; i++)
  {
    // Generate random offsets in the range [-5,5]
    int randomX = (rand() % 11) - 5;
    int randomY = (rand() % 11) - 5;

    // Get the target position using the current position and the random offsets
    Position targetPos(getPosition().getXValuePosition() + randomX,
                       getPosition().getYValuePosition() + randomY);

    // Call the helper function to shoot at the target position
    if (shootAt(targetPos))
    {
      std::cout << "Hit at (" << targetPos.getXValuePosition() << ", "
                << targetPos.getYValuePosition() << ")!\n";
    }
    else
    {
      std::cout << "Missed at (" << targetPos.getXValuePosition() << ", "
                << targetPos.getYValuePosition() << ").\n";
    }
  }
}

void SuperShip::seeingShip(Battlefield &battlefield)
{
  std::cout << getShipName() << " is seeing!\n";
}

void SuperShip::runShip(Battlefield &battlefield)
{
  std::cout << getShipName() << " is running!\n";
}

bool SuperShip::shootAt(const Position &pos)
{
  return true;
}
