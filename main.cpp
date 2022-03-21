//#ifndef P4LABORATORIO0_MAIN
//#define P4LABORATORIO0_MAIN

#include <iostream>
#include "include/Sistema.h"
#include "datatypes/DtReservaGrupal.h"
#include "datatypes/DtReservaIndividual.h"

DtHuesped *getHuespedBuscado(string basicString);

bool isHuespedRepetido(DtHuesped *huesped, DtHuesped **huespedes);

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
                string mail;
                string tipoReserva;

                cout << "ingrese el mail del reservante" << endl;
                cin >> mail;

                int dia1, dia2, mes1, mes2, anio1, anio2, codigo, hab;
                cout << "para continuar y agendar su reserva por favor ingrese el dia de check in" << endl;
                cin >> dia1;
                cout << "ingrese el mes" << endl;
                cin >> mes1;
                cout << "ingrese el anio" << endl;
                cin >> anio1;
                DtFecha fecha1 = DtFecha(dia1, mes1, anio1);

                cout << "para continuar y agendar su reserva por favor ingrese el dia de check out" << endl;
                cin >> dia2;
                cout << "ingrese el mes" << endl;
                cin >> mes2;
                cout << "ingrese el anio" << endl;
                cin >> anio2;
                DtFecha fecha2 = DtFecha(dia2, mes2, anio2);

                cout << "ingrese el codigo de su reserva" << endl;
                cin >> codigo;

                cout << "ingrese el numero de habitacion" << endl;
                cin >> hab;

                int cantidadHabitaciones;
                DtHabitacion **habitaciones = hub.obtenerHabitaciones(cantidadHabitaciones);
                int i = 0;
                int precio = -1;
                while (i < cantidadHabitaciones && precio == -1) {
                    if (habitaciones[i]->getNumero() == hab) {
                        precio = habitaciones[i]->getPrecio();
                    }
                }
                if (precio != -1) {
                    cout << "la reserva es grupal o individual? marque g por grupal e i por individual" << endl;
                    cin >> tipoReserva;
                    if (tipoReserva == "i") {
                        DtReservaIndividual *individual = new DtReservaIndividual(codigo, fecha1, fecha2, Abierta,
                                                                                  precio, hab, false);
                        hub.registrarReserva(mail, individual);
                        cout << "La reserva fue hecha con exito" << endl;
                        cout << *individual << endl;
                    } else if (tipoReserva == "g") {
                        DtHuesped **huespedes = new DtHuesped *[MAX_HUESPEDES];
                        int iter = 0;
                        int siOno = 1;
                        string email;
                        while (siOno) {
//                            cout << "escriba el email de un huesped" << endl;
//                            cin >> email;
//                            DtHuesped *maybeHuesped = getHuespedBuscado(hub, email);
//                            if (maybeHuesped != nullptr) {
//                                if (isHuespedRepetido(maybeHuesped, huespedes))
//                                    cout << "el huesped que acaba de ingresar ya se encuentra en esta reserva" << endl;
//                                else
//                                    huespedes[i] = maybeHuesped;
//                            } else {
//                                cout << "no se encontro a un huesped con el email ingresado" << endl;
//                            }
//                            cout << "desea ingresar a otro huesped? (1 - Si, 0 - No)" << endl;
//                            cin >> siOno;
//                        }
//                        DtReservaGrupal *grupal = new DtReservaGrupal(codigo, fecha1, fecha2, Abierta, precio, hab,
//                                                                      huespedes);
//                        hub.registrarReserva(mail, grupal);
//                        cout << "La reserva fue hecha con exito" << endl;
//                        cout << *grupal << endl;

                        }
                    } else {
                        cout << "Valor no aceptado, intentelo de nuevo." << endl;
                        break;
                    }
                } else {
                    cout << "no se encontro esa habitacion" << endl;
                    break;
                }
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
            case 7: {
                cout << "Gracias por utilizar nuestros sistemas" << endl << "Que tenga buen dia" << endl;
                break;
            }
            default: {
                cout << "Valor no aceptado, intentelo de nuevo." << endl;
                break;
            }

        } // end switch
    } while (opcion != 7);
    return 0;
}

//bool isHuespedRepetido(DtHuesped *huesped, DtHuesped **huespedes) {
//    int i = 0;
//    bool estaRepetido = false;
//    while (i < MAX_HUESPEDES && huespedes[i] != nullptr && !estaRepetido) {
//        if (huesped[i].getEmail() == huesped->getEmail()) {
//            estaRepetido = true;
//        }
//    }
//    return estaRepetido;
//}
//
//DtHuesped *getHuespedBuscado(Sistema hub, string email) {
//    DtHuesped** huespedes = hub.obtenerHuespedes();
//    int i = 0;
//    bool esta = false;
//    DtHuesped* res = nullptr;
//    while (i < MAX_HUESPEDES && huespedes[i] != nullptr && !esta) {
//        if (huespedes[i]->getEmail() == email) {
//            esta = true;
//            res = huespedes[i];
//        }
//        i++;
//    }
//    return res;
//}


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
