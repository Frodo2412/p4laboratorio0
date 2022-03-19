//
// Created by brunolemus on 3/19/22.
//

#include "DtHabitacion.h"

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
