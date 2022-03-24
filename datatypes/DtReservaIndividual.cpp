//
// Created by unzip on 19/3/22.
//

#include <ostream>
#include "DtReservaIndividual.h"


bool DtReservaIndividual::isPago() {
    return this->pagado;
}


DtReservaIndividual::DtReservaIndividual(ReservaIndividual *reserva) : DtReserva(reserva) {
    this->pagado = reserva->isPago();
}

DtReservaIndividual::DtReservaIndividual(int cod, DtFecha In, DtFecha Out, EstadoReserva estado, float costo, int hab,
                                         bool pago) : DtReserva(cod, In, Out, estado, costo, hab) {
    this->pagado = pago;
}

std::string DtReservaIndividual::isPagoToString() {
    std::string res;
    if (isPago())
        res = "Si";
    else
        res = "No";
    return res;
}

std::ostream &operator<<(std::ostream &os, DtReservaIndividual *reserva) {
    os << "Pagado: " << reserva->isPagoToString() << std::endl;

    return os;
}

ReservaIndividual *DtReservaIndividual::toCore(Huesped *huesped, class Habitacion *hab) {
    return new ReservaIndividual(this->codigo, huesped, hab, this->checkIn, this->checkOut, Abierta);
}

TipoReserva DtReservaIndividual::getTipoReserva() {
    return Individual;
}

string DtReservaIndividual::getTipoReservaToString() {
    return "Individual";
}
