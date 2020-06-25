#ifndef BASEPROJECT_FUNKCJE_H
#define BASEPROJECT_FUNKCJE_H

#include <string>

using namespace std;
class Client;

class Adress {
    private:
        string street;
        string number;

    public:
        Adress(string street, string number);

        string getStreet();
        string getNumber();
};

#endif
