// ParkingLotDemo.cpp
#include "ParkingLot.h"
#include "Level.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"
#include <iostream>

class ParkingLotDemo {
public:
    static void run() {
        // Get instance of ParkingLot (Singleton)
        ParkingLot& parkingLot = ParkingLot::getInstance();

        // Add levels to the parking lot
        parkingLot.addLevel(new Level(1, 100)); // Level 1 with 100 spots
        parkingLot.addLevel(new Level(2, 80));  // Level 2 with 80 spots

        // Create vehicle instances
        Vehicle* car = new Car("ABC123");
        Vehicle* truck = new Truck("XYZ789");
        Vehicle* motorcycle = new Motorcycle("M1234");

        // Park vehicles
        parkingLot.parkVehicle(car);
        parkingLot.parkVehicle(truck);
        parkingLot.parkVehicle(motorcycle);

        // Display availability of parking spots
        parkingLot.displayAvailability();

        // Unpark the motorcycle
        parkingLot.unparkVehicle(motorcycle);

        // Display updated availability after unparking
        parkingLot.displayAvailability();

        // Clean up dynamically allocated memory
        delete car;
        delete truck;
        delete motorcycle;
    }
};

int main() {
    ParkingLotDemo::run();
    return 0;
}
