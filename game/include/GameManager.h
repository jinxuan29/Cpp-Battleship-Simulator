#include "../../ships/shipType/include//Ship.h"
#include "../../ships/shipType/include//SuperShip.h"
#include "../../ships/shipType/include/Amphibious.h"
#include "../../ships/shipType/include/Battleship.h"
#include "../../ships/shipType/include/Corvette.h"
#include "../../ships/shipType/include/Cruiser.h"
#include "../../ships/shipType/include/Destroyer.h"
#include "../../ships/shipType/include/Frigate.h"
#include "../../utility/include/LinkList.h"
#include "../../utility/include/Queue.h"
#include "Battlefield.h"
#include "Team.h"
#include <string>

class GameManager {
private:
  std::string filename;
  Ship **allShips;
  int totalShipsAcrossAllTeams;

  // Battlefiled class related
  Battlefield
      *battlefield; // pointer for battlefield, to initialize battlefield and
                    // set the battlefield using the read file function
  char **battlefieldMap; // 2d array of the battlefield

  // Team class related
  Team **teams;
  std::string *teamName; // aray to store the teamname for each team
  int *teamNumTypeShip; // array to store the total type of ship each teams has.
                        // (index the same way as teamname)
  std::string **numberOfPerShip; // 2d array to store number of each type of
                                 // ship each teams has .

  // Settings
  int iteration;     // number of rounds to run the battlefield simulation
  int width;         // width of battlfield  (columns)
  int height;        // height of battlefield (rows)
  int numberOfTeams; // total number of teams from the txt file

  // Link List
  LinkList<Ship *>
      shipActivityLinkList; // link list to keep track of which ship goes next

  // Queue
  Queue<Ship *> shipRespawnQueue; // Queue to keep track of ship respawn

public:
  GameManager(std::string filename);
  ~GameManager();
  void readFile(std::string filename);
  void addShipToActivityLinkList();
  // void displayShipActivityLinkList() const;
  void runGame();                       // function to run the stimulation
  void addDestroyedShipIntoQueue();     // add destroyed ship into queue
  void removeDestroyShipFromLinkList(); // remove destroyed ship into link list
  void respawnShip(Battlefield &baattlefield); // respawn ship function (auto check for if ship are
                      // destroyed and add back into the linked list)
};
