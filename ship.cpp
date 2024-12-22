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
  void setPosition(int xPosition, int yPosition) {
    this->xPosition = xPosition;
    this->yPosition = yPosition;
  }

  void getPosition(int &xPosition, int &yPosition) {
    xPosition = this->xPosition;
    yPosition = this->yPosition;
  }

  void setLives(int lives = 3) { this->lives = lives; }

  int getLives() { return lives; }

  void setReviveCount(int reviveCount) { this->reviveCount = reviveCount; }

  int getReviveCount() { return reviveCount; }

  void setShipName(std::string shipName) { this->shipName = shipName; }

  std::string getShipName() { return shipName; }

  void setShipType(std::string shipType) { this->shipType = shipType; }

  std::string getShipTypes() { return shipType; }

  void movingShip(){
    std::cout << "ship moving";
  }

  void shootingShip(){
    std::cout << "ship shooting";
  }

  void seeingRobot(){
    std::cout << "ship seeing";
  }

  void ramShip(){
    std::cout << "ship ramming";
  }
};