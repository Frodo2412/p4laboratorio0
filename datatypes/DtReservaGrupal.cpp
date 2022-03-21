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
