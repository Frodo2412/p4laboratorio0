//
// Created by unzip on 19/3/22.
//

#ifndef P4LABORATORIO0_DTRESERVAINDIVIDUAL_H
#define P4LABORATORIO0_DTRESERVAINDIVIDUAL_H


#include "DtReserva.h"

class DtReservaIndividual : public DtReserva {
private:
    bool pagado;
public:
    DtReservaIndividual();

    DtReservaIndividual(int, DtFecha, DtFecha, EstadoReserva, float, int, bool);

    bool isPago();
};


#endif //P4LABORATORIO0_DTRESERVAINDIVIDUAL_H
