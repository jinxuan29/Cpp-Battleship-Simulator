#pragma once

#include <iostream>
#include <string>

class Ship {
private:
  int xPosition;
  int yPosition;
  int lives;
  int reviveCount;
  std::string shipName;
  std::string shipType;

public:
  // Position setters and getters
  void setXPosition(int xPosition);
  void setYPosition(int YPosition);
  int getXPosition() const;
  int getYPosition() const;

  // Lives setters and getters
  void setLives(int lives = 3);
  int getLives() const;

  // Revive count setters and getters
  void setReviveCount(int reviveCount);
  int getReviveCount() const;

  // Ship name setters and getters
  void setShipName(std::string shipName);
  std::string getShipName() const;

  // Ship type setters and getters
  void setShipType(std::string shipType);
  std::string getShipTypes() const;

  // Ship actions
  virtual void movingShip();
  virtual void shootingShip();
  virtual void seeingRobot();
  virtual void ramShip();
};
