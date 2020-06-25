#ifndef POBIPROJECT_RENT_H
#define POBIPROJECT_RENT_H

#include <memory>
#include <boost/uuid/uuid.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "Vehicle.h"

class  Client;
typedef std::shared_ptr<Client> Client_ptr;
typedef boost::posix_time::ptime PTime;
typedef boost::local_time::local_date_time LTime;
typedef boost::local_time::time_zone_ptr TZone;


class Rent{
    std::string info;
    boost::uuids::uuid UUID;
    int cost;
    Vehicle_ptr vehicle;
    Client_ptr client;

    TZone timeZone{new boost::local_time::posix_time_zone("CET+1")};

    LTime begin = LTime(PTime(), TZone());
    LTime end = LTime(PTime(), TZone());
    double finalPrice;

public:
    int rentDuration();
    int rentCost();
    void endRent();
    std::string getVehicleID();
    Rent(Client_ptr c, Vehicle_ptr v);
    Client_ptr getClient();
    Vehicle_ptr find();
    std::string rentInfo(bool cInfo=true);
};

typedef  std::shared_ptr<Rent> Rent_ptr;

#endif
