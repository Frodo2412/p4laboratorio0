//
// Created by brunolemus on 3/19/22.
//

#include "DtFecha.h"

int DtFecha::getDia() {
    return dia;
}

int DtFecha::getMes() {
    return mes;
}

int DtFecha::getAnio() {
    return anio;
}

DtFecha::DtFecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

DtFecha::DtFecha() {
}