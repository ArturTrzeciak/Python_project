#include <iostream>
#include "VehicleException.h"

using namespace std;

VehicleException::VehicleException(string s):
logic_error(s)
{}
