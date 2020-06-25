#include <iostream>
#include "Client.h"
#include "Rent.h"
#include "ClientException.h"

using namespace std;

Client::Client(string firstName, string lastName, string personalID) :
    firstName(firstName),
    lastName(lastName),
    personalID(personalID)
    {
//    if(firstName=="") throw ClientException("Empty firstName");
//    if(lastName=="") throw ClientException("Empty lastName");
//    if(personalID=="") throw ClientException("Empty personalID");
//    innerClient = ClientType_ptr(new ClientBasic());
};

Client::~Client(){
    cout << "Destruktor" << endl;
};

string Client::getFirstName() { return firstName; }

string Client::getLastName() { return lastName; }

string Client::getPersonalID() { return personalID; }

string Client::clientInfo() {
        string dat = firstName + " " + lastName + " " + personalID;

    if(adress!=nullptr){
        dat += " " + adress->getStreet();
        dat += " " + adress->getNumber();
    }
    if(registeredAdress!=nullptr){
        dat += " " + registeredAdress->getStreet();
        dat += " " + registeredAdress->getNumber();
    }
    for(auto it: rents){
        dat += '\n' + it->rentInfo(false);
    }
    return dat;

}

void Client::setRegAdress(Adress_ptr A){
    if(A!=nullptr){
        throw ClientException("Empty adress");
    }else registeredAdress=A;
}

void Client::changeType(int t){
    switch(t){
        case 1:
            innerClient = ClientTyp_ptr(new ClientStart());
            break;
        case 2:
            innerClient = ClientTyp_ptr(new ClientTwo());
            break;
        case 3:
            innerClient = ClientTyp_ptr(new ClientThree());
            break;
        case 4:
            innerClient = ClientTyp_ptr(new ClientFour());
            break;
        default:
            throw ClientException("Wrong client type");
    }
}

double Client::discount(){
    return innerClient->discount();
}

int Client::maxVehicle(){
    return innerClient->maxVehicle();
}

int Client::rentedVehicles(){
    return rents.size();
}
