#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <iostream>
#include "ParkingSpot.h"
#include "Vehicle.h"
#include "VehicleType.h"

class Level {
private:
    int floor;                        // Floor number of the parking level
    std::vector<ParkingSpot*> parkingSpots; // List of parking spots on this level

public:
    // Constructor to initialize a level with a given floor number and number of spots
    Level(int floor, int numSpots) : floor(floor) {
        // Assign spots in the ratio of 50:40:10 for motorcycles, cars, and trucks
        double spotsForBikes = 0.50;
        double spotsForCars = 0.40;

        int numBikes = static_cast<int>(numSpots * spotsForBikes);
        int numCars = static_cast<int>(numSpots * spotsForCars);

        // Create parking spots for motorcycles
        for (int i = 1; i <= numBikes; ++i) {
            parkingSpots.push_back(new ParkingSpot(i, VehicleType::MOTORCYCLE));
        }

        // Create parking spots for cars
        for (int i = numBikes + 1; i <= numBikes + numCars; ++i) {
            parkingSpots.push_back(new ParkingSpot(i, VehicleType::CAR));
        }

        // Create parking spots for trucks
        for (int i = numBikes + numCars + 1; i <= numSpots; ++i) {
            parkingSpots.push_back(new ParkingSpot(i, VehicleType::TRUCK));
        }
    }

    // Destructor to clean up dynamically allocated parking spots
    ~Level() {
        for (ParkingSpot* spot : parkingSpots) {
            delete spot;
        }
    }

    // Park a vehicle on the level
    bool parkVehicle(Vehicle* vehicle) {
        for (ParkingSpot* spot : parkingSpots) {
            if (spot->isAvailable() && spot->getVehicleType() == vehicle->getType()) {
                spot->parkVehicle(vehicle);
                return true;
            }
        }
        return false;
    }

    // Unpark a vehicle from the level
    bool unparkVehicle(Vehicle* vehicle) {
        for (ParkingSpot* spot : parkingSpots) {
            if (!spot->isAvailable() && spot->getParkedVehicle() == vehicle) {
                spot->unparkVehicle();
                return true;
            }
        }
        return false;
    }

    // Display availability of parking spots on this level
    void displayAvailability() const {
        std::cout << "Level " << floor << " Availability:" << std::endl;
        for (const ParkingSpot* spot : parkingSpots) {
            std::cout << "Spot " << spot->getSpotNumber() << ": "
                      << (spot->isAvailable() ? "Available For " : "Occupied By ") 
                      << spot->getVehicleType() << std::endl;
        }
    }
};

#endif // LEVEL_H
