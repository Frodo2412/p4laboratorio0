//#ifndef P4LABORATORIO0_MAIN
//#define P4LABORATORIO0_MAIN

#include <iostream>
#include "include/Sistema.h"

int main() {
    Sistema sistema;
    sistema.agregarHabitacion(1, 1, 1);
    sistema.agregarHabitacion(2, 3, 4);
    int cont = 0;
    DtHabitacion** habs = sistema.obtenerHabitaciones(cont);
    std::cout << cont;
    return 0;
}


//int main() {
//    bool seguir = true;
//    Sistema system = Sistema();
//    while (seguir) {
//        int numero, capacidad;
//        float precio;
//        std::cout << "Ingresar numero de habitacion a agregar: " << std::endl;
//        std::cin >> numero;
//        std::cout << "Ingresar precio de la habitacion: ";
//        std::cin >> precio;
//        std::cout << "Ingresar capacidad de la habitacion: ";
//        std::cin >> capacidad;
//        try {
//            system.agregarHabitacion(numero, precio, capacidad);
//        } catch (...) {
//            std::cout << "Error inesperado al agregar la habitacion, seguramente el numero ya este utilizado" << std::endl;
//        }
//        std::cout << "si quiere realizar otra operacion ingrese 1, en otro caso ingrese 0" << std::endl;
//        std::cin >> seguir;
//    }
//    return 0;
//}
