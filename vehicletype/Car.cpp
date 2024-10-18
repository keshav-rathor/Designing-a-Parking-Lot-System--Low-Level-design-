#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
public:
    // Constructor to initialize a Car object with a license plate and VehicleType
    Car(const std::string& licensePlate)
        : Vehicle(licensePlate, VehicleType::CAR) {}
};

#endif // CAR_H
