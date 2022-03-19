
#ifndef P4LABORATORIO0_HABITACION_H
#define P4LABORATORIO0_HABITACION_H


#include "../datatypes/DtHabitacion.h"

class Habitacion {
private:
    int numero;
    float precio;
    int capacidad;
public:
    Habitacion(int = 0, float = 0, int = 0);

    int getNumero();

    float getPrecio();

    int getCapacidad();

    void setPrecio(float);

    void setCapacidad(int);

    DtHabitacion toDt();
};


#endif //P4LABORATORIO0_HABITACION_H
