#include "Battlefield.h"
#include <string>

class GameManager {
private:
  std::string filename;
  Battlefield *battlefield;
  char **battlefieldMap;
  int **islandPosition;
  int interation;
  int width;
  int height;

public:
  GameManager(std::string filename);
  ~GameManager();
  void readFile(std::string filename);
};
