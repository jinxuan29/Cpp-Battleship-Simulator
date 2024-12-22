#pragma once
#ifndef SHIP_HPP
#define SHIP_HPP

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
    // Constructor and Destructor (optional for initialization and cleanup)
    Ship();
    ~Ship();

    // Position setters and getters
    void setPosition(int xPosition, int yPosition);
    void getPosition(int &xPosition, int &yPosition) const;

    // Lives setters and getters
    void setLives(int lives = 3);
    int getLives() const;

    // Revive count setters and getters
    void setReviveCount(int reviveCount);
    int getReviveCount() const;

    // Ship name setters and getters
    void setShipName(const std::string& shipName);
    std::string getShipName() const;

    // Ship type setters and getters
    void setShipType(const std::string& shipType);
    std::string getShipTypes() const;

    // Ship actions
    void movingShip() const;
    void shootingShip() const;
    void seeingRobot() const;
    void ramShip() const;
};

#endif // SHIP_HPP