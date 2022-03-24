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

    DtReservaIndividual(ReservaIndividual *reservaIndividual);

    bool isPago();

    ReservaIndividual *toCore(Huesped *, class Habitacion *) override;

    std::string isPagoToString();

    TipoReserva getTipoReserva() override;

    string getTipoReservaToString() override;
};

std::ostream &operator<<(std::ostream &, DtReservaIndividual *);

#endif //P4LABORATORIO0_DTRESERVAINDIVIDUAL_H
