/**********|**********|**********|
Program: Team.h

Course: Object Oriented Programing and Data Structure 
Trimester: 2410
Name: Yen Jin Xuan
ID: 242UC243R3
Lecture Section: TC
Tutorial Section: TT1L
Email: yen.jin.xuan@student.mmu.edu.my
Phone: 01633131910

Course: Object Oriented Programing and Data Structure 
Trimester: 2410
Name: Nishant A/L Kesavan 
ID: 241UC2407W
Lecture Section: TC1L
Tutorial Section: TT1L
Email: NISHANT.KESAVAN@student.mmu.edu.my
Phone: 019-8960477

Course: Object Oriented Programing and Data Structure 
Trimester: 2410
Name: Raveen A/L PARAMASIWAM 
ID: 241UC24180
Lecture Section: TC1L
Tutorial Section: TT1L
Email: RAVEEN.AL.PARAMASIWAM@student.mmu.edu.my
Phone: 017-6476584
**********|**********|**********/


#pragma once
#include <string>
#include "../../ships/shipType/include/Ship.h"
#include "../../utility/include/Logger.h"

class Team
{
private:
    std::string teamName;
    Ship **teamShips;
    int numShip;

public:
    Team();
    Team(std::string teamName);
    ~Team();

    void setTeamShipsArraySize(int numship); // set the array for the ships of a team
    Ship **getTeamShipsArray() const;        // retur the array
    int getNumShip() const;                  // total number of ship inside teamShipArray
    void addShip(Ship *ship);                // add shihp into the array
    std::string getName() const;             // get team name
    void displayTeamShips() const;           // diplay the ship inside each team
};