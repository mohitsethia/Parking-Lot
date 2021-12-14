#include "ParkingLot.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

ParkingSpot* ParkingLot::getNewParkingTicket(Vehicle *vehicle, Time *time){
    VehicleType type = vehicle->getType();
    ParkingSpot *spot = NULL;
    if(free[type].size() > 0){
        int freeSpace = *free[type].begin();
        free[type].erase(free[type].begin());
        spot = new ParkingSpot(freeSpace, vehicle, time);
        activeTickets[spot] = freeSpace;
    }
    return spot;
}

void ParkingLot::freeParking(ParkingSpot *spot){
    free[spot->getType()].insert(activeTickets[spot]);
    activeTickets.erase(spot);
    delete spot;
}

int ParkingLot::getParkingCharges(ParkingSpot *spot, Time *time){
    int hoursParked = time->hour - spot->entryTime->hour;
    int minuteParked = time->minute - spot->entryTime->minute;
    if(minuteParked > 5) hoursParked++;
    return hoursParked*20;
}