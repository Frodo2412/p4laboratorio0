#include <stdexcept>
#include "../include/Sistema.h"

Sistema::Sistema() {
    int i = 0;
    while (i < MAX_HABITACIONES) {
        this->habitaciones[i] = NULL;
        i++;
    }
    tope = 0;
}

void Sistema::agregarHuesped(string nombre, string email, bool esFinger){
    if (!isMailValido(email)){
        int i=0;
        bool salir = true;
        while(salir){
            if(huespedes[i] == nullptr){
                salir = false;
            }
            else
            i++;
        }
        huespedes[i] = new Huesped(nombre, email, esFinger);
    }else
        throw std::invalid_argument("Email existente");
}

void Sistema::agregarHabitacion(int numero, float precio, int capacidad) {
    if (hayEspacioParaHabitacion() && numeroNoAsignadoAHabitacion(numero)) {
        habitaciones[tope] = new Habitacion(numero, precio, capacidad);
        tope++;
    }
}

bool Sistema::numeroNoAsignadoAHabitacion (int numero) {
    int i = 0;
    bool res = true;
    while (i < tope && res) {
        if (habitaciones[i]->getNumero() == numero)
            res = false;
        i++;
    }
    if (!res)
        throw new std::invalid_argument("El numero de habitacion ya existe");
    return res;
}

bool Sistema::hayEspacioParaHabitacion() {
    return tope < MAX_HABITACIONES;
}

bool Sistema::isMailValido(string email){
    int i = 0;
    bool aparece = false;
    while (huespedes[i] != nullptr && !aparece){
       if(huespedes[i]->getEmail() == email){
           aparece = true;
       }
       i++;
    }
    return aparece;
}