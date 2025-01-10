#include "Battlefield.h"
#include <string>

class GameManager {
private:
  std::string filename;
  Battlefield *battlefield;
  int interation;
  int width;
  int height;

  public:
  GameManager(std::string filename);
  void readFile(std::string filename);

};
