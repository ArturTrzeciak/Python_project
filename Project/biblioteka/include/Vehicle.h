#ifndef POBIPROJECT_VEHICLE_H
#define POBIPROJECT_VEHICLE_H

#include <string>
#include <memory>

class Vehicle;

typedef std::shared_ptr<Vehicle> Vehicle_ptr;

class Vehicle{
    std::string id;
    int baseRentPrice;
public:
    Vehicle(std::string id, int baseRentPrice);
    virtual int actualRentalPrice();
    std::string vehicleInfo();
    std::string getID();
    bool operator==(Vehicle_ptr other);
};

#endif
