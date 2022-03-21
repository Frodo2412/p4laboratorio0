//
// Created by unzip on 19/3/22.
//

#include "DtReservaIndividual.h"


bool DtReservaIndividual::isPago() {
    return this->pagado;
}

ReservaIndividual *DtReservaIndividual::toCore(Huesped *huesped, struct Habitacion *hab) {
    return new ReservaIndividual(this->codigo, huesped, hab, this->checkIn, this->checkOut, Abierta);
}

DtReservaIndividual::DtReservaIndividual(ReservaIndividual *reserva) : DtReserva(reserva) {
    this->pagado = reserva->isPago();
}

DtReservaIndividual::DtReservaIndividual(int cod, DtFecha In, DtFecha Out, EstadoReserva estado, float costo, int hab,
                                         bool pago) : DtReserva(cod, In, Out, estado, costo, hab) {
    this->pagado = pago;
}
