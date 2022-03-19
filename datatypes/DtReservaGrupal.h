//
// Created by unzip on 19/3/22.
//

#ifndef P4LABORATORIO0_DTRESERVAGRUPAL_H
#define P4LABORATORIO0_DTRESERVAGRUPAL_H


#include "DtReserva.h"

class DtReservaGrupal : public DtReserva {
private:
    int MAX_HUESPEDES = 10;
    DtHuesped huespedes[];
public:
    DtReservaGrupal(ReservaGrupal);
    DtHuesped* getHuespedes();
};


#endif //P4LABORATORIO0_DTRESERVAGRUPAL_H
