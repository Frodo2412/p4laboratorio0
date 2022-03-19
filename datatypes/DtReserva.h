//
// Created by unzip on 19/3/22.
//

#ifndef P4LABORATORIO0_DTRESERVA_H
#define P4LABORATORIO0_DTRESERVA_H

#include "DtFecha.h"
#include "EstadoReserva.h"

class DtReserva {
protected:
    int codigo;
    DtFecha checkIn, checkOut;
    EstadoReserva estado;
    float costo;
    int Habitacion;
public:

    int getCodigoReserva();

    DtFecha getCheckIn();

    DtFecha getCheckOut();

    EstadoReserva getEstado();

    float getCosto();

    int getHabitacion();
};


#endif //P4LABORATORIO0_DTRESERVA_H
