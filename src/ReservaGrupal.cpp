#include "../include/ReservaGrupal.h"

ReservaGrupal::ReservaGrupal(int codigo, DtFecha checkIn, DtFecha checkOut, EstadoReserva estado, Huesped *reservante,
                             Habitacion *habitacion, DtHuesped **inquilinos) {
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->huesped = reservante;
    this->habitacion = habitacion;
    int i = 0;
    while (inquilinos[i] != nullptr) {
        this->huespedes[i] = inquilinos[i]->toCore();
        i++;
    }
    while (i < MAX_HUESPEDES) {
        this->huespedes[i] = nullptr;
        i++;
    }
}

float ReservaGrupal::calcularCosto() {
    float costoPorDia = this->habitacion->getPrecio();
    float cantDias = abs(this->getCheckOut() - this->getCheckIn());
    if (cantidadFingers(huespedes) > 1)
        return cantDias * costoPorDia * 0.7;
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
}

TipoReserva ReservaGrupal::getTipoReserva() {
    return Grupal;
}

int ReservaGrupal::cantidadFingers(Huesped **pHuesped) {
    int i = 0;
    while (i < MAX_HUESPEDES && pHuesped[i] != nullptr) {
        i++;
    }
    return i;
}
