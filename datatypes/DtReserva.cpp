//
// Created by unzip on 19/3/22.
//

#include "DtReserva.h"

int DtReserva::getCodigoReserva() {
    return this->codigo;
}

DtFecha DtReserva::getCheckIn() {
    return this->checkIn;
}

EstadoReserva DtReserva::getEstado() {
    return this->estado;
}

float DtReserva::getCosto() {
    return this->costo;
}

int DtReserva::getHabitacion() {
    return this->Habitacion;
}

DtReserva::DtReserva(Reserva r): codigo(r.getCodigo()), checkIn(r.getCheckIn()), checkOut(r.getCheckOut()), estado(r.getEstado()) {
}

DtReserva::DtReserva() {
}
