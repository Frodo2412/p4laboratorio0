//
// Created by brunolemus on 3/19/22.
//

#ifndef P4LABORATORIO0_DTHABITACION_H
#define P4LABORATORIO0_DTHABITACION_H


#include "../include/Habitacion.h"

class DtHabitacion {
private:
    int numero;
    float precio;
    int capacidad;
public:
    DtHabitacion(int, float, int);

//    DtHabitacion(Habitacion *);

    int getNumero();

    float getPrecio();

    int getCapacidad();

    Habitacion *toCore();
};

#endif //P4LABORATORIO0_DTHABITACION_H
