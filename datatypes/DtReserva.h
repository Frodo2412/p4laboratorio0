#ifndef P4LABORATORIO0_DTRESERVA_H
#define P4LABORATORIO0_DTRESERVA_H

#include "DtFecha.h"
#include "../include/Habitacion.h"
#include "../include/Huesped.h"
#include "../include/Reserva.h"
#include "EstadoReserva.h"

class DtReserva {
protected:
    int codigo;
    DtFecha checkIn, checkOut;
    EstadoReserva estado;
    float costo;
    int Habitacion;
public:
    DtReserva(int codigo, DtFecha checkIn, DtFecha checkOut, EstadoReserva estado, float costo, int habitacion);

    int getCodigoReserva();

    DtFecha getCheckIn();

    DtFecha getCheckOut();

    EstadoReserva getEstado();

    float getCosto();

    int getHabitacion();

    virtual Reserva *toCore(Huesped *, class Habitacion *) = 0;
};


#endif //P4LABORATORIO0_DTRESERVA_H
