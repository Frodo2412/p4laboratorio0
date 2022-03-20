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
    Huesped **hues = new Huesped *[MAX_HUESPEDES];
    int i = 0;
    while (i < MAX_HUESPEDES && this->huespedes[i] != nullptr) {
        hues[i] = this->huespedes[i]->toCore();
        i++;
    }
    return new ReservaGrupal(this->codigo, this->checkIn, this->checkOut, Abierta, huesped, hab, hues);
}
