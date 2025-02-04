#pragma once

#include <fstream>
#include <iostream>
class Logger{
    private:
        std::ofstream logFile;
    public:

    Logger(const std::string& filename = "log.txt") {
        logFile.open(filename, std::ios::app); 
        if (!logFile.is_open()) {
            std::cout << "Error: Could not open log file: " << filename << std::endl;
        }
    }

    void logEvent(const char& character){
        if(logFile.is_open()){
            logFile << character << " ";
        } else{
            std::cout << "Error: Log File is not open. \n";
        }
    }
    
    void logEvent(const std::string& message) {
        if (logFile.is_open()) {
            logFile << message << "\n";
        }
    }

    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};