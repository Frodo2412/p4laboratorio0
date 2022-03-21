
#include "../include/Habitacion.h"

int Habitacion::getNumero() {
    return numero;
}

float Habitacion::getPrecio() {
    return precio;
}

int Habitacion::getCapacidad() {
    return capacidad;
}

void Habitacion::setPrecio(float p) {
    precio = p;
}

void Habitacion::setCapacidad(int c) {
    capacidad = c;
}

Habitacion::Habitacion(int num, float pr, int cap) {
    this->numero = num;
    this->precio = pr;
    this->capacidad = cap;
}

//DtHabitacion *Habitacion::toDt() {
//    return new DtHabitacion(numero, precio, capacidad);
//}
