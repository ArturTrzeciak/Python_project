#include "Client.h"
#include "Adress.h"
#include <iostream>

using namespace std;

int main() {

    Adress home("Wall", "99");

    Client a("Ferb", "Jonson", "1223456789");
    Client b("Adam", "Fibunach", "1233456780");

    a.clientInfo();
    b.clientInfo();

    return EXIT_SUCCESS;
}