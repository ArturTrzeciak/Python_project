#ifndef POBIPROJECT_CLIENTEXCEPTION_H
#define POBIPROJECT_CLIENTEXCEPTION_H

class ClientException: public std::logic_error{
public:
    ClientException(std::string s);
};

#endif //POBIPROJECT_CLIENTEXCEPTION_H
