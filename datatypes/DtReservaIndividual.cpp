//
// Created by unzip on 19/3/22.
//

#include "DtReservaIndividual.h"


bool DtReservaIndividual::isPago() {
    return this->pagado;
}

ReservaIndividual *DtReservaIndividual::toCore(Huesped *huesped, class Habitacion *hab) {
ReservaIndividual *DtReservaIndividual::toCore(Huesped *huesped, struct Habitacion *hab) {
    return new ReservaIndividual(this->codigo, huesped, hab, this->checkIn, this->checkOut, Abierta);
}

DtReservaIndividual::DtReservaIndividual(int codigo, DtFecha checkIn, DtFecha checkOut, EstadoReserva estado,
                                         float costo, int habitacion, bool isPago) : DtReserva(codigo, checkIn,
                                                                                               checkOut, estado,
                                                                                               costo, habitacion) {
    this->pagado = isPago;
}
