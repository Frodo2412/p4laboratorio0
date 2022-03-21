#ifndef P4LABORATORIO0_SISTEMA_H
#define P4LABORATORIO0_SISTEMA_H

#include "utils.h"
#include "iostream"
#include "Reserva.h"
#include "../datatypes/DtReserva.h"
#include "../datatypes/DtHabitacion.h"


using namespace std;

class Sistema {
public:
    Sistema();

    void agregarHabitacion(int numero, float precio, int capacidad);

    DtHabitacion **obtenerHabitaciones(int &cantHabitaciones);

    DtHuesped **obtenerHuespedes(int &cantHuespedes);

    void agregarHuesped(string nombre, string email, bool esFinger);

    void registrarReserva(string email, DtReserva *reserva);

private:
    bool existsHuespedWithEmail(string email);

    Habitacion **habitaciones = new Habitacion* [MAX_HABITACIONES];
    int habitacionesOcupadas;

    Huesped **huespedes = new Huesped*[MAX_HUESPEDES];
    int cantHuespedes;

    Reserva **reservas = new Reserva*[MAX_RESERVAS];
    int cantReservas;

    bool existsHabitacionWithNumero(int numero);

    bool hayEspacioParaHabitacion();

    bool hayEspacioParaReserva();

    Huesped *getHuespedWithEmail(string email);

    Habitacion *getHabitacionWithNumero(int numero);

};


#endif //P4LABORATORIO0_SISTEMA_H
