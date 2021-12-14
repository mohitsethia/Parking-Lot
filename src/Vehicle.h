#pragma once
#include "Time.h"

enum VehicleType{
    motorcycle, 
    car, 
    bus, 
    truck
};

class Vehicle{
    public:
    string LicenseNumber;
    VehicleType type;
    Vehicle(){}
    Vehicle(string LicenseNumber){
        this->LicenseNumber = LicenseNumber;
    }
    Vehicle(VehicleType type){
        this->type = type;
    }
    Vehicle(string LicenseNumber, VehicleType type){
        this->LicenseNumber = LicenseNumber;
        this->type = type;
    }
    VehicleType getType();
    VehicleType convert(string &str);
};

class Car: public Vehicle{
    public:
    Car(string LicenseNumber): Vehicle(LicenseNumber ,VehicleType::car){}
};
class Bus: public Vehicle{
    public:
    Bus(string LicenseNumber): Vehicle(LicenseNumber ,VehicleType::bus){}
};
class Motorcycle: public Vehicle{
    public:
    Motorcycle(string LicenseNumber): Vehicle(LicenseNumber ,VehicleType::motorcycle){}
};
class Truck: public Vehicle{
    public:
    Truck(string LicenseNumber): Vehicle(LicenseNumber ,VehicleType::truck){}
};
