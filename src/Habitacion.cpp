//
// Created by brunolemus on 3/19/22.
//

#include "../include/Habitacion.h"

int Habitacion::getNumero() {
    return numero;
}

float Habitacion::getPrecio() {
    return precio;
}

int Habitacion::getCapacidad() {
    return capacidad;
}

void Habitacion::setPrecio(float p) {
    precio = p;
}

void Habitacion::setCapacidad(int c) {
    capacidad = c
}
