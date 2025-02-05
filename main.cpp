#include "game/include/GameManager.h"
#include "ships/shipType/include/Amphibious.h"
#include "ships/shipType/include/Ship.h"
#include "ships/shipType/include/SuperShip.h"
#include "utility/include/LinkList.h"
#include <ctime> // Include if using srand and time

int main() {
  srand(time(0));
  GameManager gameManager1("game.txt");
  gameManager1.runGame();  

  return 0;
}
