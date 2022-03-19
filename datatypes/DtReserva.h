//
// Created by unzip on 19/3/22.
//

#ifndef P4LABORATORIO0_DTRESERVA_H
#define P4LABORATORIO0_DTRESERVA_H

#include "EstadoReserva.h"
#include "DtFecha.h"

class DtReserva {
private:
    int codigo;
    DtFecha checkIn;
    EstadoReserva estado;
    float costo;
    int Habitacion;
public:
    DtReserva(Reserva);
    int getCodigoReserva();
    DtFecha getCheckIn();
    EstadoReserva getEstado();
    float getCosto();
    int getHabitacion();
};


#endif //P4LABORATORIO0_DTRESERVA_H
