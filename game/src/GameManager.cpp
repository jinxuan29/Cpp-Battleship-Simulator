
#include <cstddef>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "../include/GameManager.h"

GameManager::GameManager(std::string filename) { 
    this->filename = filename; 
}

void GameManager::readFile(std::string filename) {
    int width;
    int height;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << "\n";
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
        
        if (line.find("width") != std::string::npos) {
            size_t pos = line.find(" ");
            width = std::stoi(line.substr(pos + 1));
        } 
        if (line.find("height") != std::string::npos) {
            size_t pos = line.find(" ");
            height = std::stoi(line.substr(pos + 1));
        }
    }

    file.close();

    // Store width and height into class variables
    this->width = width;
    this->height = height;

    // Output all lines
    std::cout << "Width: " << width << "\n" << "Height: " << height << "\n";

    std::cout << "All lines from the file:\n";
    for (const auto& l : lines) {
        std::cout << l << "\n";
    }
    for (size_t i = 11; i < lines.size(); i++) {
        std::cout <<  "\n" <<lines[i] << "\n";
    }

    //todo store each value into a int** battlefieldmap and find thhe island position.
}