#ifndef P4LABORATORIO0_SISTEMA_H
#define P4LABORATORIO0_SISTEMA_H

#include "Habitacion.h"
#include "utils.h"
#include "Huesped.h"
#include "../datatypes/DtHabitacion.h"
#include "iostream"
#include "Reserva.h"
#include "../datatypes/DtReserva.h"

using namespace std;

class Sistema {
public:
    Sistema();

    void agregarHabitacion(int numero, float precio, int capacidad);

    DtHabitacion **obtenerHabitaciones(int &cantHabitaciones);

    void agregarHuesped(string nombre, string email, bool esFinger);

    void registrarReserva(string email, DtReserva *reserva);
    DtReserva** obtenerReservas(DtFecha fecha, int& cantReservas);

private:
    bool existsHuespedWithEmail(string email);

    Habitacion *habitaciones[MAX_HABITACIONES];
    int habitacionesOcupadas;

    Huesped *huespedes[MAX_HUESPEDES];
    int cantHuespedes;

    Reserva *reservas[MAX_RESERVAS];
    int cantReservas;

    bool existsHabitacionWithNumero(int numero);

    bool hayEspacioParaHabitacion();

    bool hayEspacioParaReserva();

    Huesped *getHuespedWithEmail(string email);

    Habitacion *getHabitacionWithNumero(int numero);

};


#endif //P4LABORATORIO0_SISTEMA_H
