//#ifndef P4LABORATORIO0_MAIN
//#define P4LABORATORIO0_MAIN

#include <iostream>
#include "include/Sistema.h"
#include "datatypes/DtReservaGrupal.h"
#include "datatypes/DtReservaIndividual.h"

int main() {
    Sistema hub;
    int opcion = 0;
    do {
        cout
                << "Ingresar opción (1-Agregar Huesped , 2-Agregar Habitacion, 3-Obtener huespedes, 4-Obtener Habitaciones, 5-Registrar Reserva, 6-Obtener Reservas, 7-Salir)"
                << endl;
        cin >> opcion;
        switch (opcion) {
            case 1: {
                string name;
                string mail;
                int fing = 0;
                bool isFinger;
                cout << "Cual es su nombre?" << endl;
                cin >> name;
                cout << "Cual es su email?" << endl;
                cin >> mail;
                while (fing == 0) {
                    cout << "Es finger? (1-Si, 2-No)" << endl;
                    cin >> fing;
                    switch (fing) {
                        case 1:
                            isFinger = true;
                            break;
                        case 2:
                            isFinger = false;
                            break;
                        default:
                            cout << "Valor no aceptado, intentelo de nuevo." << endl;
                            fing = 0;
                            break;
                    }
                }
                hub.agregarHuesped(name, mail, isFinger);
                cout << "Nuevo huesped agregado" << endl;
                break;
            }
            case 2: {
                int numero;
                float precio;
                int capacidad;
                cout << "Cual es su numero?" << endl;
                cin >> numero;
                cout << "Cual es su precio?" << endl;
                cin >> precio;
                cout << "Cual es su capacidad?" << endl;
                cin >> capacidad;
                hub.agregarHabitacion(numero, precio, capacidad);
                cout << "Nueva habitacion agregada" << endl;
                break;
            }
            case 3:
//                hub.obtenerHuespedes()

                break;

            case 4: {
                int cantidadHab;
                DtHabitacion **habitaciones = hub.obtenerHabitaciones(cantidadHab);
                cout << "Las habitaciones son:" << endl;
                for (int i = 0; i < cantidadHab; i++) {
                    cout << habitaciones[i] << endl;
                }
                break;
            }
            case 5: {
//                hub.agregarReserva();
                break;
            }
            case 6: {
//                int cantReservas;
//                DtReserva **reservas = hub.obtenerReservas(cantReservas);
//                cout << "Las reservas son:" << endl;
//                for (int i = 0; i < cantReservas; i++) {
//                    cout << reservas[i] << endl;
//                }
//                break;
            }
            case 7:
                cout << "Gracias por utilizar nuestros sistemas" << endl << "Que tenga buen dia" << endl;
                break;
            default:
                cout << "Valor no aceptado, intentelo de nuevo." << endl;
                break;

        } // end switch
    } while (opcion != 7);
    return 0;
}



//int main() {
//    Sistema sistema;
//    DtFecha fecha1(1, 1, 2020);
//    DtFecha fecha2(1, 2, 2020);
//    sistema.agregarHuesped("pedro", "pedro@gmail.com", true);
//    sistema.agregarHuesped("Jose", "jose@gmail.com", true);
//
//    sistema.agregarHabitacion(1, 100, 5);
//    sistema.agregarHabitacion(2, 100, 5);
//
//    DtHuesped **huespedes = new DtHuesped *[2];
//    DtReservaGrupal reservaGrupal(1, fecha1, fecha2, Cerrada, 1000, 1, huespedes);
//    sistema.registrarReserva("pedro@gmail.com", &reservaGrupal);
//
//    DtReservaIndividual reservaIndividual(2, fecha1, fecha2, Cerrada, 1000, 1, true);
//    sistema.registrarReserva("pedro@gmail.com", &reservaIndividual);
//
//    int cont = 0;
//    std::cout << cont;
//    return 0;
//}


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
