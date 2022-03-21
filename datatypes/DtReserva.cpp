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

DtFecha DtReserva::getCheckOut() {
    return this->checkOut;
}

DtReserva::DtReserva(int codigo, DtFecha checkIn, DtFecha checkOut, EstadoReserva estado, float costo, int Habitacion) {
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->costo = costo;
    this->Habitacion = Habitacion;
}
