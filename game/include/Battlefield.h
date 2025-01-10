#pragma once
#include "../../ships/shipType/include/Ship.h"

class Battlefield{
    private:
        int width;
        int height;
        char ** grid;
        Ship *** shipGrid;
    
    public:
        Battlefield(int w, int h);
        ~Battlefield();

        void display() const;
        void placeIsland(int x, int y, char symbol);
};