//
// Created by unzip on 19/3/22.
//

#ifndef P4LABORATORIO0_DTRESERVAGRUPAL_H
#define P4LABORATORIO0_DTRESERVAGRUPAL_H


#include "../include/utils.h"
#include "DtHuesped.h"
#include "../include/ReservaGrupal.h"
#include "DtReserva.h"


class DtReservaGrupal : public DtReserva {
private:
    DtHuesped **huespedes;
public:
    DtReservaGrupal(int codigo, DtFecha checkIn, DtFecha checkOut, EstadoReserva estado, float costo, int Habitacion,
                    Huesped **hues);

    DtHuesped **getHuespedes();

    ReservaGrupal *toCore(Huesped *, class Habitacion *) override;

    ~DtReservaGrupal();
};


#endif //P4LABORATORIO0_DTRESERVAGRUPAL_H
