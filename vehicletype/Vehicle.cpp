#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "VehicleType.h"

class Vehicle {
protected:
    std::string licensePlate;  // License plate of the vehicle
    VehicleType type;          // Type of the vehicle (e.g., Car, Truck, Motorcycle)

public:
    // Constructor to initialize a vehicle with a license plate and vehicle type
    Vehicle(const std::string& licensePlate, VehicleType type)
        : licensePlate(licensePlate), type(type) {}

    // Getter for the vehicle type
    VehicleType getType() const {
        return type;
    }

    // Virtual destructor to ensure proper cleanup for derived classes
    virtual ~Vehicle() = default;
};

#endif // VEHICLE_H
