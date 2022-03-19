//
// Created by unzip on 19/3/22.
//

#include "DtReservaIndividual.h"

DtReservaIndividual::DtReservaIndividual(ReservaIndividual ri) {
    this->codigo = ri.getCodigo();
    this->checkIn = ri.getCheckIn();
    this->checkOut = ri.getCheckOut();
    this->estado = ri.getEstado();
    this->Habitacion = ri.getHabitacion()->getNumero();
    this->pagado = ri.isPago();
}

bool DtReservaIndividual::isPago() {
    return this->pagado;
}

DtReservaIndividual::DtReservaIndividual() {

}
