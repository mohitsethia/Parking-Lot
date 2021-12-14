#pragma once
#include "Vehicle.h"

using namespace std;

class ParkingSpot{
    public:
    int spot;
    VehicleType type;
    Time *entryTime = NULL;
    bool Free;
    ParkingSpot(int spot, Vehicle *vehicle, Time *time){
        this->type = vehicle->getType();
        this->spot = spot;
        this->entryTime = time;
        // int hour = time->hour;
        // int minute = time->minute;
        // this->entryTime = new Time(hour, minute);
        this->Free = false;
    }
    Time* getTime();
    void freeSpace();
    bool isFree();
    VehicleType getType();
};