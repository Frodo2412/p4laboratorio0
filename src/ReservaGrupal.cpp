#include "../include/ReservaGrupal.h"

ReservaGrupal::ReservaGrupal(int codigo, DtFecha checkIn, DtFecha checkOut, EstadoReserva estado, Huesped reservante,
                             Habitacion habitacion, Huesped *inquilinos) {
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->huesped = &reservante;
    this->habitacion = &habitacion;

    int i = 0;
    while (i < MAX_HUESPEDES && &inquilinos[i] != nullptr) {
        this->huespedes[i] = &inquilinos[i];
        i++;
    }
}

float ReservaGrupal::calcularCosto() {
    float costoPorDia = this->habitacion->getPrecio();
    int cantDias = this->getCheckOut() - this->getCheckIn();
    return costoPorDia * cantDias;
}
