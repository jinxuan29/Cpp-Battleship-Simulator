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
  // Get current position
  Position currentPos = this->getPosition();
  int currX = currentPos.getXValuePosition();
  int currY = currentPos.getYValuePosition();

  // Define the search area (3x3 grid)
  int startX = std::max(currX - 1, 0); // Ensure the search area stays within bounds
  int endX = std::min(currX + 1, battlefield.getWidth() - 1);
  int startY = std::max(currY - 1, 0);
  int endY = std::min(currY + 1, battlefield.getHeight() - 1);

  bool enemyFound = false;

  // Step 1: Search for enemy ship in the 3x3 grid
  for (int y = startY; y <= endY; ++y)
  {
    for (int x = startX; x <= endX; ++x)
    {
      if (battlefield.checkForEnemyShip(x, y))
      {
        // Move to the enemy ship's position (destroy it)
        battlefield.removeShipAtPosition(x, y); // Assuming you have a remove ship method
        this->setPosition(Position(x, y));
        std::cout << "Moving to destroy enemy at (" << x << ", " << y << ").\n";
        enemyFound = true;
        return; // Exit once the ship moves
      }
    }
  }

  // Step 2: If no enemy ship is found, move randomly within the grid
  if (!enemyFound)
  {
    // Randomly select a new position within the 3x3 grid
    int randomX = rand() % (endX - startX + 1) + startX;
    int randomY = rand() % (endY - startY + 1) + startY;

    // Move to the random position
    this->setPosition(Position(randomX, randomY));
    std::cout << "Moving to random position (" << randomX << ", " << randomY << ").\n";
  }
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

void SuperShip::ramShip(Battlefield &battlefield)

{
  // Get current position
  Position currentPos = this->getPosition();
  int currX = currentPos.getXValuePosition();
  int currY = currentPos.getYValuePosition();

  // Define the search area (3x3 grid) to check for enemy ships nearby
  int startX = std::max(currX - 1, 0);
  int endX = std::min(currX + 1, battlefield.getWidth() - 1);
  int startY = std::max(currY - 1, 0);
  int endY = std::min(currY + 1, battlefield.getHeight() - 1);

  bool enemyFound = false;

  // Step 1: Search for an enemy ship in the nearby grid (3x3 area)
  for (int y = startY; y <= endY; ++y)
  {
    for (int x = startX; x <= endX; ++x)
    {
      if (battlefield.checkForEnemyShip(x, y))
      {
        // If an enemy ship is found, ram it
        std::cout << "Ramming enemy at (" << x << ", " << y << ").\n";

        // Assuming the enemy ship is destroyed upon ramming
        battlefield.removeShipAtPosition(x, y);

        // Optionally, you can decrease lives of the ramming ship or implement damage
        // For now, just print a message
        this->setLives(this->getLives() - 1); // Decrease lives after ramming

        enemyFound = true;
        return; // Exit after ramming
      }
    }
  }

  // Step 2: If no enemy ship is found, print a message
  if (!enemyFound)
  {
    std::cout << "No enemy ship nearby to ram.\n";
  }
}

void SuperShip::upgradeShip()
{
  std::cout << "super ship unable to upgrade";
}