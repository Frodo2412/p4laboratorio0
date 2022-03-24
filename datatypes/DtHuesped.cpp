
#include "DtHuesped.h"
#include "../include/utils.h"

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

string DtHuesped::getEsFingerToString() {
    string res;
    if (esFinger) {
        res = "Si";
    } else
        res = "No";
    return res;
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

DtHuesped *DtHuesped::copy() {
    DtHuesped *huesped = new DtHuesped(this->nombre, this->email,
                                       this->esFinger);
    return huesped;
}

std::ostream &operator<<(std::ostream &os, DtHuesped *huesped) {
    os << "Nombre: " << huesped->getNombre() << ", Email: " << huesped->getEmail() << ", Es finger: "
       << huesped->getEsFingerToString() << std::endl;
    return os;
}
