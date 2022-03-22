//
// Created by unzip on 19/3/22.
//

#include "DtReserva.h"
#include "DtReservaIndividual.h"
#include "DtReservaGrupal.h"
#include <iostream>

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

std::ostream &operator<<(std::ostream &os, DtReserva *reserva) {
    os << "Tipo Reserva: " << reserva->getTipoReserva() << std::endl;
    os << "Fecha check in: " << reserva->getCheckIn().format() << std::endl;
    os << "Fecha check out: " << reserva->getCheckOut().format() << std::endl;
    os << "Habitacion: " << reserva->getHabitacion() << std::endl;
    os << "Costo: $" << reserva->getCosto() << std::endl;

    if (dynamic_cast<DtReservaIndividual *>(reserva)) {
        os << dynamic_cast<DtReservaIndividual *>(reserva);
    } else {
        os << dynamic_cast<DtReservaGrupal *>(reserva);
    }

    return os;
}
