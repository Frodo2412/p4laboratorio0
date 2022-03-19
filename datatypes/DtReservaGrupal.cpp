//
// Created by unzip on 19/3/22.
//

#include "DtReservaGrupal.h"

DtReserva *DtReservaGrupal::getHuespedes() {
    return this->huespedes;
}

DtReservaGrupal::DtReservaGrupal() {

}

DtReservaGrupal::DtReservaGrupal(ReservaGrupal rg) {
    DtHuesped hues[MAX_HUESPEDES];
    this->huespedes = hues;
}
