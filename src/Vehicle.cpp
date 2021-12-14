#include "Vehicle.h"

VehicleType Vehicle::convert(string &str){
    if(str == "motorcycle") return motorcycle;
    else if(str == "car") return car;
    else if(str == "bus") return bus;
    else return truck;
}
VehicleType Vehicle::getType(){
    return type;
}