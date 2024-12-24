#include "Ship.h"
#include <string>
class Amphibious : public Ship {

public:
  Amphibious();

  Amphibious(std::string shipName, int xPosition, int yPosition, int lives,
            int reviveCount);

  ~Amphibious();

  Amphibious(const Amphibious &other);

  Amphibious &operator=(const Amphibious &other);

  void movingShip() override;

  void shootingShip() override;

  void seeingRobot() override;

  void ramShip() override;
};