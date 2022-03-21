#include "DtReservaGrupal.h"

DtReservaGrupal::DtReservaGrupal(int cod, DtFecha In, DtFecha Out, EstadoReserva estado, float costo, int hab,
                                 DtHuesped **hues) : DtReserva(cod, In, Out, estado, costo, hab) {
    int i = 0;
    while (i < MAX_HUESPEDES && hues[i] != nullptr) {
        this->huespedes[i] = hues[i];
        i++;
    }
    while (i < MAX_HUESPEDES) {
        this->huespedes[i] = nullptr;
        i++;
    }
}

DtHuesped **DtReservaGrupal::getHuespedes() {
    return this->huespedes;
}

ReservaGrupal *DtReservaGrupal::toCore(Huesped *huesped, class Habitacion *hab) {
    return new ReservaGrupal(this->codigo, this->checkIn, this->checkOut, Abierta, huesped, hab, this->getHuespedes());
}

DtReservaGrupal::DtReservaGrupal(ReservaGrupal *reserva) : DtReserva(reserva) {
    int i = 0;
    while (i < MAX_HUESPEDES && reserva->getHuespedes()[i] != nullptr) {
        huespedes[i] = new DtHuesped(reserva->getHuespedes()[i]);
        i++;
    }
    while (i < MAX_HUESPEDES) {
        huespedes[i] = nullptr;
        i++;
    }
}


DtReservaGrupal::~DtReservaGrupal() {
    int i = 0;
    while(i < MAX_HUESPEDES && huespedes[i] != nullptr) {
        delete huespedes[i];
        i++;
    }
    delete [] huespedes;
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
