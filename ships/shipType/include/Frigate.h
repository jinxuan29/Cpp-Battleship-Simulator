#pragma once

#include "../action/ShootingShip.h"
#include "../utility/include/Position.h"
#include <string>

class Frigate : public ShootingShip {
private:
    int shotsFired; // Tracks the number of shots fired
    int shipsDestroyed; // Tracks the number of ships destroyed
    static const int UPGRADE_THRESHOLD = 3; // Ships destroyed required for upgrade

    // Shooting sequence: up, up-right, right, down-right, down, down-left, left, up-left
    Position shootingSequence[8] = {
        Position(0, -1),  // up
        Position(1, -1),  // up-right
        Position(1, 0),   // right
        Position(1, 1),   // down-right
        Position(0, 1),   // down
        Position(-1, 1),  // down-left
        Position(-1, 0),  // left
        Position(-1, -1)  // up-left
    };

public:
    Frigate();

    Frigate(const Position &position, int lives, int reviveCount,
            int shipDestroyedCount, const std::string &shipName,
            const std::string &shipType, const std::string &teamName,
            bool isDestroyed);

    ~Frigate();

    Frigate(const Frigate &other);

    Frigate &operator=(const Frigate &other);

    void shootingShip() override;

    // Upgrade to Corvette
    void upgradeToCorvette();

    // Get the next target position based on the shooting sequence
    Position getNextTargetPosition();

    // Check if the frigate should upgrade to Corvette
    bool shouldUpgrade() const;
};