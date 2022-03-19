//
// Created by unzip on 19/3/22.
//

#include "DtReservaGrupal.h"

DtHuesped *DtReservaGrupal::getHuespedes() {
    return *this->huespedes;
}

DtReservaGrupal::DtReservaGrupal() {

}

DtReservaGrupal::DtReservaGrupal(int cod, DtFecha In, DtFecha Out, EstadoReserva estado, float costo, int hab,
                                 DtHuesped *hues) {
    this->codigo = cod;
    this->checkIn = In;
    this->checkOut = Out;
    this->estado = estado;
    this->costo = costo;
    this->Habitacion = hab;

    int i = 0;
    while (i < MAX_HUESPEDES && &hues[i] != nullptr) {
        this->huespedes[i] = &hues[i];
        i++;
    }

}