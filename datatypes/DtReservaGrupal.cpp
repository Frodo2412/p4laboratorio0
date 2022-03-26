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
    return new ReservaGrupal(this->codigo, this->checkIn, this->checkOut, Abierta, huesped, hab, this->huespedes);
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
    while (i < MAX_HUESPEDES && huespedes[i] != nullptr) {
        delete huespedes[i];
        i++;
    }
    delete[] huespedes;
}

TipoReserva DtReservaGrupal::getTipoReserva() {
    return Grupal;
}

string DtReservaGrupal::getTipoReservaToString() {
    return "Grupal";
}

std::ostream &operator<<(std::ostream &os, DtReservaGrupal *reserva) {
    DtHuesped** huespedes = reserva->getHuespedes();
    int i = 0;
    if (huespedes[i] != nullptr) {
        os << "Huespedes: " << huespedes[i] << endl;
        i++;
        while (i < MAX_HUESPEDES && huespedes[i] != nullptr) {
            os << "           " << huespedes[i] << endl;
            i++;
        }
    }
    return os;
}
