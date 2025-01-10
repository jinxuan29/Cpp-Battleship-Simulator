#pragma once

class Position {
private:
  int x;
  int y;

public:
  Position(int x, int y) : x(x), y(y) {};

  bool operator=(const Position &other) const;

  Position operator+(const Position &other) const;

  ~Position();

  Position UpLeft();

  Position Up();

  Position UpRight();

  Position Left();

  Position Right();

  Position DownLeft();

  Position Down();

  Position DownRight();

  Position getRandomPositionFrom4Position();

  Position getRandomPositionFrom8Position();

  int getXValuePosition();

  int getYValuePosition();
};