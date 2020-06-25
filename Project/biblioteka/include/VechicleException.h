//
// Created by student on 10.06.2020.
//

#ifndef POBIPROJECT_VECHICLEEXCEPTIONS_H
#define POBIPROJECT_VECHICLEEXCEPTIONS_H

class VehicleException: public std::logic_error{

public:
    VehicleException(std::string s);
};

#endif //POBIPROJECT_VECHICLEEXCEPTIONS_H
