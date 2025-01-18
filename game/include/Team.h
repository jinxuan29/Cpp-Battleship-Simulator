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

        void setTeamShipsArraySize(int numship);
        void addShip(Ship* ship);
        void getName();
        void displayTeamShips();
};