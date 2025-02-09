/**********|**********|**********|
Program: SuperShip.cpp

Course: Object Oriented Programing and Data Structure
Trimester: 2410
Name: Yen Jin Xuan
ID: 242UC243R3
Lecture Section: TC
Tutorial Section: TT1L
Email: yen.jin.xuan@student.mmu.edu.my
Phone: 01633131910

Course: Object Oriented Programing and Data Structure
Trimester: 2410
Name: Nishant A/L Kesavan
ID: 241UC2407W
Lecture Section: TC1L
Tutorial Section: TT1L
Email: NISHANT.KESAVAN@student.mmu.edu.my
Phone: 019-8960477

Course: Object Oriented Programing and Data Structure
Trimester: 2410
Name: Raveen A/L PARAMASIWAM
ID: 241UC24180
Lecture Section: TC1L
Tutorial Section: TT1L
Email: RAVEEN.AL.PARAMASIWAM@student.mmu.edu.my
Phone: 017-6476584
**********|**********|**********/

#include "../include/SuperShip.h"
#include <iostream>

SuperShip::SuperShip() {}

SuperShip::SuperShip(const Position &position, int lives, int reviveCount,
                     int shipDestroyedCount, const std::string &shipName,
                     const std::string &shipType, const std::string &teamName,
                     bool isDestroyed, const char symbol)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed, symbol) {}

SuperShip::~SuperShip() { std::cout << "SuperShip Removed \n"; }

SuperShip::SuperShip(Ship &&other) : Ship(std::move(other))
{
  setShipType("SuperShip");
}

void SuperShip::shootingShip(Battlefield &battlefield)
{
  Logger logger;
  std::string message =
      getShipName() + " is preparing to shoot at 3 random locations.";
  logger.logEvent(message);
  std::cout << message << std::endl;

  Position currentPos = getPosition();

  // Shoot 3 random locations
  for (int i = 0; i < 3; i++)
  {
    Position targetPos =
        currentPos + Position().getRandomPositionFrom8Position();

    Ship *target = battlefield.checkForShip(targetPos.getXValuePosition(),
                                            targetPos.getYValuePosition());

    if (target && target->getTeamName() != getTeamName())
    {
      message = getShipName() + " has hit " + target->getShipName() + " at (" +
                std::to_string(targetPos.getXValuePosition()) + ", " +
                std::to_string(targetPos.getYValuePosition()) + ")";
      logger.logEvent(message);
      std::cout << message << std::endl;

      target->setIsDestroyed(true);
      setShipDestroyedCount(getShipDestroyedCount() + 1);
    }
    else
    {
      message = getShipName() + " missed at (" +
                std::to_string(targetPos.getXValuePosition()) + ", " +
                std::to_string(targetPos.getYValuePosition()) + ")";
      logger.logEvent(message);
      std::cout << message << std::endl;
    }
  }
}

Ship *SuperShip::seeingShip(Battlefield &battlefield)
{
  Logger logger;
  std::string message = getShipName() + " is scanning for enemy ships.";
  logger.logEvent(message);
  std::cout << message << std::endl;

  Position currentPos = getPosition();

  // Scan 3x3 area
  for (int dx = -1; dx <= 1; dx++)
  {
    for (int dy = -1; dy <= 1; dy++)
    {
      int newX = currentPos.getXValuePosition() + dx;
      int newY = currentPos.getYValuePosition() + dy;

      if (battlefield.isValidPosition(newX, newY) &&
          !battlefield.isIsland(newX, newY))
      {
        Ship *enemy = battlefield.checkForShip(newX, newY);
        if (enemy && enemy->getTeamName() != this->getTeamName())
        {
          message =
              getShipName() + " spotted enemy ship: " + enemy->getShipName();
          logger.logEvent(message);
          std::cout << message << std::endl;
          return enemy;
        }
      }
    }
  }
  message = getShipName() + " found no enemies nearby.";
  logger.logEvent(message);
  std::cout << message << std::endl;
  return nullptr;
}

void SuperShip::runShip(Battlefield &battlefield)
{
  std::cout << getShipName() << " is running!\n";
  ramShip(battlefield);
  shootingShip(battlefield);
}

void SuperShip::ramShip(Battlefield &battlefield)
{
  Logger logger;
  std::string message = getShipName() + " is preparing to ram.";
  logger.logEvent(message);
  std::cout << message << std::endl;

  Ship *target = seeingShip(battlefield);
  Position currentPos = getPosition();
  Position bestMove = currentPos;

  if (target)
  {
    bestMove = target->getPosition();

    target->setIsDestroyed(true);
    this->setShipDestroyedCount(this->getShipDestroyedCount() + 1);

    message = getShipName() + " has rammed " + target->getShipName() + "!";
    logger.logEvent(message);
    std::cout << message << std::endl;
  }
  else
  {
    bool moved = false;
    for (int dx = -1; dx <= 1 && !moved; dx++)
    {
      for (int dy = -1; dy <= 1 && !moved; dy++)
      {
        int newX = currentPos.getXValuePosition() + dx;
        int newY = currentPos.getYValuePosition() + dy;

        if (battlefield.isValidPosition(newX, newY) &&
            !battlefield.isIsland(newX, newY) &&
            !battlefield.checkForShip(newX, newY))
        {
          bestMove = Position(newX, newY);
          moved = true;
        }
      }
    }

    if (!moved)
    {
      message = getShipName() + " is trapped and cannot move.";
      logger.logEvent(message);
      std::cout << message << std::endl;
      return;
    }
  }

  setPosition(bestMove);
  message = getShipName() + " moved to (" +
            std::to_string(bestMove.getXValuePosition()) + ", " +
            std::to_string(bestMove.getYValuePosition()) + ")";
  logger.logEvent(message);
  std::cout << message << std::endl;
}

Ship *SuperShip::upgradeShip()
{
  std::cout << "Unable to Upgrade Anymore";
  return nullptr;
}