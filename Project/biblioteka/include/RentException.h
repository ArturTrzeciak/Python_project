#ifndef POBIPROJECT_RENTEXCEPTION_H
#define POBIPROJECT_RENTEXCEPTION_H

class RentException : public std::logic_error{

public:
    RentException(std::string s);

};


#endif
