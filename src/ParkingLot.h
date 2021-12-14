#pragma once
#include "ParkingSpot.h"
#include "Vehicle.h"
#include "Time.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>


class ParkingLot{
    public:
    map<ParkingSpot*, int> activeTickets;
    map<VehicleType, set<int>> free;
    
    ParkingLot(vector<pair<VehicleType, int>> spots){
        for(const pair<VehicleType, int> &s: spots){
            for(int i = 0; i < s.second; i++){
                free[spots[i].first].insert(i+1);
            }
        }
    }

    ParkingSpot* getNewParkingTicket(Vehicle *vehicle, Time *time);
    void freeParking(ParkingSpot *spot);
    int getParkingCharges(ParkingSpot *spot, Time *time);
};