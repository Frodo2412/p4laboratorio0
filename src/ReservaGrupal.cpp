#include "../include/ReservaGrupal.h"

ReservaGrupal::ReservaGrupal(int codigo, DtFecha checkIn, DtFecha checkOut, EstadoReserva estado, Huesped *reservante,
                             Habitacion *habitacion, Huesped **inquilinos) {
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->huesped = reservante;
    this->habitacion = habitacion;

    int i = 0;
    while (i < MAX_HUESPEDES && inquilinos[i] != nullptr) {
        this->huespedes[i] = inquilinos[i];
        i++;
    }
}

float ReservaGrupal::calcularCosto() {
    float costoPorDia = this->habitacion->getPrecio();
    int cantDias = this->getCheckOut() - this->getCheckIn();
    return costoPorDia * cantDias;
}

ReservaGrupal::~ReservaGrupal() {
    for (int i = 0; i < MAX_HUESPEDES; ++i) {
        delete huespedes[i];
    }
    delete[]huespedes;
    delete huesped;
}

//DtReservaGrupal *ReservaGrupal::toDt() {
//    auto **huesp = new DtHuesped*[MAX_HUESPEDES];
//    int i = 0;
//    while (i < MAX_HUESPEDES && huespedes[i] != nullptr) {
//        huesp[i] = new DtHuesped(huespedes[i]->getNombre(), huespedes[i]->getEmail(), huespedes[i]->isFinger());
//        i++;
//    }
//    return new DtReservaGrupal(codigo, checkIn, checkOut, estado, calcularCosto(), habitacion->getNumero(), huesp);
//}
