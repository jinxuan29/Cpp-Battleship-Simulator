/**********|**********|**********|
Program: Position.h

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



#pragma once

#include <cstddef>
class Position
{
private:
  int x;
  int y;
  bool isInitialized;

public:
  Position() : isInitialized(false) {};

  Position(const Position &other) : x(other.x), y(other.y), isInitialized(true) {};

  Position(int x, int y) : x(x), y(y), isInitialized(true) {};

  // copy constructor
  Position &operator=(const Position &other);

  // overwrite == operator to comparte position if its equal to each other
  bool operator==(const Position &other) const;

  // overwrite + operator to add x and y value of the position (return a new
  // position tho not sure if shld make it add into the first initial position)
  Position operator+(const Position &other) const;

  ~Position();

  // x and y valur of upleft
  Position UpLeft();

  // x and y value of up
  Position Up();

  // x and y value of upright
  Position UpRight();

  // x and y valur of left
  Position Left();

  // x and y valur of right
  Position Right();

  // x and y value of down left
  Position DownLeft();

  // x and y valur of donw
  Position Down();

  // x and y valur of downright
  Position DownRight();

  // get random position (up down left right)
  Position getRandomPositionFrom4Position();

  // get random position (up down left right upright upleft downright downleft)
  Position getRandomPositionFrom8Position();

  int getXValuePosition() const;

  int getYValuePosition() const;

  // priny x and y value of the position
  void printXYValue() const;
};