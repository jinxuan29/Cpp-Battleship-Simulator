#include "../include/Battleship.h"
#include <iostream>

Battleship::Battleship()
    : Ship(Position(), 3, 0, 0, "", "Battleship", "", false, '0') {};

Battleship::Battleship(const Position &position, int lives, int reviveCount,
                       int shipDestroyedCount, const std::string &shipName,
                       const std::string &shipType, const std::string &teamName,
                       bool isDestroyed, const char symbol)
    : Ship(position, lives, reviveCount, shipDestroyedCount, shipName, shipType,
           teamName, isDestroyed, symbol){};

Battleship::~Battleship() {
  std::cout << "Battleship Removed";
  //if (this->upgradedShip!=nullptr) {
  //  delete upgradedShip;
  //  upgradedShip = nullptr;
  //}
}

Battleship::Battleship(const Battleship &other) {
  this->setPosition(other.getPosition());
  this->setShipName(other.getShipName());
  this->setShipType(other.getShipType());
  this->setLives(other.getLives());
  this->setReviveCount(other.getReviveCount());
  this->setShipDestroyedCount(other.getShipDestroyedCount());
  this->upgradedShip = other.upgradedShip;
}

Battleship &Battleship::operator=(const Battleship &other) {
  if (this != &other) {
    this->setPosition(other.getPosition());
    this->setShipName(other.getShipName());
    this->setShipType(other.getShipType());
    this->setLives(other.getLives());
    this->setReviveCount(other.getReviveCount());
    this->setShipDestroyedCount(other.getShipDestroyedCount());
  }
  return *this;
}

Ship *Battleship::seeingShip(Battlefield &battlefield) {
  Logger logger;
  std::string message = getShipName() + " is looking at its current position";
  logger.logEvent(message);
  std::cout << getShipName() << " is looking at its current position\n";

  Position current = getPosition();
  message = getShipName() + " current position: (" +
            std::to_string(current.getXValuePosition()) + "," +
            std::to_string(current.getYValuePosition()) + ")";
 // logger.logEvent(message);
  std::cout << getShipName() << " current position: ("
            << current.getXValuePosition() << "," << current.getYValuePosition()
            << ")";
  return nullptr;
}

void Battleship::movingShip(Battlefield &battlefield) {
  Logger logger;
  std::string message = getShipName() + " is moving";
  logger.logEvent(message);
  std::cout << getShipName() << " is moving\n";

  Position possibleDirections[4] = {Position().Up(), Position().Down(),
                                    Position().Left(), Position().Right()};

  bool availableDirections[4] = {true, true, true, true};
  int remainingDirections = 4;

  while (remainingDirections > 0) {
    int randomIndex;
    do {
      randomIndex = rand() % 4;
    } while (!availableDirections[randomIndex]);

    Position randomDirection = possibleDirections[randomIndex];
    Position newPosition = getPosition() + randomDirection;

    int newX = newPosition.getXValuePosition();
    int newY = newPosition.getYValuePosition();

    // Check for out of bounds, islands, and occupied positions
    if (battlefield.isValidPosition(newX, newY) &&
        !battlefield.isIsland(newX, newY) &&
        !battlefield.checkForEnemyShip(newX, newY)) {

      setPosition(newPosition);
      message = getShipName() + " moved to (" + std::to_string(newX) + ", " +
                std::to_string(newY) + ")";
      logger.logEvent(message);
      std::cout << getShipName() << " moved to (" << newX << ", " << newY
                << ")\n";
      return;
    } else {
      message =
          getShipName() + " could not move to (" + std::to_string(newX) + ", " +
          std::to_string(newY) +
          "), it's either occupied, an island, or out of bounds. Retrying";
      //logger.logEvent(message);
      std::cout
          << getShipName() << " could not move to (" << newX << ", " << newY
          << "), it's either occupied, an island, or out of bounds. Retrying\n";
    }
    availableDirections[randomIndex] = false;
    remainingDirections--;
  }

  message = getShipName() + " is trapped and cannot move.";
  logger.logEvent(message);
  std::cout << getShipName() << " is trapped and cannot move.\n";
}

void Battleship::shootingShip(Battlefield &battlefield) {
  Logger logger;
  std::string message = getShipName() + " is shooting";
  logger.logEvent(message);
  std::cout << getShipName() << " is shooting\n";

  Position currentPos = this->getPosition();

  // Generate a random position within city block distance <= 5
  Position shootingOffset;
  do {
    shootingOffset = Position().getRandomPositionFrom8Position();
  } while (abs(shootingOffset.getXValuePosition()) +
               abs(shootingOffset.getYValuePosition()) >
           5);

  Position shootingTarget = currentPos + shootingOffset;

  Ship *hit = battlefield.checkForEnemyShip(shootingTarget.getXValuePosition(),
                                            shootingTarget.getYValuePosition());

  // If an enemy ship is found, destroy it
  if (hit && (hit->getTeamName() != this->getTeamName())) {
    message = getShipName() + " has hit " + hit->getShipName() + " at " +
              std::to_string(hit->getPosition().getXValuePosition()) + "," +
              std::to_string(hit->getPosition().getYValuePosition());
    logger.logEvent(message);
    std::cout << message;
    this->setShipDestroyedCount(getShipDestroyedCount() + 1);
    hit->setIsDestroyed(true);
  } else {
    message = getShipName() + " missed at (" +
              std::to_string(shootingTarget.getXValuePosition()) + ", " +
              std::to_string(shootingTarget.getYValuePosition()) + ")";
    logger.logEvent(message);
    std::cout << getShipName() << " missed at ("
              << shootingTarget.getXValuePosition() << ", "
              << shootingTarget.getYValuePosition() << ")\n";
  }
}

void Battleship::runShip(Battlefield &battlefield) {
  seeingShip(battlefield);
  movingShip(battlefield);
  shootingShip(battlefield);
  shootingShip(battlefield);
}

Ship *Battleship::upgradeShip() {
  if (getShipDestroyedCount() >= 4) {
    std::string message = getShipName() + " has been upgraded to Destroyer!";
    Logger().logEvent(message);
    Logger().logEvent(message);
    //if (upgradedShip) {
    //  delete upgradedShip;
    //  upgradedShip = nullptr;
    //}
    std::cout << getShipName() << "has been upgraded to Destroyer!\n";
    this->upgradedShip = new Destroyer(
        Position(this->getPosition().getXValuePosition(),
                 this->getPosition().getYValuePosition()),
        this->getLives(), this->getReviveCount(), this->getShipDestroyedCount(),
        this->getShipName(), "Destroyer", this->getTeamName(),
        this->getIsDestroyed(), this->getSymbol());
    return upgradedShip;
  }
  return nullptr;
}
