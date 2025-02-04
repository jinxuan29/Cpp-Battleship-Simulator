#include "../include/Battlefield.h"
#include <ctime>
#include <iostream>

void Battlefield::removeShipAtPosition(int x, int y)
{
  for (int i = 0; i < totalNumberOfShips; i++)
  {
    if (battlefieldShip[i] != nullptr)
    { // Ensure the pointer is valid
      Position shipPos = battlefieldShip[i]->getPosition();
      if (shipPos.getXValuePosition() == x && shipPos.getYValuePosition() == y)
      {
        std::cout << "Removing ship at (" << x << ", " << y << ").\n";

        // Remove ship from battlefield (mark as nullptr)
        delete battlefieldShip[i]; // Free memory
        battlefieldShip[i] = nullptr;

        // Remove the ship from the battlefield grid
        grid[y][x] = '.'; // Assuming '.' represents empty water

        return; // Exit after removing the ship
      }
    }
  }
}

int Battlefield::getWidth() const
{
  return width;
}

int Battlefield::getHeight() const
{
  return height;
}

bool Battlefield::checkForEnemyShip(int x, int y) const
{
  if (!isValidPosition(x, y))
    return false; // Ensure within battlefield bounds

  for (int i = 0; i < totalNumberOfShips; i++)
  {
    if (battlefieldShip[i] && !battlefieldShip[i]->getIsDestroyed())
    {
      Position pos = battlefieldShip[i]->getPosition();
      if (pos.getXValuePosition() == x && pos.getYValuePosition() == y)
      {
        return true; // Ship found at (x, y), it's a hit!
      }
    }
  }
  return false; // No ship found, it's a miss
}

bool Battlefield::checkTerrain(int x, int y) const
{
  if (x < 0 || x >= width || y < 0 || y >= height)
    return false; // Out of bounds check

  return grid[y][x] == '0'; //  '0' means sea, '1' means land
}

bool Battlefield::isValidPosition(int x, int y) const
{
  return (x >= 0 && x < width && y >= 0 && y < height);
}

Battlefield::Battlefield(int width, int height) : width(width), height(height)
{
  grid = new char *[height];
  for (int i = 0; i < height; i++)
  {
    grid[i] = new char[width];

    for (int j = 0; j < width; j++)
    {
      grid[i][j] = '0';
    }
  }
}

Battlefield::Battlefield(char **grid, int width, int height)
    : width(width), height(height), numberOfIsland(0), islandPosition(nullptr)
{
  this->grid = new char *[height];
  for (int i = 0; i < height; i++)
  {
    this->grid[i] = new char[width];
    for (int j = 0; j < width; j++)
    {
      this->grid[i][j] = grid[i][j];
    }
  }
}

// Battlefield::Battlefield(char** grid){
//   this->grid = grid;
// }

void Battlefield::display() const
{
  for (int i = 0; i < height; ++i)
  {
    for (int j = 0; j < width; ++j)
    {
      std::cout << this->grid[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

void Battlefield::setIslandPosition()
{
  int numberOfIsland = 0;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (this->grid[i][j] == '1')
      {
        numberOfIsland++;
      }
    }
  }
  this->numberOfIsland = numberOfIsland;
  // get island position and store inside islandposition array
  this->islandPosition = new int *[numberOfIsland];
  for (int i = 0; i < numberOfIsland; i++)
  {
    this->islandPosition[i] = new int[2];
  }
  int currentIndex = 0;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (this->grid[i][j] == '1')
      {
        this->islandPosition[currentIndex][0] = j;
        this->islandPosition[currentIndex][1] = i;
        currentIndex++;
      }
    }
  }
}

// only works after running the setIslandPosition function
// starts from 0 instead of 1
void Battlefield::printIslandPosition() const
{
  std::cout << "Island Positions:\n";
  for (int i = 0; i < this->numberOfIsland; i++)
  {
    std::cout << this->islandPosition[i][0] << ":" << this->islandPosition[i][1]
              << "\n";
  }
}

void Battlefield::placeIsland(int x, int y, char symbol)
{
  grid[x][y] = symbol;
  display();
}

void Battlefield::updateBattlefield()
{
  // rewrite the grid change all symbol back to 0 except islands (1)
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (this->grid[i][j] != '1')
      {
        this->grid[i][j] = '0';
      }
    }
  }

  for (int i = 0; i < totalNumberOfShips; i++)
  {
    if (battlefieldShip[i] && !battlefieldShip[i]->getIsDestroyed())
    {
      Position pos = battlefieldShip[i]->getPosition();
      if (pos.getXValuePosition() >= 0 && pos.getXValuePosition() < width &&
          pos.getYValuePosition() >= 0 && pos.getYValuePosition() < height)
      {
        bool isOnIsland = false;
        if (battlefieldShip[i]->getShipType() == "Amphibious")
        {
          // check if amphibious is on island
          for (int j = 0; j < numberOfIsland; j++)
          {
            if (islandPosition[j][0] == pos.getXValuePosition() &&
                islandPosition[j][1] == pos.getYValuePosition())
            {
              isOnIsland = true;
              break;
            }
          }
        }

        // If the ship is Amphibious and on an island, display the ship's symbol
        if (isOnIsland)
        {
          this->grid[pos.getYValuePosition()][pos.getXValuePosition()] =
              battlefieldShip[i]->getSymbol();
        }
        else if (this->grid[pos.getYValuePosition()]
                           [pos.getXValuePosition()] != '1')
        {
          // Otherwise, display the ship's symbol only if the position is not an
          // island
          this->grid[pos.getYValuePosition()][pos.getXValuePosition()] =
              battlefieldShip[i]->getSymbol();
        }
      }
    }
  }

  // Display the updated battlefield
  display();
}

void Battlefield::placeShipArrayIntoBattlefield(Ship **ships, int numShips)
{
  srand(time(0));
  this->totalNumberOfShips = numShips;
  // add ship into the battlefield ship array
  battlefieldShip = new Ship *[numShips]();
  for (int i = 0; i < numShips; i++)
  {
    battlefieldShip[i] = ships[i];
  }

  int emptyPositions = 0;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (grid[i][j] == '0')
      {
        emptyPositions++;
      }
    }
  }

  if (emptyPositions < numShips)
  {
    std::cerr << "Error: Not enough empty positions to place all ships.\n";
    return;
  }

  for (int i = 0; i < numShips; i++)
  {
    if (!ships[i])
    {
      std::cerr << "Error: Ship at index " << i << " is null.\n";
      continue;
    }

    bool placed = false;
    int attempts = 0;
    const int maxAttempts = width * height;

    while (!placed && attempts < maxAttempts)
    {

      int y = rand() % height;
      int x = rand() % width;

      bool isIsland = false;

      for (int j = 0; j < numberOfIsland; j++)
      {
        if (islandPosition[j][0] == x && islandPosition[j][1] == y)
        {
          isIsland = true;
          break;
        }
      }

      // allow amphibious to land on island
      if (ships[i]->getShipType() == "Amphibious")
      {
        if (grid[y][x] == '0' || isIsland)
        {
          grid[y][x] = ships[i]->getSymbol();
          placed = true;

          ships[i]->setPosition(Position(x, y));
        }
      }

      else if (!isIsland && grid[y][x] == '0')
      {
        grid[y][x] = ships[i]->getSymbol();
        placed = true;

        ships[i]->setPosition(Position(x, y));
      }

      attempts++;
    }

    if (!placed)
    {
      std::cerr << "Error: Could not place ship " << i << " after "
                << maxAttempts << " attempts.\n";
    }
  }
}

void Battlefield::placeShipIntoBattlefield(Ship *ship)
{
  if (!ship)
  {
    std::cerr << "Error: Ship is null.\n";
    return;
  }

  // If Amphibous Ship then include island as well into empty count
  int emptyCount = 0;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (grid[i][j] == '0' || (ship->getShipType() == "Amphibious" && grid[i][j] == '1'))
      {
        emptyCount++;
      }
    }
  }

  if (emptyCount == 0)
  {
    std::cerr << "Error: No empty positions available to place the ship.\n";
    return;
  }

  int **emptyPositions = new int *[emptyCount];
  for (int i = 0; i < emptyCount; i++)
  {
    emptyPositions[i] = new int[2];
  }

  int index = 0;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      if (grid[i][j] == '0' || (ship->getShipType() == "Amphibious" && grid[i][j] == '1'))
      {
        emptyPositions[index][0] = i;
        emptyPositions[index][1] = j;
        index++;
      }
    }
  }

  // Randomly select a position from the valid positions
  srand(time(0));
  int randomIndex = rand() % emptyCount;
  int x = emptyPositions[randomIndex][1];
  int y = emptyPositions[randomIndex][0];

  // Place the ship at the selected position
  grid[y][x] = ship->getSymbol();
  ship->setPosition(Position(x, y));

  std::cout << "Ship placed at (" << x << ", " << y << ")\n";

  for (int i = 0; i < emptyCount; i++)
  {
    delete[] emptyPositions[i];
  }
  delete[] emptyPositions;
}

Battlefield::~Battlefield()
{
  if (this->grid)
  {
    for (int i = 0; i < height; i++)
    {
      delete[] this->grid[i];
    }
    delete[] this->grid;
    this->grid = nullptr;
  }

  if (this->islandPosition)
  {
    for (int i = 0; i < this->numberOfIsland; i++)
    {
      delete[] this->islandPosition[i];
    }
    delete[] this->islandPosition;
    this->islandPosition = nullptr;
  }

  if (this->battlefieldShip)
  {
    delete[] battlefieldShip;
    this->battlefieldShip = nullptr;
  }
}