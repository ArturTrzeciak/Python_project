//
// Created by student on 10.06.2020.
//

#ifndef POBIPROJECT_CLIENTTYP_H
#define POBIPROJECT_CLIENTTYP_H

class ClientTyp{
public:
    virtual double discount()=0;
    virtual int maxVehicle()=0;
    virtual ~ClientTyp();
};


#endif //POBIPROJECT_CLIENTTYP_H
