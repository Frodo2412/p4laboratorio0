//
// Created by unzip on 19/3/22.
//

#ifndef P4LABORATORIO0_RESERVA_H
#define P4LABORATORIO0_RESERVA_H


#include "../datatypes/DtFecha.h"
#include "../datatypes/EstadoReserva.h"

class Reserva {
private:
    int codigo;
    DtFecha checkIn, checkOut;
    EstadoReserva estado;
public:
    Reserva();

    Reserva(int cod, DtFecha checkIn, DtFecha checkOut);

    void cerrarReserva();

    void cancelarReserva();

    virtual float calcularCosto() = 0;

    int getCodigo();

    DtFecha getCheckIn();

    DtFecha getCheckOut();

    EstadoReserva getEstado();
};


#endif //P4LABORATORIO0_RESERVA_H
