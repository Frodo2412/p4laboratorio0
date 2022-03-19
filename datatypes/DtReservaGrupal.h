//
// Created by unzip on 19/3/22.
//

#ifndef P4LABORATORIO0_DTRESERVAGRUPAL_H
#define P4LABORATORIO0_DTRESERVAGRUPAL_H


#include "DtReserva.h"
#include "DtHuesped.h"
#include "../include/utils.h"

class DtReservaGrupal : public DtReserva {
private:
    DtHuesped *huespedes[MAX_HUESPEDES];
public:
    DtReservaGrupal();
    DtReservaGrupal(int, DtFecha, DtFecha, EstadoReserva, float, int, DtHuesped*);
    DtHuesped* getHuespedes();
};


#endif //P4LABORATORIO0_DTRESERVAGRUPAL_H
