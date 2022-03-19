#include <stdexcept>
#include "../include/Sistema.h"

Sistema::Sistema() {
    int i = 0;
    while (i < MAX_HABITACIONES) {
        this->habitaciones[i] = nullptr;
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

bool Sistema::numeroNoAsignadoAHabitacion(int numero) {
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

DtHabitacion **Sistema::obtenerHabitaciones(int &cantHabitaciones) {
    DtHabitacion **habs = new DtHabitacion *[tope];
    int i = 0;
    while (i < tope) {
        habs[i] = new DtHabitacion(this->habitaciones[i]);
        i++;
    }
    cantHabitaciones = tope;
    return habs;
}

