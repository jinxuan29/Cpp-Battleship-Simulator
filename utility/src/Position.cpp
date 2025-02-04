#include "../include/Position.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

bool Position::operator==(const Position &other) const {
  return x == other.x && y == other.y;
}

Position Position::operator+(const Position &other) const {
  return Position(x + other.x, y + other.y);
}

Position &Position::operator=(const Position &other) {
  if (this != &other) { // Check for self-assignment
    x = other.x;
    y = other.y;
    isInitialized = true;
  }
  return *this;
}

Position::~Position() {};

Position Position::Up() { return Position(0, -1); }

Position Position::Down() { return Position(0, +1); }

Position Position::Left() { return Position(-1, 0); }

Position Position::Right() { return Position(1, 0); }

Position Position::UpLeft() { return Position(-1, -1); }

Position Position::UpRight() { return Position(1, -1); }
Position Position::DownLeft() { return Position(-1, 1); }
Position Position::DownRight() { return Position(1, 1); }

// geneerate random UP DOWN LEFT OR RIGHT POSITION using //srand
Position Position::getRandomPositionFrom4Position() {
  ////srand(time(0));
  int randomDirection = rand() % 4;
  switch (randomDirection) {
  case 0:
    return Position::Up();
  case 1:
    return Position::Down();
  case 2:
    return Position::Left();
  case 3:
    return Position::Right();
  }
  std::cout << "Error This should no happen idk whats wrong, position "
               "getRandomPositionFrom4Position";
  return Position(0, 0);
};

// geneerate random UP DOWN LEFT RIGHT UPLEFT UPRIGHT DOWNLEFT DOWNRIGHT
// POSITION using //srand
Position Position::getRandomPositionFrom8Position() {
  // srand(time(0));
  int randomDirection = rand() % 8;
  switch (randomDirection) {
  case 0:
    return Position::Up();
  case 1:
    return Position::Down();
  case 2:
    return Position::Left();
  case 3:
    return Position::Right();
  case 4:
    return Position::UpLeft();
  case 5:
    return Position::UpRight();
  case 6:
    return Position::DownRight();
  case 7:
    return Position::DownLeft();
  }
  throw std::runtime_error(
      "Error This should no happen idk whats wrong, position "
      "getRandomPositionFrom8Position");
};

int Position::getXValuePosition() const {
  if (this->isInitialized) {
    return x;
  } else {
    throw std::runtime_error("Position does not have X Value");
  }
}
int Position::getYValuePosition() const {
  if (this->isInitialized) {
    return y;
  } else {
    throw std::runtime_error("Position does not have Y value");
  }
}

void Position::printXYValue() const {
  if (this->isInitialized) {
    std::cout << this->x << " " << this->y;
  } else {
    std::cout << "Position does not have X and Y value";
  }
}