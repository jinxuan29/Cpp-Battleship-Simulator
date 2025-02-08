#include "game/include/GameManager.h"
#include <ctime> // Include if using srand and time
#include <fstream> // For file handling

#include <ctime> // Include if using srand and time

int main() {

  std::ofstream logFile("log.txt", std::ios::out | std::ios::trunc);
    if (!logFile) {
        std::cerr << "Error: Could not open or create log.txt for clearing.\n";
    } else {
        logFile.close(); 
    }

  srand(time(0));
  GameManager gameManager1("game.txt");
  gameManager1.runGame();

  return 0;
}
