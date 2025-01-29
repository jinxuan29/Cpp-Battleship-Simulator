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

Amphibious::Amphibious(const Amphibious &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
  this->setTeamName(other.getTeamName());
  this->setIsDestroyed(other.getIsDestroyed());
}

Amphibious &Amphibious::operator=(const Amphibious &other) {
  if (this != &other) {
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

// Move Function - Amphibious can move on both land and sea 
void Amphibious::movingShip() {
   std::cout << getShipName() << "is moving\n"; 

   Position newPos = getPosition();

     // Generate random movement direction (up, down, left, right)
    int direction = rand() % 4;
    switch (direction) {
        case 0: newPos.y -= 1; break; // Move up
        case 1: newPos.y += 1; break; // Move down
        case 2: newPos.x -= 1; break; // Move left
        case 3: newPos.x += 1; break; // Move right
    }

     // Check if new position is valid (not out of bounds)
    if (Battlefield::isValidPosition(newPos)) {
        setPosition(newPos);
        std::cout << getShipName() << " moved to (" << newPos.x << ", " << newPos.y << ")\n";
    } else {
        std::cout << getShipName() << " could not move\n";
    }
}


// Shooting Function - Random fire in 8 directions
void Amphibious::shootingShip() {
   std::cout << getShipName() << "is shooting\n";
   
   Position target = getPosition();
   int direction = rand() % 8;
   
   switch (direction){
           case 0: target.y -= 1; break; // Up
        case 1: target.y += 1; break; // Down
        case 2: target.x -= 1; break; // Left
        case 3: target.x += 1; break; // Right
        case 4: target.x -= 1; target.y -= 1; break; // Up Left
        case 5: target.x += 1; target.y -= 1; break; // Up Right
        case 6: target.x -= 1; target.y += 1; break; // Down Left
        case 7: target.x += 1; target.y += 1; break; // Down Right
   }

    if (Battlefield::isValidPosition(target)) {
        std::cout << getShipName() << " fires at (" << target.x << ", " << target.y << ")\n";
        // Implement logic to check if enemy ship is at this position and destroy it
    } else {
        std::cout << getShipName() << " missed the shot!\n";
    }
}
    
// Seeing Function - Amphibious scans a 3x3 area 
void Amphibious::seeingShip() {
   std::cout << getShipName()<< "is scanning surroundings\n"; 

   Position current getPosition();
   for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            Position checkPos = {current.x + dx, current.y + dy};
            if (Battlefield::isValidPosition(checkPos)) {
                std::cout << "Scanning (" << checkPos.x << ", " << checkPos.y << ")\n";
                // Implement logic to detect enemy ships
            }
        }
    }
}

// Run Function - Executes ship actions
void Amphibious::runShip() { 
  seeingShip();
  movingShip();
  shootingShip();
}
// Upgrade Function - Upgrade to SuperShip after 4 kills 
void Amphibious::upgradeShip() { 
  if (getShipDestroyedCount() >=4) {
    std::cout << getShipName() <<"has been upgraded to SuperShip!\n";
    // Conver this Amphibious object to SuperShip
    // This requires logif to replace the current instance in the simulation
  }
}