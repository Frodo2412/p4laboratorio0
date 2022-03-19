//
// Created by brunolemus on 3/19/22.
//

#include "../include/Huesped.h"

Huesped::Huesped(string nombre, string email, bool esFinger) {
    this->nombre = nombre;
    this->email = email;
    this->esFinger = esFinger;
}

string Huesped::getNombre() {
    return nombre;
}

string Huesped::getEmail() {
    return email;
}

bool Huesped::isFinger() {
    return esFinger;
}

void Huesped::setNombre(string nombre) {
    this->nombre = nombre;
}

void Huesped::setFinger(bool esFinger) {
    this->esFinger = esFinger;
}

Huesped::Huesped() {
    nombre = "";
    email = "";
    esFinger = false;
}
