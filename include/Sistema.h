#ifndef P4LABORATORIO0_SISTEMA_H
#define P4LABORATORIO0_SISTEMA_H

#include "Habitacion.h"
#include "utils.h"
#include "../datatypes/DtHabitacion.h"

class Sistema {
public:
    Sistema();

    void agregarHabitacion(int numero, float precio, int capacidad);

    DtHabitacion** obtenerHabitaciones(int& cantHabitaciones);

private:
    Habitacion *habitaciones[MAX_HABITACIONES];
    int tope;

    bool numeroNoAsignadoAHabitacion(int numero);

    bool hayEspacioParaHabitacion();
};


#endif //P4LABORATORIO0_SISTEMA_H
