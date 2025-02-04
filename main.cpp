#include "game/include/GameManager.h"

int main(){

  srand(time(0));

  GameManager gameManager1("game.txt");
  gameManager1.runGame();
  return 0;
}