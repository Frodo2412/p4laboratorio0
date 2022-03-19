//
// Created by brunolemus on 3/19/22.
//

#ifndef P4LABORATORIO0_DTFECHA_H
#define P4LABORATORIO0_DTFECHA_H


class DtFecha {
private:
    int dia{};
    int mes{};
    int anio{};
public:
    DtFecha();

    DtFecha(int, int, int);

    int getDia();

    int getMes();

    int getAnio();

    int operator-(DtFecha);
};


#endif //P4LABORATORIO0_DTFECHA_H
