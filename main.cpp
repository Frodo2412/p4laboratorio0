//#ifndef P4LABORATORIO0_MAIN
//#define P4LABORATORIO0_MAIN

#include <iostream>
#include "include/Sistema.h"
#include "datatypes/DtReservaGrupal.h"
#include "datatypes/DtReservaIndividual.h"

int main() {
    Sistema sistema;
    DtFecha fecha1(1, 1, 2020);
    DtFecha fecha2(1, 2, 2020);
    sistema.agregarHuesped("pedro", "pedro@gmail.com", true);
    sistema.agregarHuesped("Jose", "jose@gmail.com", true);

    sistema.agregarHabitacion(1, 100, 5);
    sistema.agregarHabitacion(2, 100, 5);

    DtHuesped **huespedes = new DtHuesped *[2];
    DtReservaGrupal reservaGrupal(1, fecha1, fecha2, Cerrada, 1000, 1, huespedes);
    sistema.registrarReserva("pedro@gmail.com", &reservaGrupal);

    DtReservaIndividual reservaIndividual(2, fecha1, fecha2, Cerrada, 1000, 1, true);
    sistema.registrarReserva("pedro@gmail.com", &reservaIndividual);

    int cont = 0;
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
