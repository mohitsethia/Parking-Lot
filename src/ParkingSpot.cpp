#include "ParkingSpot.h"

Time* ParkingSpot::getTime(){
    return entryTime;
}

void ParkingSpot::freeSpace(){
    this->Free = true;
}

bool ParkingSpot::isFree(){
    return this->Free;
}

VehicleType ParkingSpot::getType(){
    return type;
}