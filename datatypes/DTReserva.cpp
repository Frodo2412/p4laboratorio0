//
// Created by unzip on 19/3/22.
//

#include "DTReserva.h"

int DTReserva::getCodigoReserva() {
    return this->codigo;
}

DTFecha DTReserva::getCheckIn() {
    return this->checkIn;
}

EstadoReserva DTReserva::getEstado() {
    return this->estado;
}

float DTReserva::getCosto() {
    return this->costo;
}

int DTReserva::getHabitacion() {
    return this->Habitacion;
}
