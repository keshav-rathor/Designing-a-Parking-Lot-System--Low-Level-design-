# Designing-a-Parking-Lot-System--Low-Level-Design
Designing a Parking Lot System-(Low Level design)
Requirements

The parking lot should consist of multiple levels, with each level containing a specified number of parking spots.
The system must support various types of vehicles, including cars, motorcycles, and trucks.
Each parking spot should be designated for a specific type of vehicle.
Upon entry, the system should allocate a parking spot to the vehicle and release the spot when the vehicle exits.
The system must track parking spot availability in real-time and provide this information to users.
It should support multiple entry and exit points and handle concurrent access efficiently.
Implementations

C++ Implementation
Classes, Interfaces, and Enumerations

ParkingLot: Implements the Singleton pattern to ensure only one instance of the parking lot exists. It maintains a list of levels and provides methods for parking and unparking vehicles.
Level: Represents a parking level, containing a list of parking spots. It handles parking and unparking of vehicles within the level.
ParkingSpot: Represents an individual parking spot, tracking its availability and the parked vehicle.
Vehicle: An abstract base class for different vehicle types, extended by specific classes like Car, Motorcycle, and Truck.
VehicleType: An enumeration defining the different vehicle types supported in the parking lot.
Multi-threading is implemented using synchronization techniques to ensure thread safety in critical sections.
Main: Demonstrates the functionality of the parking lot system.

