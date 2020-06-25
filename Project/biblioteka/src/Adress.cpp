#include "Adress.h"

Adress::Adress(string street, string number) : street{street}, number{number}{};

string Adress::getStreet(){ return street; };

string Adress::getNumber(){ return number; };
