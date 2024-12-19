#include "iostream"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <limits>
#include <ostream>
#include <string>
#include <cstdlib>
#include <ctime>

bool FileExists(std::string filename) {
  std::ifstream file(filename.c_str());

  if (file) {
    std::cout << "File exists \n";
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

  int iteration_num;
  int width_num;
  int height_num;

  if (FileExists(filename)) {
    do {
      std::cout << "Old file detected, do you want to use the existing file? (Y/N): ";
      std::cin >> response;
      std::transform(response.begin(), response.end(), response.begin(), ::toupper);

      if (response != "Y" && response != "N") {
        std::cout << "Invalid input. Please enter 'Y' or 'N' \n";
      }

      if (response == "Y") {
        std::cout << "Reading input from file \n";
        std::ifstream file(filename);
        while (std::getline(file, file_content)) {
          std::cout << file_content + "\n";
        }
      }

      if (response == "N") {
        break;
      }

    } while (response != "Y" && response != "N");
  }

  std::cout << "Creating new file\n";
  std::ofstream file(filename);
  if (!file) {
    std::cerr << "Error Opening File!" << std::endl;
    return 1;
  }

  std::cout << "Enter the following details:\n";

  while (true) {
    std::cout << "Iterations: ";
    if (std::cin >> iteration_num && iteration_num > 0) break;
    std::cout << "Invalid input. Please enter a positive integer.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  file << "iterations " << iteration_num << "\n";

  while (true) {
    std::cout << "Width: ";
    if (std::cin >> width_num && width_num > 0) break;
    std::cout << "Invalid input. Please enter a positive integer.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  file << "width " << width_num << "\n";

  while (true) {
    std::cout << "Height: ";
    if (std::cin >> height_num && height_num > 0) break;
    std::cout << "Invalid input. Please enter a positive integer.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  file << "height " << height_num << "\n";

  int group_count;
  while (true) {
    std::cout << "Enter number of groups joining: ";
    if (std::cin >> group_count && group_count > 0) break;
    std::cout << "Invalid input. Please enter a positive integer.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  for (int i = 0; i < group_count; ++i) {
    std::string group_name;
    std::cout << "Enter name for Group " << (i + 1) << ": ";
    std::cin >> group_name;

    int group_total_ship_types;
    while (true) {
      std::cout << "Enter number of ship types for " << group_name << ": ";
      if (std::cin >> group_total_ship_types && group_total_ship_types > 0 && group_total_ship_types <= 4) break;
      std::cout << "Invalid input. Please enter a positive integer (1 to 4).\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int battleship_num = 0, cruiser_num = 0, destroyer_num = 0, frigate_num = 0;

    do {
      std::cout << "Enter number of Battleships for " << group_name << ": ";
      if (!(std::cin >> battleship_num) || battleship_num < 0) {
        std::cout << "Invalid input. Please enter a non-negative integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }

      std::cout << "Enter number of Cruisers for " << group_name << ": ";
      if (!(std::cin >> cruiser_num) || cruiser_num < 0) {
        std::cout << "Invalid input. Please enter a non-negative integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }

      std::cout << "Enter number of Destroyers for " << group_name << ": ";
      if (!(std::cin >> destroyer_num) || destroyer_num < 0) {
        std::cout << "Invalid input. Please enter a non-negative integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }

      std::cout << "Enter number of Frigates for " << group_name << ": ";
      if (!(std::cin >> frigate_num) || frigate_num < 0) {
        std::cout << "Invalid input. Please enter a non-negative integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }

      int total_ship_types = 0;
      if (battleship_num > 0) ++total_ship_types;
      if (cruiser_num > 0) ++total_ship_types;
      if (destroyer_num > 0) ++total_ship_types;
      if (frigate_num > 0) ++total_ship_types;

      if (total_ship_types != group_total_ship_types) {
        std::cout << "Error: Total ship types must match the declared number of ship types. Please re-enter.\n";
        continue;
      }

      file <<"Team "<< group_name << " " << total_ship_types << "\n";

      if (battleship_num > 0) file << "Battleship * " << battleship_num << "\n";
      if (cruiser_num > 0) file << "Cruiser $ " << cruiser_num << "\n";
      if (destroyer_num > 0) file << "Destroyer # " << destroyer_num << "\n";
      if (frigate_num > 0) file << "Frigate @ " << frigate_num << "\n";

      break;
    } while (true);
  }

  std::cout << "Generating randomized grid...\n";
  srand(time(0));
  for (int i = 0; i < height_num; ++i) {
    for (int j = 0; j < width_num; ++j) {
      int cell_value = rand() % 2;
      file << cell_value << (j < width_num - 1 ? " " : "");
    }
    file << "\n";
  }

  file.close();
  std::cout << "File created successfully!\n";

  return 0;
}
