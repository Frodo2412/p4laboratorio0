//
// Created by unzip on 19/3/22.
//

#include "../include/ReservaIndividual.h"

float ReservaIndividual::calcularCosto() {
    return this->getHabitacion()->getPrecio() * abs(this->getCheckOut() - this->getCheckIn());
}

bool ReservaIndividual::isPago() {
    return pagado;
}

void ReservaIndividual::setPago() {
    this->pagado = true;
}

ReservaIndividual::ReservaIndividual(int cod, Huesped *hues, Habitacion *hab, DtFecha In, DtFecha Out, bool pago,
                                     EstadoReserva est) {
    this->codigo = cod;
    this->huesped = hues;
    this->habitacion = hab;
    this->checkIn = In;
    this->checkOut = Out;
    this->pagado = pago;
    this->estado = est;
}

TipoReserva ReservaIndividual::getTipoReserva() {
    return Individual;
}
