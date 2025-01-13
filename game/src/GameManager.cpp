#include "../include/GameManager.h"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

GameManager::GameManager(std::string filename) { this->filename = filename; }
// TODO
//  initialize private variable accordfing to text file
//  team class maybe?
void GameManager::readFile(std::string filename) {
  int width = 0;
  int height = 0;

  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Failed to open the file: " << filename << "\n";
    return;
  }

  int lineCount = 0;
  std::string tempLine;
  while (std::getline(file, tempLine)) {
    lineCount++;
  }
  file.clear();
  file.seekg(0, std::ios::beg);

  // Allocate memory for storing lines
  std::string *lines = new std::string[lineCount];

  // Read lines into the dynamic array
  int index = 0;
  while (std::getline(file, tempLine)) {
    lines[index++] = tempLine;
  }
  file.close();

  this->numberOfTeams = 0;

  for (int i = 0; i < lineCount; i++) {
    if (lines[i].find("iteration") != std::string::npos) {
      size_t pos = lines[i].find(" ");
      height = std::stoi(lines[i].substr(pos + 1));
    }
    if (lines[i].find("width") != std::string::npos) {
      size_t pos = lines[i].find(" ");
      width = std::stoi(lines[i].substr(pos + 1));
    }
    if (lines[i].find("height") != std::string::npos) {
      size_t pos = lines[i].find(" ");
      height = std::stoi(lines[i].substr(pos + 1));
    }
    if (lines[i].find("Team") != std::string::npos) {
      this->numberOfTeams++;
    }
    // 1. store the ship type, symbol, and number of each ship or do i just
    // create all the object based on the class then store inside team class?
    // 2. then put inside team array
  }

  // Team Variable
  this->teamName = new std::string[numberOfTeams];
  this->teamNumShip = new int[numberOfTeams];
  this->numberOfPerShip = new std::string *[numberOfTeams];
  int currentTeam = 0;

  // read file again cuz last time read file are used to get the number of team
  // to initialize the array, probably has better way of doing this
  std::ifstream file2(filename);
  if (!file2.is_open()) {
    std::cerr << "Failed to open the file: " << filename << "\n";
    return;
  }

  for (int i = 0; i < lineCount; i++) {
    if (lines[i].find("Team") != std::string::npos) {
      std::istringstream iss(lines[i]);
      std::string token;
      iss >> token; // "Team"
      iss >> this->teamName[currentTeam];
      iss >> this->teamNumShip[currentTeam];
      this->numberOfPerShip[currentTeam] = new std::string[this->teamNumShip[currentTeam]];
      for (int j = 0; j < this->teamNumShip[currentTeam]; j++) {
        i++;
        if (i >= lineCount) {
          break;
        }
        this->numberOfPerShip[currentTeam][j] = lines[i];
      }
      currentTeam++;
    }
  }

  // Battlefield Variable
  this->width = width;
  this->height = height;

  std::cout << numberOfTeams << "\n";
  std::cout << "Width: " << width << "\n" << "Height: " << height << "\n";

  // create battlefield and get it from lines
  this->battlefieldMap = new char *[height];
  for (int i = 0; i < height; i++) {
    this->battlefieldMap[i] = new char[width];
  }

  for (int i = lineCount - height, row = 0; i < lineCount && row < height;
       i++, row++) {
    std::istringstream iss(lines[i]);
    for (int col = 0; col < width; col++) {
      iss >> this->battlefieldMap[row][col];
    }
  }

  std::cout << "Number of Teams: " << this->numberOfTeams << std::endl;
    for (int i = 0; i < this->numberOfTeams; ++i) {
        std::cout << "Team " << this->teamName[i] << " has " << this->teamNumShip[i] << " ships:" << std::endl;
        for (int j = 0; j < this->teamNumShip[i]; ++j) {
            std::cout << "  " << this->numberOfPerShip[i][j] << std::endl;
        }
    }  

  Battlefield battlefield(battlefieldMap, width, height);
  battlefield.display();
  battlefield.setIslandPosition();
  battlefield.printIslandPosition();
  delete[] lines;
}

GameManager::~GameManager() {
  if (battlefieldMap) {
    for (int i = 0; i < height; i++) {
      delete[] battlefieldMap[i];
    }
    delete[] battlefieldMap;
    battlefieldMap = nullptr;
  }

  if(numberOfPerShip){
     for (int i = 0; i < numberOfTeams; i++) {
      delete [] numberOfPerShip[i];
    }
    delete [] numberOfPerShip;
    numberOfPerShip = nullptr;
  }

  if(teamName){
    delete[] teamName;
    teamName = nullptr;
  }

  if(teamNumShip){
    delete []  teamNumShip;
    teamNumShip = nullptr;
  }

}