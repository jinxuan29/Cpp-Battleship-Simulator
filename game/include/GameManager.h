#include "Battlefield.h"
#include <string>

class GameManager {
private:
  std::string filename;
  Battlefield
      *battlefield; // pointer for battlefield, to initialize battlefield and
                    // set the battlefield using the read file function
  char **battlefieldMap; // 2d array of the battlefield
  int **islandPosition; // 2d array of all coords of the island in battlefield
  std::string* teamName; //aray to store the teamname for each team
  Ship** teamShip; 
  int interation;
  int width;
  int height;

public:
  GameManager(std::string filename);
  ~GameManager();
  void readFile(std::string filename);
};
