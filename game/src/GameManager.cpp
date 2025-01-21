#include "../include/GameManager.h"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

GameManager::GameManager(std::string filename) { this->filename = filename; }
// TODO
//  create link list (ship activity queue), create queue (respawn queue),
// store ship into queue and linked list
// bad code on link list
void GameManager::readFile(std::string filename)
{
  this->width = 0;
  this->height = 0;

  std::ifstream file(filename);
  if (!file.is_open())
  {
    std::cerr << "Failed to open the file: " << filename << "\n";
    return;
  }

  int lineCount = 0;
  std::string tempLine;
  while (std::getline(file, tempLine))
  {
    lineCount++;
  }
  file.clear();
  file.seekg(0, std::ios::beg);

  // Allocate memory for storing lines
  std::string *lines = new std::string[lineCount];

  // Read lines into the dynamic array
  int index = 0;
  while (std::getline(file, tempLine))
  {
    lines[index++] = tempLine;
  }
  file.close();

  this->numberOfTeams = 0;

  for (int i = 0; i < lineCount; i++)
  {
    if (lines[i].find("iteration") != std::string::npos)
    {
      size_t pos = lines[i].find(" ");
      this->iteration = std::stoi(lines[i].substr(pos + 1));
    }
    if (lines[i].find("width") != std::string::npos)
    {
      size_t pos = lines[i].find(" ");
      this->width = std::stoi(lines[i].substr(pos + 1));
    }
    if (lines[i].find("height") != std::string::npos)
    {
      size_t pos = lines[i].find(" ");
      this->height = std::stoi(lines[i].substr(pos + 1));
    }
    if (lines[i].find("Team") != std::string::npos)
    {
      this->numberOfTeams++;
    }
  }

  // Team Variable
  this->teamName = new std::string[numberOfTeams];
  this->teamNumTypeShip = new int[numberOfTeams];
  this->numberOfPerShip = new std::string *[numberOfTeams];
  int currentTeam = 0;

  // read file again cuz last time read file are used to get the number of team
  // to initialize the array, probably has better way of doing this
  std::ifstream file2(filename);
  if (!file2.is_open())
  {
    std::cerr << "Failed to open the file: " << filename << "\n";
    return;
  }

  for (int i = 0; i < lineCount; i++)
  {
    if (lines[i].find("Team") != std::string::npos)
    {
      std::istringstream iss(lines[i]);
      std::string token;
      iss >> token; // "Team"
      iss >> this->teamName[currentTeam];
      iss >> this->teamNumTypeShip[currentTeam];
      this->numberOfPerShip[currentTeam] =
          new std::string[this->teamNumTypeShip[currentTeam]];
      for (int j = 0; j < this->teamNumTypeShip[currentTeam]; j++)
      {
        i++;
        if (i >= lineCount)
        {
          break;
        }
        this->numberOfPerShip[currentTeam][j] = lines[i];
      }
      currentTeam++;
    }
  }

  std::cout << numberOfTeams << "\n";
  std::cout << "Width: " << width << "\n"
            << "Height: " << height << "\n";

  // create battlefield and get it from lines
  this->battlefieldMap = new char *[height];
  for (int i = 0; i < height; i++)
  {
    this->battlefieldMap[i] = new char[width];
  }

  for (int i = lineCount - height, row = 0; i < lineCount && row < height;
       i++, row++)
  {
    std::istringstream iss(lines[i]);
    for (int col = 0; col < width; col++)
    {
      iss >> this->battlefieldMap[row][col];
    }
  }

  std::cout << "Number of Teams: " << this->numberOfTeams << std::endl;
  for (int i = 0; i < this->numberOfTeams; ++i)
  {
    std::cout << "Team " << this->teamName[i] << " has "
              << this->teamNumTypeShip[i] << " ships:" << std::endl;
    for (int j = 0; j < this->teamNumTypeShip[i]; ++j)
    {
      std::cout << "  " << this->numberOfPerShip[i][j] << std::endl;
    }
  }
  delete[] lines;
}

void GameManager::addShipToActivityLinkList()
{
  int maxShips = 0;
  for (int i = 0; i < numberOfTeams; i++)
  {
    if (teams[i]->getNumShip() > maxShips)
    {
      maxShips = teams[i]->getNumShip();
    }
  }

  for (int i = 0; i < maxShips; i++)
  {
    for (int j = 0; j < numberOfTeams; j++)
    {
      Ship **teamShips = teams[j]->getTeamShipsArray();
      int numShips = teams[j]->getNumShip();

      // Check if the current team has a ship at index
      if (i < numShips && teamShips[i])
      {
        shipActivityLinkList.push_back(teamShips[i]);
      }
    }
  }
}

void GameManager::displayShipActivityLinkList() const
{
  std::cout << "Ship Activity Link List:\n";
  shipActivityLinkList.print(); // print function only works for ship class
                                // despite being template
}

void GameManager::runGame()
{
  // create all objects
  readFile(this->filename);
  // initalize battlefield
  Battlefield battlefield(this->battlefieldMap, this->width, this->height);
  battlefield.display();
  battlefield.setIslandPosition();

  // initailize teams
  std::cout << numberOfTeams << std::endl;

  this->teams = new Team *[numberOfTeams];
  for (int i = 0; i < numberOfTeams; i++)
  {
    std::cout << "Creating team: " << teamName[i] << " with "
              << teamNumTypeShip[i] << " ships\n";
    teams[i] = new Team(teamName[i]);

    // first loop to initalize total number of ship each team has
    int totalNumberofShips = 0;
    for (int j = 0; j < teamNumTypeShip[i]; j++)
    {
      std::cout << numberOfPerShip[i][j] << "\n";
      std::string shipDetails = this->numberOfPerShip[i][j];
      std::string shipType;
      char shipLogo;
      int numberOfShip;

      std::istringstream iss(shipDetails);
      iss >> shipType >> shipLogo >> numberOfShip;

      std::cout << "Ship Type: " << shipType << std::endl;
      std::cout << "Ship Logo: " << shipLogo << std::endl;
      std::cout << "Number of Ships: " << numberOfShip << std::endl;

      totalNumberofShips += numberOfShip;
    }
    teams[i]->setTeamShipsArraySize(totalNumberofShips);

    // second loop to create ship object and add inside the team class
    for (int j = 0; j < teamNumTypeShip[i]; j++)
    {
      std::cout << numberOfPerShip[i][j] << "\n";
      std::string shipDetails = this->numberOfPerShip[i][j];
      std::string shipType;
      char shipLogo;
      int numberOfShip;

      std::istringstream iss(shipDetails);
      iss >> shipType >> shipLogo >> numberOfShip;
      /*
       for (int k = 0; k < numberOfShip; k++) {
        if (shipType == "Amphibious") {
          Amphibious* amphibious = new Amphibious();
        } else if (shipType == "Corvette") {
          Corvette* corvette = new Corvette();
        } else if (shipType == "Cruiser") {
          Cruiser* cruiser = new Cruiser();
        } else if (shipType == "Destroyer") {
          Destroyer* destroyer = new Destroyer();
        } else if (shipType == "Frigate") {
          Frigate* frigate = new Frigate();
        } else if (shipType == "SuperShip") {
          SuperShip* supership = new SuperShip();
        } else if (shipType == "Battleship") {
          Battleship* battleship = new Battleship();
        } else {
          std::cerr << "Unknown ship type: " << shipType << std::endl;
        }
*/
      for (int k = 0; k < numberOfShip; k++)
      {
        Ship *ship = nullptr;

        if (shipType == "Amphibious")
        {
          ship = new Amphibious();
        }
        else if (shipType == "Corvette")
        {
          ship = new Corvette();
        }
        else if (shipType == "Cruiser")
        {
          ship = new Cruiser();
        }
        else if (shipType == "Destroyer")
        {
          ship = new Destroyer();
        }
        else if (shipType == "Frigate")
        {
          ship = new Frigate();
        }
        else if (shipType == "SuperShip")
        {
          ship = new SuperShip();
        }
        else if (shipType == "Battleship")
        {
          ship = new Battleship();
        }
        else
        {
          std::cerr << "Unknown ship type: " << shipType << std::endl;
        }

        if (ship)
        { // Check if 'ship' is not nullptr
          std::string shipName =
              teamName[i] + "_" + shipType + "_" + std::to_string(k);
          ship->setSymbol(shipLogo);
          ship->setTeamName(teamName[i]);
          ship->setShipName(shipName);
          ship->setShipType(shipType);
          teams[i]->addShip(ship); // Add the ship to the team
        }
      }
    }
    battlefield.placeShipIntoBattlefield(teams[i]->getTeamShipsArray(),
                                         teams[i]->getNumShip());
    battlefield.display();
    teams[i]->displayTeamShips();
  }
  addShipToActivityLinkList();
  displayShipActivityLinkList();
}

GameManager::~GameManager()
{
  if (battlefieldMap)
  {
    for (int i = 0; i < height; i++)
    {
      delete[] battlefieldMap[i];
    }
    delete[] battlefieldMap;
    battlefieldMap = nullptr;
  }

  if (teams)
  {
    for (int i = 0; i < numberOfTeams; i++)
    {
      delete teams[i];
    }
    delete[] teams;
    teams = nullptr;
  }

  if (numberOfPerShip)
  {
    for (int i = 0; i < numberOfTeams; i++)
    {
      delete[] numberOfPerShip[i];
    }
    delete[] numberOfPerShip;
    numberOfPerShip = nullptr;
  }

  if (teamName)
  {
    delete[] teamName;
    teamName = nullptr;
  }

  if (teamNumTypeShip)
  {
    delete[] teamNumTypeShip;
    teamNumTypeShip = nullptr;
  }
}