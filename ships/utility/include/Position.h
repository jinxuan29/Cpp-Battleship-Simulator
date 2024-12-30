#pragma once

class Position{
    private:
        int x;
        int y; 

    public:
        Position(int x, int y) : x(x), y(y) {};
        
        bool operator=(const Position& other) const{
            return x == other.x && y==other.y;
        }

        Position operator+(const Position& other) const{
            return Position(x + other.x, y + other.y);
        }
};