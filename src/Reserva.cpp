//
// Created by unzip on 19/3/22.
//

#include "../include/Reserva.h"

DtFecha Reserva::getCheckIn() {
    return checkIn;
}

DtFecha Reserva::getCheckOut() {
    return checkOut;
}

EstadoReserva Reserva::getEstado() {
    return estado;
}

int Reserva::getCodigo() {
    return codigo;
}

void Reserva::cerrarReserva() {
    estado = Cerrada;
}

void Reserva::cancelarReserva() {
    estado = Cancelada;
}

Habitacion *Reserva::getHabitacion() {
    return habitacion;
}

Huesped *Reserva::getHuesped() {
    return huesped;
}

Reserva::~Reserva() {}

