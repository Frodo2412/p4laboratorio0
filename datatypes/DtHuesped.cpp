//
// Created by brunolemus on 3/19/22.
//

#include "DtHuesped.h"

DtHuesped::DtHuesped() {
    this->nombre = "";
    this->email = "";
    this->esFinger = true;
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

DtHuesped::DtHuesped(Huesped *huesped) {
    this->nombre = huesped->getNombre();
    this->email = huesped->getEmail();
    this->esFinger = huesped->isFinger();
}

DtHuesped::DtHuesped(string nombre, string email, bool esFinger) {
    this->nombre = nombre;
    this->email = email;
    this->esFinger = esFinger;
}
