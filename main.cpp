#include "game/include/GameManager.h"
#include <iostream>

int main(){

  GameManager gameManager1("game.txt");
  gameManager1.runGame();

  std::cout << "end";
  return 0;
}