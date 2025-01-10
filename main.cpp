#include "game/include/GameManager.h"
#include "ships/shipType/include/Battleship.h"

int main(){
  GameManager gameManager1("game.txt");
  gameManager1.readFile("game.txt");
}