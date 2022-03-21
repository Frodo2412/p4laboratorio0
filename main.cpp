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
                do {
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
                            break;
                    }
                } while (fing != 1 && fing != 2);
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
            case 3: {
                int cantHuesp = 0;
                DtHuesped **huespedesAux = hub.obtenerHuespedes(cantHuesp);
                for (int i = 0; i < cantHuesp; ++i) {
                    cout << huespedesAux[i] << endl;
                }
                for (int j = 0; j < cantHuesp; ++j) {
                    delete huespedesAux[j];
                }
                delete[]huespedesAux;
                break;
            }
            case 4: {
                int cantidadHab = 0;
                DtHabitacion **habitaciones = hub.obtenerHabitaciones(cantidadHab);
                cout << "Las habitaciones son:" << endl;
                for (int i = 0; i < cantidadHab; i++) {
                    cout << habitaciones[i] << endl;
                }
                for (int j = 0; j < cantidadHab; ++j) {
                    delete habitaciones[j];
                }
                delete[]habitaciones;
                break;
            }
            case 5: {
                string mail;
                int tipoReserva;

                cout << "Ingrese el mail del reservante:" << endl;
                cin >> mail;

                int dia1, dia2, mes1, mes2, anio1, anio2, codigo, hab;
                cout << "Para continuar y agendar su reserva por favor ingrese la fecha de check in" << endl;
                cout << "Ingrese el dia:" << endl;
                cin >> dia1;
                cout << "ingrese el mes:" << endl;
                cin >> mes1;
                cout << "ingrese el anio:" << endl;
                cin >> anio1;
                DtFecha fecha1 = DtFecha(dia1, mes1, anio1);

                cout << "Ahora por favor ingrese la fecha de check out" << endl;
                cout << "Ingrese el dia:" << endl;
                cin >> dia2;
                cout << "ingrese el mes" << endl;
                cin >> mes2;
                cout << "ingrese el anio" << endl;
                cin >> anio2;
                DtFecha fecha2 = DtFecha(dia2, mes2, anio2);

                cout << "Ingrese un codigo (en numeros) que identificaran su reserva:" << endl;
                cin >> codigo;

                cout << "Ingrese el numero de habitacion que quiere reservar:" << endl;
                cin >> hab;

                int cantidadHabitaciones = 0;
                DtHabitacion **habitaciones = hub.obtenerHabitaciones(cantidadHabitaciones);
                int i = 0;
                float precio = -1;
                while (i < cantidadHabitaciones) {
                    if (habitaciones[i]->getNumero() == hab) {
                        precio = habitaciones[i]->getPrecio();
                        break;
                    }
                    i++;
                }
                do {
                    cout << "Seleccione el tipo de reserva (1- Individual, 2- Grupal)" << endl;
                    cin >> tipoReserva;
                    switch (tipoReserva) {
                        case 1: {
                            bool isOk = true;
                            auto *individual = new DtReservaIndividual(codigo, fecha1, fecha2,
                                                                                      Abierta,
                                                                                      precio, hab, false);
                            try {
                                hub.registrarReserva(mail, individual);
                            } catch (std::invalid_argument ex) {
                                cout << ex.what() << endl << "Intentelo de nuevo" << endl;
                                isOk = false;
                            }
                            if (isOk) {
                                cout << "La reserva fue hecha con exito" << endl;
                                cout << *individual << endl;
                            }
                            delete individual;
                            break;
                        }
                        case 2: {
                            auto **huespedes = new DtHuesped *[MAX_HUESPEDES];
                            int siOno = 1;
                            string email;
                            cout
                                    << "A continuacion se le van a pedir los emails de los huepedes que forman parte de la reserva"
                                    << endl;
                            do {
                                cout << "escriba el email de un huesped" << endl;
                                cin >> email;
                                DtHuesped *maybeHuesped = nullptr;
                                int cantHuespedes = 0;
                                DtHuesped **huespedesAux = hub.obtenerHuespedes(cantHuespedes);
                                i = 0;
                                while (i < cantHuespedes) {
                                    if (huespedesAux[i]->getEmail() == email) {
                                        maybeHuesped = huespedesAux[i];
                                        break;
                                    }
                                    i++;
                                }
                                if (maybeHuesped != nullptr) {
                                    huespedes[i] = maybeHuesped;
                                } else {
                                    cout << "No se encontro a un huesped con el email ingresado" << endl;
                                }
                                for (int j = 0; j < cantHuespedes; ++j) {
                                    delete huespedesAux[i];
                                }
                                delete[]huespedesAux;
                                cout << "Desea ingresar a otro huesped? (1 - Si, 0 - No)" << endl;
                                cin >> siOno;
                            } while (siOno != 0);
                            auto *grupal = new DtReservaGrupal(codigo, fecha1, fecha2, Abierta, precio, hab,
                                                               huespedes);
                            try {
                                hub.registrarReserva(mail, grupal);
                                cout << "La reserva fue hecha con exito" << endl;
                                cout << *grupal << endl;
                            } catch (std::invalid_argument ex) {
                                cout << ex.what() << endl;
                            }
                            int j = 0;
                            while (j < MAX_HUESPEDES && huespedes[i] != nullptr) {
                                delete huespedes[i];
                                j++;
                            }
                            delete[]huespedes;
                        }
                        default:
                            cout << "Valor no aceptado, intentelo de nuevo." << endl;
                            break;
                    }
                } while (tipoReserva != 1 && tipoReserva != 2);
                for (int j = 0; j < cantidadHabitaciones; ++j) {
                    delete habitaciones[i];
                }
                delete[]habitaciones;
            }
            case 6: {
                int cantReservas = 0;
                int dia, mes, anio;
                cout << "Para continuar seleccione la fecha de la que quiere obtener las reservas:" << endl;
                cout << "Ingrese el dia:" << endl;
                cin >> dia;
                cout << "ingrese el mes:" << endl;
                cin >> mes;
                cout << "ingrese el anio:" << endl;
                cin >> anio;
                DtFecha fecha = DtFecha(dia, mes, anio);
                DtReserva **reservas = hub.obtenerReservas(fecha, cantReservas);
                cout << "Las reservas son:" << endl;
                if (cantReservas == 0)
                    cout << "No hay reservas en esa fecha" << endl;
                else {
                    for (int i = 0; i < cantReservas; i++) {
                        cout << reservas[i] << endl;
                    }
                }
                for (int j = 0; j < cantReservas; ++j) {
                    delete reservas[j];
                }
                delete[]reservas;
                break;
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
