//
// Created by unzip on 19/3/22.
//

#ifndef P4LABORATORIO0_RESERVAINDIVIDUAL_H
#define P4LABORATORIO0_RESERVAINDIVIDUAL_H


#include "Reserva.h"
#include "../datatypes/DtReservaIndividual.h"

class ReservaIndividual : public Reserva {
private:
    bool pagado;
public:
    ReservaIndividual(int, Huesped *, Habitacion *, DtFecha, DtFecha, EstadoReserva);

    float calcularCosto() override;

    bool isPago();

    void setPago();

    DtReservaIndividual *toDt() override;
};


#endif //P4LABORATORIO0_RESERVAINDIVIDUAL_H
