#ifndef POBIPROJECT_CREATURE_H
#define POBIPROJECT_CREATURE_H

#include <string>
#include <memory>
#include <vector>
#include "Adress.h"
#include "Vehicle.h"
#include "ClientTypes.hpp"

class Rent;

typedef std::shared_ptr<Adress> Adress_ptr;
typedef std::shared_ptr<ClientTyp> ClientTyp_ptr;
typedef std::shared_ptr<Rent> Rent_ptr;

class Client {
    std::string firstName;
    std::string lastName;
    std::string personalID;
    Adress_ptr registeredAdress= nullptr;
    Adress_ptr adress= nullptr;
    std::vector<Rent_ptr> rents;
    ClientTyp_ptr innerClient;

public:
    Client(std::string firstName, std::string lastName, std::string personalID);
    ~Client();
    std::string getFirstName();
    std::string getLastName();
    std::string getPersonalID();
    std::string clientInfo();

    void setRegAdress(Adress_ptr  A);
    void setAdress(Adress_ptr  A);
    void changeType(int);
    double discount();
    int maxVehicle();
    int rentedVehicles();
};

typedef std::shared_ptr<Client> Client_ptr;

#endif