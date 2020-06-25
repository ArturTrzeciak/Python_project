#include <boost/uuid/random_generator.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "Rent.h"
#include "RentException.h"
#include "Client.h"
#include "Vehicle.h"

using namespace std;

Rent::Rent(Client_ptr c, Vehicle_ptr v):
        client(c),
        vehicle(v)
{
    if(c==nullptr or v==nullptr)
    {
        throw RentException("nullptr Client or vehicle");
    }
    finalPrice = vehicle->actualRentalPrice()*(1.0-client->discount());
    UUID = boost::uuids::random_generator()();
    begin = boost::local_time::local_sec_clock::local_time(timeZone);
}

string Rent::rentInfo(bool cInfo){
    stringstream ret;

    ret << UUID << ' ';
    ret << begin << ' ';
    if(end.is_not_a_date_time()){
        ret << rentDuration() << ' ';
    }else{
        ret << end << ' ';
    }

    if(cInfo){
        ret << client->clientInfo() << ' ';
    }
    ret << vehicle->vehicleInfo();
    return ret.str();
}

int Rent::rentDuration(){
    if(end.is_not_a_date_time()) return 0;
    if(end.date()<begin.date()) throw RentException("end date < begin date");
    return (end.date()-begin.date()).days()+1;
}

int Rent::rentCost(){
    return finalPrice*rentDuration();
}

void Rent::endRent(){
    end=boost::local_time::local_sec_clock::local_time(timeZone);
    cost=rentCost();
}

Client_ptr Rent::getClient(){
    return client;
}

Vehicle_ptr Rent::find(){
    return vehicle;
}

string Rent::getVehicleID(){
    return vehicle->getID();
}