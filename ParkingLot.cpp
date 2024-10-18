#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <vector>
#include <iostream>
#include "Level.h"
#include "Vehicle.h"

class ParkingLot {
private:
    static ParkingLot* instance;  // Singleton instance
    std::vector<Level*> levels;   // List of parking levels

    // Private constructor to prevent instantiation
    ParkingLot() {}

public:
    // Get the singleton instance of ParkingLot
    static ParkingLot& getInstance() {
        if (instance == nullptr) {
            instance = new ParkingLot();
        }
        return *instance;
    }

    // Add a level to the parking lot
    void addLevel(Level* level) {
        levels.push_back(level);
    }

    // Park a vehicle
    bool parkVehicle(Vehicle* vehicle) {
        for (Level* level : levels) {
            if (level->parkVehicle(vehicle)) {
                std::cout << "Vehicle parked successfully." << std::endl;
                return true;
            }
        }
        std::cout << "Could not park vehicle." << std::endl;
        return false;
    }

    // Unpark a vehicle
    bool unparkVehicle(Vehicle* vehicle) {
        for (Level* level : levels) {
            if (level->unparkVehicle(vehicle)) {
                return true;
            }
        }
        return false;
    }

    // Display availability of parking spots on all levels
    void displayAvailability() {
        for (Level* level : levels) {
            level->displayAvailability();
        }
    }

    // Destructor to clean up dynamically allocated levels
    ~ParkingLot() {
        for (Level* level : levels) {
            delete level;
        }
    }
};

#endif // PARKINGLOT_H
