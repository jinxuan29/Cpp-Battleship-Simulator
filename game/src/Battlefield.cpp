#include "../include/Battlefield.h"

Battlefield::Battlefield(int width, int height) : width(width), height(height) {
  grid = new char *[height];
  for (int i = 0; i < height; i++) {
    grid[i] = new char[width];

    for(int j = 0; j<width; j++){
        grid[i][j] = '0';
    }
  }
}

void Battlefield::display() const {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                std::cout << grid[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

void Battlefield::placeIsland(int x, int y, char symbol){
  grid[x][y] = symbol;
  display();
}

Battlefield::~Battlefield() {
    for (int i = 0; i<height; i++) {
      delete[] grid[i];
    }
    delete[] grid;
    grid = nullptr;
}