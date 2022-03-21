//
// Created by brunolemus on 3/19/22.
//

#ifndef P4LABORATORIO0_DTHUESPED_H
#define P4LABORATORIO0_DTHUESPED_H

#include <iostream>
#include "../include/Huesped.h"

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

    Huesped *toCore();

    string getEsFingerToString();
};

std::ostream &operator<<(std::ostream &, DtHuesped* huespedes[]);
#endif //P4LABORATORIO0_DTHUESPED_H
