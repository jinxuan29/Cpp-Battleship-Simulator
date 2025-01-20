#include <string>
#include "../../ships/shipType/include/Ship.h"
class Team{
    private:
        std::string teamName;
        Ship** teamShips;
        int numShip;
    public:
        Team(); 
        Team(std::string teamName);
        ~Team();

        void setTeamShipsArraySize(int numship); // set the array for the ships of a team
        Ship** getTeamShipsArray() const; // retur the array
        int getNumShip() const; // total number of ship inside teamShipArray
        void addShip(Ship* ship); // add shihp into the array
        void getName() const; // get team name
        void displayTeamShips() const; // diplay the ship inside each team
};