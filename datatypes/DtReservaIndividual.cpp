//
// Created by unzip on 19/3/22.
//

#include "DtReservaIndividual.h"


bool DtReservaIndividual::isPago() {
    return this->pagado;
}

DtReservaIndividual::DtReservaIndividual(int cod, DtFecha In, DtFecha Out, EstadoReserva estado, float costo, int hab,
                                         bool pag) {
    this->codigo = cod;
    this->checkIn = In;
    this->checkOut = Out;
    this->estado = estado;
    this->costo = costo;
    this->Habitacion = hab;
    this->pagado = pag;
}

ReservaIndividual *DtReservaIndividual::toCore(Huesped *huesped, class Habitacion *hab) {
    return new ReservaIndividual(this->codigo, huesped, hab, this->checkIn, this->checkOut, Abierta);
}