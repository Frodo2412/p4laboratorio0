//
// Created by brunolemus on 3/19/22.
//

#ifndef P4LABORATORIO0_DTHUESPED_H
#define P4LABORATORIO0_DTHUESPED_H

#include <iostream>

using namespace std;

class DtHuesped {
private:
    string nombre;
    string email;
    bool esFinger;
public:
    DtHuesped();

    DtHuesped(string, string, bool);

    string getNombre();

    string getEmail();

    bool getEsFinger();

    void setNombre(string);

    void setEsFinger(bool);
};


#endif //P4LABORATORIO0_DTHUESPED_H
