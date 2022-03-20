#ifndef P4LABORATORIO0_SISTEMA_H
#define P4LABORATORIO0_SISTEMA_H

#include "Habitacion.h"
#include "utils.h"
#include "Huesped.h"
#include "../datatypes/DtHabitacion.h"
#include "iostream"

using namespace std;

class Sistema {
private:
    Habitacion *habitaciones[MAX_HABITACIONES];
    Huesped *huespedes[MAX_HUESPEDES];
    int cantHabitaciones;
    int cantHuespedes;

    bool isMailValido(string email);

    bool numeroNoAsignadoAHabitacion(int numero);

    bool hayEspacioParaHabitacion();

public:

    Sistema();

    void agregarHabitacion(int numero, float precio, int capacidad);

    void agregarHuesped(string nombre, string email, bool esFinger);

    DtHabitacion **obtenerHabitaciones(int &cantHabitaciones);
};


#endif //P4LABORATORIO0_SISTEMA_H
