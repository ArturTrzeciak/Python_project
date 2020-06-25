#include <iostream>
#include "RentException.h"

using namespace std;

RentException::RentException(string s):
logic_error(s)
{}