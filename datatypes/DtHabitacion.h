//
// Created by brunolemus on 3/19/22.
//

#ifndef P4LABORATORIO0_DTHABITACION_H
#define P4LABORATORIO0_DTHABITACION_H


class DtHabitacion {
private:
    int numero;
    float precio;
    int capacidad;
public:
    DtHabitacion();

    DtHabitacion(int, float, int);

    int getNumero();

    float getPrecio();

    int getCapacidad();
};

#endif //P4LABORATORIO0_DTHABITACION_H
