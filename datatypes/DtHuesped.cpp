//
// Created by brunolemus on 3/19/22.
//

#include "DtHuesped.h"

DtHuesped::DtHuesped() {
    this->nombre = "";
    this->email = "";
    this->esFinger = true;
}

DtHuesped::DtHuesped(string name, string email, bool isFinger) {
    nombre = name;
    this->email = email;
    esFinger = isFinger;
}

string DtHuesped::getEmail() {
    return email;
}

string DtHuesped::getNombre() {
    return nombre;
}

bool DtHuesped::getEsFinger() {
    return esFinger;
}

void DtHuesped::setNombre(string name) {
    nombre = name;
}

void DtHuesped::setEsFinger(bool isFinger) {
    esFinger = isFinger;
}

Huesped *DtHuesped::toCore() {
    return new Huesped(nombre, email, esFinger);
}
