//
// Created by brunolemus on 3/19/22.
//

#ifndef P4LABORATORIO0_SISTEMA_H
#define P4LABORATORIO0_SISTEMA_H

#include "Habitacion.h"

const int MAX_HUESPEDES = 100;
const int MAX_HABITACIONES = 100;
const int MAX_RESERVAS = 100;

class Sistema {
public:
    Sistema();
    void agregarHabitacion(int numero, float precio, int capacidad);

private:
    Habitacion *habitaciones[MAX_HABITACIONES];
    int tope;
    bool numeroNoAsignadoAHabitacion(int numero);
    bool hayEspacioParaHabitacion();
};


#endif //P4LABORATORIO0_SISTEMA_H
