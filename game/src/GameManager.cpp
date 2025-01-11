#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "../include/GameManager.h"

GameManager::GameManager(std::string filename) { 
    this->filename = filename; 
}
//TODO 
// initialize private variable accordfing to text file
// team class maybe?
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
    std::string* lines = new std::string[lineCount];

    // Read lines into the dynamic array
    int index = 0;
    while (std::getline(file, tempLine)) {
        lines[index++] = tempLine;
    }
    file.close();

    // Parse width and height
    // TODO parse other variable in
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

    }

    this->width = width;
    this->height = height;

    std::cout << "Width: " << width << "\n" << "Height: " << height << "\n";

    // create battlefield and get it from lines
    this->battlefieldMap = new char*[height];
    for (int i = 0; i < height; i++) {
        this->battlefieldMap[i] = new char[width];
    }

    for (int i = 11, row = 0; i < lineCount && row < height; i++, row++) {
        std::istringstream iss(lines[i]);
        for (int col = 0; col < width; col++) {
            iss >> this->battlefieldMap[row][col];
        }
    }

//    std::cout << "Battlefield Map:\n";
//    for (int i = 0; i < height; i++) {
//        for (int j = 0; j < width; j++) {
//            std::cout << this->battlefieldMap[i][j];
//        }
//        std::cout << "\n";
//    }

    Battlefield battlefield(battlefieldMap, width, height);
    battlefield.display();
    battlefield.setIslandPosition();
    battlefield.printIslandPosition();
    delete [] lines;
}


GameManager::~GameManager() {
    if (battlefieldMap) {
        for (int i = 0; i < height; i++) {
            delete[] battlefieldMap[i];
        }
        delete[] battlefieldMap;
        battlefieldMap = nullptr;
    }
}