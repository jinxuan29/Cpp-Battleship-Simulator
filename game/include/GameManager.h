#include "Battlefield.h"
#include "Team.h"
#include <string>

class GameManager {
private:
  std::string filename;
  //Battlefiled class related 
  Battlefield
      *battlefield; // pointer for battlefield, to initialize battlefield and
                    // set the battlefield using the read file function
  char **battlefieldMap; // 2d array of the battlefield
 
   // Team class related 
  Team** teams;
  std::string* teamName; //aray to store the teamname for each team
  int* teamNumTypeShip; // array to store the total type of ship each teams has. (index the same way as teamname)
  std::string** numberOfPerShip; // 2d array to store number of each type of ship each teams has . 

  // Settings 
  int iteration; // number of rounds to run the battlefield simulation
  int width; // width of battlfield  (columns)
  int height; // height of battlefield (rows)
  int numberOfTeams; //total number of teams from the txt file

public:
  GameManager(std::string filename);
  ~GameManager();
  void readFile(std::string filename);
  void runGame();
};
