//
// Created by brunolemus on 3/19/22.
//

#include "DtHabitacion.h"

using namespace std;

DtHabitacion::DtHabitacion(int numero, float precio, int capacidad) {
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
}

int DtHabitacion::getNumero() {
    return this->numero;
}

float DtHabitacion::getPrecio() {
    return this->precio;
}

int DtHabitacion::getCapacidad() {
    return this->capacidad;
}

Habitacion *DtHabitacion::toCore() {
    return new Habitacion(numero, precio, capacidad);
}

std::ostream &operator<<(std::ostream &os, DtHabitacion *habitacion) {
    os << "Número: " << habitacion->getNumero() << endl << "Precio por noche: " << habitacion->getPrecio() << endl
       << "Capacidad: "
       << habitacion->getCapacidad() << std::endl;
    return os;
}
