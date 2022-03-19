#ifndef P4LABORATORIO0_SISTEMA_H
#define P4LABORATORIO0_SISTEMA_H

#include "Habitacion.h"
#include "utils.h"
#include "Huesped.h"
#include "../datatypes/DtHabitacion.h"
#include "iostream"

using namespace std;

class Sistema {
public:
    Sistema();

    void agregarHabitacion(int numero, float precio, int capacidad);

    void agregarHuesped(string nombre, string email, bool esFinger);

    DtHabitacion **obtenerHabitaciones(int &cantHabitaciones);

private:
    bool isMailValido(string email);

    Habitacion *habitaciones[MAX_HABITACIONES];
    int cantHabitaciones;

    Huesped *huespedes[MAX_HUESPEDES];
    int cantHuespedes;

    bool numeroNoAsignadoAHabitacion(int numero);

    bool hayEspacioParaHabitacion();
};


#endif //P4LABORATORIO0_SISTEMA_H
