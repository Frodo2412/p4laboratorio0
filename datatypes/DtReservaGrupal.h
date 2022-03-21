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
    DtHuesped **huespedes = new DtHuesped *[MAX_HUESPEDES];
public:
    DtReservaGrupal(int, DtFecha, DtFecha, EstadoReserva, float, int, DtHuesped **);

    DtReservaGrupal(ReservaGrupal *reserva);

    DtHuesped **getHuespedes();

    ReservaGrupal *toCore(Huesped *, class Habitacion *) override;

    ~DtReservaGrupal() override;
};


#endif //P4LABORATORIO0_DTRESERVAGRUPAL_H
