#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
public:
    // Constructor to initialize a Motorcycle object with a license plate and VehicleType
    Motorcycle(const std::string& licensePlate)
        : Vehicle(licensePlate, VehicleType::MOTORCYCLE) {}
};

#endif // MOTORCYCLE_H
