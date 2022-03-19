//
// Created by unzip on 19/3/22.
//

#include "ReservaIndividual.h"

float ReservaIndividual::calcularCosto() {
    return this->getHabitacion()->getPrecio() * (this->getCheckOut() - this->getCheckIn());
}

bool ReservaIndividual::isPago() {
    return pagado;
}

void ReservaIndividual::setPago() {
    this->pagado = true;
}

ReservaIndividual::ReservaIndividual(int cod, Huesped *hues, Habitacion * hab, DtFecha In, DtFecha Out) {
    this->codigo = cod;
    this->huesped = hues;
    this->habitacion = hab;
    this->checkIn = In;
    this->checkOut = Out;
    this->pagado = false;
}

