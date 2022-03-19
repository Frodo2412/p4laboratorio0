//
// Created by brunolemus on 3/19/22.
//

#include <stdexcept>
#include "../include/Sistema.h"

Sistema::Sistema() {
    int i = 0;
    while (i < MAX_HABITACIONES) {
        this->habitaciones[i] = NULL;
        i++;
    }
    tope = 0;
}

void Sistema::agregarHabitacion(int numero, float precio, int capacidad) {
    if (hayEspacioParaHabitacion() && numeroNoAsignadoAHabitacion(numero)) {
        habitaciones[tope] = new Habitacion(numero, precio, capacidad);
        tope++;
    }
}

bool Sistema::numeroNoAsignadoAHabitacion (int numero) {
    int i = 0;
    bool res = true;
    while (i < tope && res) {
        if (habitaciones[i]->getNumero() == numero)
            res = false;
        i++;
    }
    if (!res)
        throw new std::invalid_argument("El numero de habitacion ya existe");
    return res;
}

bool Sistema::hayEspacioParaHabitacion() {
    return tope < MAX_HABITACIONES;
}
