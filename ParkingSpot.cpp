// ParkingSpot.h
#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "Vehicle.h"
#include "VehicleType.h"
#include <stdexcept>

class ParkingSpot {
private:
    int spotNumber;
    VehicleType vehicleType;
    Vehicle* parkedVehicle;

public:
    ParkingSpot(int spotNumber, VehicleType vehicleType)
        : spotNumber(spotNumber), vehicleType(vehicleType), parkedVehicle(nullptr) {}

    // Thread safety is achieved by mutex in critical sections
    bool isAvailable() const {
        return parkedVehicle == nullptr;
    }

    void parkVehicle(Vehicle* vehicle) {
        if (isAvailable() && vehicle->getType() == vehicleType) {
            parkedVehicle = vehicle;
        } else {
            throw std::invalid_argument("Invalid vehicle type or spot already occupied.");
        }
    }

    void unparkVehicle() {
        parkedVehicle = nullptr;
    }

    VehicleType getVehicleType() const {
        return vehicleType;
    }

    Vehicle* getParkedVehicle() const {
        return parkedVehicle;
    }

    int getSpotNumber() const {
        return spotNumber;
    }
};

#endif // PARKINGSPOT_H
