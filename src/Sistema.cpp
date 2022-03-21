#include <stdexcept>
#include "../include/Sistema.h"

Sistema::Sistema() {
//    int i = 0;
//    while (i < MAX_HABITACIONES) {
//        this->habitaciones[i] = nullptr;
//        this->huespedes[i] = nullptr;
//        this->reservas[i] = nullptr;
//        i++;
//    }
    habitacionesOcupadas = 0;
    cantHuespedes = 0;
    cantReservas = 0;
}

void Sistema::agregarHuesped(string nombre, string email, bool esFinger) {
    if (existsHuespedWithEmail(email))
        throw std::invalid_argument("El numero de habitacion ya existe");
    if (hayEspacioParaHabitacion()) {
        huespedes[cantHuespedes] = new Huesped(nombre, email, esFinger);
        cantHuespedes++;
    }
}

void Sistema::agregarHabitacion(int numero, float precio, int capacidad) {
    if (existsHabitacionWithNumero(numero))
        throw std::invalid_argument("El numero de habitacion ya existe");
    if (hayEspacioParaHabitacion()) {
        habitaciones[habitacionesOcupadas] = new Habitacion(numero, precio, capacidad);
        habitacionesOcupadas++;
    }
}

bool Sistema::existsHabitacionWithNumero(int numero) {
    int i = 0;
    bool res = false;
    while (i < habitacionesOcupadas && !res) {
        if (habitaciones[i]->getNumero() == numero)
            res = true;
        i++;
    }
    return res;
}

bool Sistema::hayEspacioParaHabitacion() {
    return habitacionesOcupadas < MAX_HABITACIONES;
}

DtHabitacion **Sistema::obtenerHabitaciones(int &cantHabitaciones) {
    DtHabitacion **habs = new DtHabitacion *[habitacionesOcupadas];
    int i = 0;
    while (i < habitacionesOcupadas) {
        habs[i] = new DtHabitacion(habitaciones[i]->getNumero(),habitaciones[i]->getPrecio(),habitaciones[i]->getCapacidad());
        i++;
    }
    cantHabitaciones = habitacionesOcupadas;
    return habs;
}
DtHuesped **Sistema::obtenerHuespedes(int &cantHuespedes) {
    DtHuesped **hues = new DtHuesped *[cantHuespedes];
    int i = 0;
    while(i < cantHuespedes){
        hues[i] = new DtHuesped(huespedes[i]->getNombre(),huespedes[i]->getEmail(),huespedes[i]->isFinger());
        i++;
    }
    cantHuespedes = this->cantHuespedes;
    return hues;
}

bool Sistema::existsHuespedWithEmail(string email) {
    int i = 0;
    bool aparece = false;
    while (huespedes[i] != nullptr && !aparece) {
        if (huespedes[i]->getEmail() == email) {
            aparece = true;
        }
        i++;
    }
    return aparece;
}

void Sistema::registrarReserva(string email, DtReserva *reserva) {
    if (!existsHuespedWithEmail(email))
        throw std::invalid_argument("No existe usuario con ese mail");
    if (!existsHabitacionWithNumero(reserva->getHabitacion()))
        throw std::invalid_argument("No existe habitacion con ese numero");
    if (!hayEspacioParaReserva())
        throw std::invalid_argument("No hay espacio para reservas");

    Huesped *huesped = getHuespedWithEmail(email);
    Habitacion *habitacion = getHabitacionWithNumero(reserva->getHabitacion());
    Reserva *res = reserva->toCore(huesped, habitacion);
    reservas[cantReservas] = res;
    cantReservas++;
}

bool Sistema::hayEspacioParaReserva() {
    return cantReservas < MAX_RESERVAS;
}

Huesped *Sistema::getHuespedWithEmail(string email) {
    int i = 0;
    while (huespedes[i]->getEmail() != email) {
        i++;
    }
    return huespedes[i];
}

Habitacion *Sistema::getHabitacionWithNumero(int numero) {
    int i = 0;
    while (habitaciones[i]->getNumero() != numero) {
        i++;
    }
    return habitaciones[i];
}
