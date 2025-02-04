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

Amphibious::Amphibious(const Amphibious &other)
{
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
  this->setTeamName(other.getTeamName());
  this->setIsDestroyed(other.getIsDestroyed());
}

Amphibious &Amphibious::operator=(const Amphibious &other)
{
  if (this != &other)
  {
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

// Shooting Function - Random fire in 8 directions
void Amphibious::shootingShip()
{
  std::cout << getShipName() << "is shooting\n";

  Position target = getPosition();
  int direction = rand() % 8;

  switch (direction)
  {
  case 0:
    target = target.Up(); // Up
    break;
  case 1:
    target = target.Down(); // Down
    break;
  case 2:
    target = target.Left(); // Left
    break;
  case 3:
    target = target.Right(); // Right
    break;
  case 4:
    target = target.UpLeft(); // Up Left
    break;
  case 5:
    target = target.UpRight(); // Up Right
    break;
  case 6:
    target = target.DownLeft(); // Down Left
    break;
  case 7:
    target = target.DownRight(); // Down Right
    break;
  }
  Battlefield battlefield(10, 10);

  // Check if new position is valid (not out of bounds)
  if (battlefield.isValidPosition(target.getXValuePosition(), target.getYValuePosition()))
  {

    std::cout << getShipName() << " moved to ("
              << target.getXValuePosition() << ", "
              << target.getYValuePosition() << ")\n";
  }
  else

  {
    std::cout << getShipName() << " missed the shot!\n";
  }
}

void Amphibious::seeingShip()
{
  std::cout << getShipName() << " is scanning surroundings\n";

  Position current = getPosition();
  Battlefield battlefield(10, 10); // Create an instance of Battlefield

  for (int dx = -1; dx <= 1; ++dx)
  {
    for (int dy = -1; dy <= 1; ++dy)
    {
      Position checkPos = {current.getXValuePosition() + dx, current.getYValuePosition() + dy}; // Fixed access error

      if (battlefield.isValidPosition(checkPos.getXValuePosition(), checkPos.getYValuePosition()))
      {
        std::cout << "Scanning (" << checkPos.getXValuePosition() << ", " << checkPos.getYValuePosition() << ")\n";
        // Implement logic to detect enemy ships
      }
    }
  }
}

void Amphibious::movingShip()
{
  std::cout << getShipName() << " is moving\n";

  Position newPos = getPosition();

  // Generate random movement direction (up, down, left, right)
  int direction = rand() % 4;
  switch (direction)
  {
  case 0:
    newPos = Position(newPos.getXValuePosition(), newPos.getYValuePosition() - 1); // Move up
    break;
  case 1:
    newPos = Position(newPos.getXValuePosition(), newPos.getYValuePosition() + 1); // Move down
    break;
  case 2:
    newPos = Position(newPos.getXValuePosition() - 1, newPos.getYValuePosition()); // Move left
    break;
  case 3:
    newPos = Position(newPos.getXValuePosition() + 1, newPos.getYValuePosition()); // Move right
    break;
  }

  Battlefield battlefield(10, 10);

  // Check if new position is valid (not out of bounds)
  if (battlefield.isValidPosition(newPos.getXValuePosition(), newPos.getYValuePosition()))
  {
    // Check if the ship is trying to move to a sea or land tile
    if (battlefield.checkTerrain(newPos.getXValuePosition(), newPos.getYValuePosition()))
    {
      // It's a sea tile, so the ship can move
      setPosition(newPos);
      std::cout << getShipName() << " moved to (" << newPos.getXValuePosition() << ", "
                << newPos.getYValuePosition() << ")\n";
    }
    else
    {
      // It's a land tile, ship cannot move to land
      std::cout << getShipName() << " could not move to (" << newPos.getXValuePosition() << ", "
                << newPos.getYValuePosition() << "), land is blocked.\n";
    }
  }
  else
  {
    // If the position is out of bounds
    std::cout << getShipName() << " could not move (out of bounds).\n";
  }
}

// Run Function - Executes ship actions
void Amphibious::runShip()
{
  seeingShip();
  movingShip();
  shootingShip();
}

// Upgrade Function - Upgrade to SuperShip after 4 kills
void Amphibious::upgradeShip()
{
  if (getShipDestroyedCount() >= 4)
  {
    std::cout << getShipName() << "has been upgraded to SuperShip!\n";
    // Conver this Amphibious object to SuperShip
    // This requires logif to replace the current instance in the simulation
  }
}
