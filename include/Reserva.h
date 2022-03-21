//
// Created by unzip on 19/3/22.
//

#ifndef P4LABORATORIO0_RESERVA_H
#define P4LABORATORIO0_RESERVA_H

#include "../datatypes/DtFecha.h"
#include "../datatypes/EstadoReserva.h"
#include "../datatypes/TipoReserva.h"
#include "Habitacion.h"
#include "Huesped.h"

class Reserva {
protected:
    int codigo;
    Huesped *huesped;
    Habitacion *habitacion;
    DtFecha checkIn, checkOut;
    EstadoReserva estado;
public:

    void cerrarReserva();

    void cancelarReserva();

    virtual float calcularCosto() = 0;

    int getCodigo();

    DtFecha getCheckIn();

    DtFecha getCheckOut();

    EstadoReserva getEstado();

    Habitacion *getHabitacion();

    Huesped *getHuesped();

    virtual TipoReserva getTipoReserva() = 0;

    virtual ~Reserva();
};


#endif //P4LABORATORIO0_RESERVA_H
