/**********|**********|**********|
Program: Logger.h

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