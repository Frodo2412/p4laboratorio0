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

DtReserva::DtReserva(Reserva *reserva) {
    this->codigo = reserva->getCodigo();
    this->checkIn = reserva->getCheckIn();
    this->checkOut = reserva->getCheckOut();
    this->estado = reserva->getEstado();
    this->costo = reserva->calcularCosto();
    this->Habitacion = reserva->getHabitacion()->getNumero();
}

DtReserva::DtReserva(int cod, DtFecha In, DtFecha Out, EstadoReserva estado, float costo, int hab) {
    this->codigo = cod;
    this->checkIn = In;
    this->checkOut = Out;
    this->estado = estado;
    this->costo = costo;
    this->Habitacion = hab;
}

DtReserva::~DtReserva() {}
