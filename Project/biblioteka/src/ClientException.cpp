#include <iostream>
#include "ClientException.h"

using namespace std;

ClientException::ClientException(string s):
        logic_error(s)
{}
