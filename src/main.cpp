#include "ParkingLot.h"
#include "ParkingSpot.h"
#include "Vehicle.h"
#include "Time.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
    cout << "Number Of Different Parking\n";
    int numberOfVehicle;
    cin >> numberOfVehicle;
    vector<pair<VehicleType, int>> spots;
    Vehicle *temp = new Vehicle();
    cout << "VehicleTypes: car, bus, motorcycle, truck\n";
    cout << "VehicleType is case sensitive, so Enter carefully\n";
    cout << "Spaces available for each type of Vehicle\n";
    cout << "Enter VehicleType <space> slots\n";
    for(int i = 0; i < numberOfVehicle; i++){
        string type;
        int space;
        cin >> type >> space;
        spots.push_back({temp->convert(type), space});
    }
    delete temp;
    ParkingLot *parkingLot = new ParkingLot(spots);
    map<string, ParkingSpot*> parkedVehicles;
    while(true){
        cout << "VehicleType & Number\n";
        string vehicletype, num;
        cin >> vehicletype >> num;
        int hour;
        int minute;
        cout << "time in hour and minute\n";
        cin >> hour >> minute;
        Time *time = new Time(hour, minute);
        cout << "0 for Entry, otherwise for exit\n";
        int panel; //0 for entry 1 for exit
        cin >> panel; 
        if(panel == 0){
            ParkingSpot *ps = NULL;
            if(vehicletype == "car"){
                Vehicle *c = new Car(num);
                ps = parkingLot->getNewParkingTicket(c, time);
            }
            else if(vehicletype == "bus"){
                Vehicle *c = new Bus(num);
                ps = parkingLot->getNewParkingTicket(c, time);
            }
            else if(vehicletype == "truck"){
                Vehicle *c = new Truck(num);
                ps = parkingLot->getNewParkingTicket(c, time);
            }
            else{
                Vehicle *c = new Motorcycle(num);
                ps = parkingLot->getNewParkingTicket(c, time);
            }
            if(ps == NULL){
                cout << "No Available Space\n";
            }
            else{
                parkedVehicles[num] = ps;
                cout << "Park At : " << ps->spot << "\n";
            }
        }
        else{
            int charges = parkingLot->getParkingCharges(parkedVehicles[num], time);
            cout << "You need to pay: " << charges << "\n";
            parkingLot->freeParking(parkedVehicles[num]);
            parkedVehicles.erase(num);
            cout << "Thank you visit Again\n";
        }
    }
    return 0;
}