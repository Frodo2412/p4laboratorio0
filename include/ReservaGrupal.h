#ifndef P4LABORATORIO0_RESERVAGRUPAL_H
#define P4LABORATORIO0_RESERVAGRUPAL_H


#include "Reserva.h"
#include "Huesped.h"
#include "utils.h"

class ReservaGrupal : public Reserva {
private:
    Huesped **huespedes = new Huesped *[MAX_HUESPEDES];
public:
    ReservaGrupal(int, DtFecha, DtFecha, EstadoReserva, Huesped *, Habitacion *, Huesped **);

    float calcularCosto() override;

    ~ReservaGrupal();

//    DtReservaGrupal *toDt() override
};


#endif //P4LABORATORIO0_RESERVAGRUPAL_H

