#include "Ship.h"
#include <string>
class Corvette : public Ship {

public:
  Corvette();

  Corvette(std::string shipName, int xPosition, int yPosition, int lives,
            int reviveCount);

  ~Corvette();

  Corvette(const Corvette &other);

  Corvette &operator=(const Corvette &other);

  void movingShip() override;

  void shootingShip() override;

  void seeingRobot() override;

  void ramShip() override;
};