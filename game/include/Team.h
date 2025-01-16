#include <string>
#include "../../ships/shipType/include/Ship.h"
class Team{
    private:
        std::string teamName;
        Ship** teamShips;
        int nummShip;
    public:
        Team(); 
        Team(std::string teamName, int nummShip);
        ~Team();

        void addShip(Ship* ship);
        void getName();
};