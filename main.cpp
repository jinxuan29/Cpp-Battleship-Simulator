#include "iostream"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <ostream>
#include <string>

bool FileExists(std::string filename) {
  std::ifstream file(filename.c_str());

  if (file) {
    std::cout << "File exist \n";
    return true;
  } else {
    std::cout << "File does not exist \n";
    return false;
  }
}

int main() {
  std::string filename = "game.txt";
  std::string response;
  std::string file_content;

  // setting variable
  int iteration_num;
  int width_num;
  int height_num;

  // typr of battleship
  int battleship_num; // total type of battleship
  int cruiser_num;
  int destroyer_num;
  int frigate_num;

  do {
    std::cout
        << "Old file detected, do you want to use the existing file? (Y/N): ";
    std::cin >> response;
    std::transform(response.begin(), response.end(), response.begin(),
                   ::toupper);

    if (response != "Y" && response != "N") {
      std::cout << "Invalid input. Please enter 'Y' or 'N' \n";
    }

    if (response == "Y") {
      std::cout << "Reading input from file \n";
      std::ifstream file(filename);
      int x = 0;
      while (std::getline(file, file_content)) {
        std::cout << file_content + "\n";
        x++;
      }

      file.clear();
      file.seekg(0);

      std::cout << "\n \n Storing input into array \n\n";
      std::string *file_content_array = new std::string[x];

      std::string file_content;
      int index = 0;

      while (getline(file, file_content)) {
        file_content_array[index] = file_content;
        index++;
      }
      for (int i = 0; i < x; i++) {
        std::cout << file_content_array[i] << "\n";
      }
      
      delete[] file_content_array;
    }

    if (response == "N") {
    }

  } while (response != "Y" && response != "N");
}
