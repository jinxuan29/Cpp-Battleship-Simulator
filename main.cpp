#include "game/include/GameManager.h"
#include "ships/shipType/include/Ship.h"
#include "utility/include/Position.h"

int main()
{

  // GameManager gameManager1("game.txt");
  // gameManager1.runGame();

  Position position1(4, 6);
  Position position2(4, 6);
  if (position1 == position2)
  {
    std::cout << "equal";
  }
  // Position random = position1.getRandomPositionFrom4Position();
  // Position equal = random + position1;
  // std::cout << equal.getXValuePosition() << std::endl;
  // std::cout << equal.getYValuePosition() << std::endl;

  return 0;
}