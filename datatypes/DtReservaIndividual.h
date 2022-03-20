//
// Created by unzip on 19/3/22.
//

#ifndef P4LABORATORIO0_DTRESERVAINDIVIDUAL_H
#define P4LABORATORIO0_DTRESERVAINDIVIDUAL_H


#include "DtReserva.h"
#include "../include/ReservaIndividual.h"

class DtReservaIndividual : public DtReserva {
private:
    bool pagado;
public:
    DtReservaIndividual(int, DtFecha, DtFecha, EstadoReserva, float, int, bool);

    bool isPago();

    ReservaIndividual *toCore(Huesped *, class Habitacion *) override;
};


#endif //P4LABORATORIO0_DTRESERVAINDIVIDUAL_H
