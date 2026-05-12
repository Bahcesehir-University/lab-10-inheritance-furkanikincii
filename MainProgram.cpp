// ================================================================
// Lab: Inheritance in C++
// Course: Object-Oriented Programming for Engineers
// File: MainProgram.cpp
// ================================================================
// INSTRUCTIONS:
//   Complete every TODO. Do NOT change function signatures.
//   All code stays in this single file. No .h files allowed.
// ================================================================

#include <iostream>
#include <string>
#include <sstream> // Formatted string output için eklendi

// ================================================================
// CLASS DEFINITIONS
// ================================================================

// ----------------------------------------------------------------
// Base Class: Vehicle
// ----------------------------------------------------------------
class Vehicle {
protected:
    // TODO: declare protected data members
    std::string make;
    int year;
    double fuelLevel;

public:
    // TODO: declare constructor
    Vehicle(std::string make, int year, double fuelLevel);

    // TODO: declare getters (const)
    std::string getMake() const;
    int getYear() const;
    double getFuelLevel() const;

    // TODO: declare refuel(double amount)
    void refuel(double amount);

    // TODO: declare pure virtual describe() returning std::string
    virtual std::string describe() const = 0;

    // TODO: declare virtual destructor
    virtual ~Vehicle() {}
};

// ----------------------------------------------------------------
// Derived Class: Car
// ----------------------------------------------------------------
class Car : public Vehicle {
private:
    // TODO: int numDoors
    int numDoors;

public:
    // TODO: Constructor(make, year, fuelLevel, numDoors)
    Car(std::string make, int year, double fuelLevel, int numDoors);

    // TODO: getNumDoors()
    int getNumDoors() const;

    // TODO: describe() override
    std::string describe() const override;
};

// ----------------------------------------------------------------
// Derived Class: Truck
// ----------------------------------------------------------------
class Truck : public Vehicle {
private:
    // TODO: double payloadTons
    double payloadTons;

public:
    // TODO: Constructor(make, year, fuelLevel, payloadTons)
    Truck(std::string make, int year, double fuelLevel, double payloadTons);

    // TODO: getPayloadTons()
    double getPayloadTons() const;

    // TODO: describe() override
    std::string describe() const override;
};

// ================================================================
// FUNCTION IMPLEMENTATIONS
// ================================================================

// ----------------------------------------------------------------
// Vehicle member function implementations
// ----------------------------------------------------------------

// TODO: Implement Vehicle constructor
Vehicle::Vehicle(std::string make, int year, double fuelLevel) 
    : make(make), year(year), fuelLevel(fuelLevel) {}

// TODO: Implement getMake(), getYear(), getFuelLevel()
std::string Vehicle::getMake() const { return make; }
int Vehicle::getYear() const { return year; }
double Vehicle::getFuelLevel() const { return fuelLevel; }

// TODO: Implement refuel(double amount)
void Vehicle::refuel(double amount) {
    if (amount <= 0) return;
    fuelLevel += amount;
    if (fuelLevel > 100.0) fuelLevel = 100.0;
}

// ----------------------------------------------------------------
// Car member function implementations
// ----------------------------------------------------------------

// TODO: Implement Car constructor (chain to Vehicle)
Car::Car(std::string make, int year, double fuelLevel, int numDoors)
    : Vehicle(make, year, fuelLevel), numDoors(numDoors) {}

// TODO: Implement getNumDoors()
int Car::getNumDoors() const { return numDoors; }

// TODO: Implement describe()
std::string Car::describe() const {
    std::ostringstream oss;
    oss << "Car: " << make << " (" << year << "), " << numDoors 
        << " doors, fuel: " << fuelLevel << "%";
    return oss.str();
}

// ----------------------------------------------------------------
// Truck member function implementations
// ----------------------------------------------------------------

// TODO: Implement Truck constructor (chain to Vehicle)
Truck::Truck(std::string make, int year, double fuelLevel, double payloadTons)
    : Vehicle(make, year, fuelLevel), payloadTons(payloadTons) {}

// TODO: Implement getPayloadTons()
double Truck::getPayloadTons() const { return payloadTons; }

// TODO: Implement describe()
std::string Truck::describe() const {
    std::ostringstream oss;
    oss << "Truck: " << make << " (" << year << "), payload: " 
        << payloadTons << "t, fuel: " << fuelLevel << "%";
    return oss.str();
}

// ================================================================
// MAIN
// ================================================================

int main() {
    // --- Basic usage demo ---
    Car   c("Toyota", 2020, 75.5, 4);
    Truck t("Ford",   2018, 60.0, 5.5);

    std::cout << c.describe() << "\n";
    std::cout << t.describe() << "\n";

    // Polymorphism via base pointer
    Vehicle* v1 = &c;
    Vehicle* v2 = &t;
    std::cout << v1->describe() << "\n";
    std::cout << v2->describe() << "\n";

    // Refuel demo
    c.refuel(20.0);
    std::cout << "After refuel: " << c.getFuelLevel() << "%\n";

    return 0;
}
