CC = g++
CFLAGS = -std=c++17 -Wall

# Directories
GAME_INCLUDE_DIR = game/include
GAME_SRC_DIR = game/src
SHIPS_INCLUDE_DIR = ships/shipType/include
SHIPS_SRC_DIR = ships/shipType/src
UTILITY_INCLUDE_DIR = utility/include
UTILITY_SRC_DIR = utility/src

# Source Files
GAME_SOURCES = $(GAME_SRC_DIR)/Battlefield.cpp $(GAME_SRC_DIR)/GameManager.cpp
SHIP_SOURCES = $(SHIPS_SRC_DIR)/Amphibious.cpp $(SHIPS_SRC_DIR)/Battleship.cpp $(SHIPS_SRC_DIR)/Corvette.cpp $(SHIPS_SRC_DIR)/Cruiser.cpp $(SHIPS_SRC_DIR)/Destroyer.cpp $(SHIPS_SRC_DIR)/Frigate.cpp $(SHIPS_SRC_DIR)/Ship.cpp $(SHIPS_SRC_DIR)/SuperShip.cpp
UTILITY_SOURCES = $(UTILITY_SRC_DIR)/Position.cpp
MAIN_SOURCE = main.cpp

# All Sources
SOURCES = $(GAME_SOURCES) $(SHIP_SOURCES) $(UTILITY_SOURCES) $(MAIN_SOURCE)

# Output Executable
EXECUTABLE = main

# Build and Run Target
all: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

# Clean Target
clean:
	rm -f $(EXECUTABLE)
