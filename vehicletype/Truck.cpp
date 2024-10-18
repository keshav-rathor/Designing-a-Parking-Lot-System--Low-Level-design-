#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
public:
    // Constructor to initialize a Truck object with a license plate and VehicleType
    Truck(const std::string& licensePlate)
        : Vehicle(licensePlate, VehicleType::TRUCK) {}
};

#endif // TRUCK_H
