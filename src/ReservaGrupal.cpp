#include "../include/ReservaGrupal.h"

ReservaGrupal::ReservaGrupal(int codigo, DtFecha checkIn, DtFecha checkOut, EstadoReserva estado, Huesped *reservante,
                             Habitacion *habitacion, Huesped **inquilinos) {
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->huesped = reservante;
    this->habitacion = habitacion;
    this->huespedes = inquilinos;
}

float ReservaGrupal::calcularCosto() {
    float costoPorDia = this->habitacion->getPrecio();
    float cantDias = this->getCheckOut() - this->getCheckIn();
    return costoPorDia * cantDias;
}

Huesped **ReservaGrupal::getHuespedes() {
    return this->huespedes;
}

ReservaGrupal::~ReservaGrupal() {
    for (int i = 0; i < MAX_HUESPEDES; ++i) {
        delete huespedes[i];
    }
    delete[]huespedes;
    delete huesped;
}
