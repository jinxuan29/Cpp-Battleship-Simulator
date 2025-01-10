#pragma once

#include "../../../utility/include/Position.h"
#include <iostream>

class Ship {
private:
  Position position;
  int lives;
  int reviveCount;
  int shipDestroyedCount;
  std::string shipName;
  std::string shipType;
  std::string teamName;
  bool isDestroyed;

public:
  Ship();

  Ship(const Position &position, int lives, int reviveCount,
       int shipDestroyedCount, const std::string &shipName,
       const std::string &shipType, const std::string &teamName,
       bool isDestroyed);

  virtual ~Ship() = default;

  void setPosition(const Position &positiion);
  Position getPosition() const;

  void setLives(int lives = 3);
  int getLives() const;

  void setReviveCount(int reviveCount);
  int getReviveCount() const;

  void setShipDestroyedCount(int shipDestroyedCount = 0);
  int getShipDestroyedCount() const;

  void setShipName(std::string shipName);
  std::string getShipName() const;

  void setShipType(std::string shipType);
  std::string getShipTypes() const;

  void setTeamName(std::string teamName);
  std::string getTeamName() const;

  void setIsDestroyed(bool isDestroyed = false);
  bool getIsDestroyed() const;

  //virtual void runShip() = 0; // run ship set of action.
  //virtual Ship upgradeShip()=0; // unsure to put it here ot battlefield class
};
