//
// Created by unzip on 19/3/22.
//

#include "DtReservaGrupal.h"

DtHuesped **DtReservaGrupal::getHuespedes() {
    return this->huespedes;
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

DtReservaGrupal::DtReservaGrupal(int codigo, DtFecha checkIn, DtFecha checkOut, EstadoReserva estado, float costo,
                                 int Habitacion, Huesped **hues) : DtReserva(codigo, checkIn, checkOut, estado, costo,
                                                                             Habitacion) {
    DtHuesped **dtHues = new DtHuesped *[MAX_HUESPEDES];
    int i = 0;
    while (i < MAX_HUESPEDES && hues[i] != nullptr) {
        dtHues[i] = new DtHuesped(hues[i]);
        i++;
    }
    while (i < MAX_HUESPEDES) {
        dtHues[i] = nullptr;
        i++;
    }
    this->huespedes = dtHues;
}


DtReservaGrupal::~DtReservaGrupal() {
    for (int i = 0; i < MAX_HUESPEDES; ++i) {
        delete huespedes[i];
    }
    delete[]huespedes;
}
