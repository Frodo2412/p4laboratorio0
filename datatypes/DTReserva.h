//
// Created by unzip on 19/3/22.
//

#ifndef P4LABORATORIO0_DTRESERVA_H
#define P4LABORATORIO0_DTRESERVA_H

#include "EstadoReserva.h"

class DTReserva {
private:
    int codigo;
    DTFecha checkIn;
    EstadoReserva estado;
    float costo;
    int Habitacion;
public:
    int getCodigoReserva();
    DTFecha getCheckIn();
    EstadoReserva getEstado();
    float getCosto();
    int getHabitacion();
};


#endif //P4LABORATORIO0_DTRESERVA_H
