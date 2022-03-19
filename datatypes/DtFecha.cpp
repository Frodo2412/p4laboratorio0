//
// Created by brunolemus on 3/19/22.
//

#include "DtFecha.h"
#include <iostream>
#include <cmath>

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
    if (d < 0 || d > 30)
        throw std::invalid_argument("Dia invalido");
    if (m < 0 || 12 < m)
        throw std::invalid_argument("Mes invalido");
    if (a < 1901)
        throw std::invalid_argument("Anio invalido");
    dia = d;
    mes = m;
    anio = a;
}

DtFecha::DtFecha() {
    this->anio = 1901;
    this->mes = 1;
    this->dia = 1;
}

int DtFecha::operator-(DtFecha fecha) {

    int thisFecha = this->anio * 365 + this->mes * 30 + this->dia;
    int ultimaFecha = fecha.anio * 365 + fecha.mes * 30 + fecha.dia;

    return abs(thisFecha - ultimaFecha);
}
