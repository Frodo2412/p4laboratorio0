//
// Created by unzip on 19/3/22.
//

#include "DtReservaGrupal.h"

DtHuesped **DtReservaGrupal::getHuespedes() {
    return this->huespedes;
}

DtReservaGrupal::DtReservaGrupal(int cod, DtFecha In, DtFecha Out, EstadoReserva estado, float costo, int hab,
                                 DtHuesped **hues) {
    this->codigo = cod;
    this->checkIn = In;
    this->checkOut = Out;
    this->estado = estado;
    this->costo = costo;
    this->Habitacion = hab;
    this->huespedes = hues;

}

ReservaGrupal *DtReservaGrupal::toCore(Huesped *huesped, class Habitacion *hab) {
    auto **hues = new Huesped *[MAX_HUESPEDES];
    int i = 0;
    while (i < MAX_HUESPEDES && huespedes[i] != nullptr) {
        hues[i] = huespedes[i]->toCore();
        i++;
    }
    return new ReservaGrupal(this->codigo, this->checkIn, this->checkOut, Abierta, huesped, hab, hues);
}

DtReservaGrupal::~DtReservaGrupal() {
    for (int i = 0; i < MAX_HUESPEDES; ++i) {
        delete huespedes[i];
    }
    delete[]huespedes;
}

string DtReservaGrupal::getTipoReserva() {
    return "Grupal";
}

string DtReservaGrupal::getHuespedesToString() {
    int i = 0;
    string res = "";
    while (i < MAX_HUESPEDES && huespedes[i] != nullptr) {
        res.append(huespedes[i]->getNombre()).append(" - ").append(huespedes[i]->getEmail()).append(" - ").append(huespedes[i]->getEsFingerToString());
        i++;
    }
    return res;
}

std::ostream &operator<<(std::ostream &os, DtReservaGrupal &reserva) {
    os << "Tipo Reserva: " << reserva.getTipoReserva() << std::endl;
    os << "Fecha check in: " << reserva.getCheckIn().format() << std::endl;
    os << "Fecha check out: " << reserva.getCheckOut().format() << std::endl;
    os << "Habitacion: " << reserva.getHabitacion() << std::endl;
    os << "Costo: $" << reserva.getCosto() << std::endl;
    os << "Huespedes: " << reserva.getHuespedesToString() << std::endl;

    return os;
}
