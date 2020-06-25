#include "Vehicle.h"
#include <iostream>

using namespace std;

string Vehicle::vehicleInfo() {
    return baseRentPrice + " " + id;
}

//Vehicle::Vehicle(string id, int baseRentPrice): id(id), baseRentPrice(baseRentPrice){
//    if(baseRentPrice <= 0)
//        throw VehicleEXception()
//}

string Vehicle::getID() { return id; }