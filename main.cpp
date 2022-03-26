//#ifndef P4LABORATORIO0_MAIN
//#define P4LABORATORIO0_MAIN

#include <iostream>
#include "include/Sistema.h"
#include "datatypes/DtReservaGrupal.h"
#include "datatypes/DtReservaIndividual.h"

void dibujarMenu() {
    cout
            << "Ingresar opción: " << endl << "1- Agregar Huesped" << endl << "2- Agregar Habitacion" << endl
            << "3- Obtener huespedes" << endl << "4- Obtener Habitaciones" << endl << "5- Registrar Reserva" << endl
            << "6- Obtener Reservas" << endl << "7- Salir" << endl;
}

DtFecha leerFecha() {
    int dia, mes, anio;
    cin >> dia >> mes >> anio;
    try {
        return {dia, mes, anio};
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
        return leerFecha();
    }
}

bool leerBoolean() {
    int ret;
    cin >> ret;
    if (ret == 1)
        return true;
    else if (ret == 0)
        return false;
    else {
        cout << "Ingrese 1 o 0" << endl;
        return leerBoolean();
    }
}

bool leerBooleanParaContinuar() {
    int ret;
    cout << "Ingrese 1 si quiere seguir ingresando huespedes, 0 en otro caso" << endl;
    cin >> ret;
    if (ret == 1)
        return true;
    else
        return false;
}

void leerHuesped(Sistema &sistema) {
    string name, mail;
    bool isFinger;
    cout << "Cual es su nombre?" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Cual es su email?" << endl;
    cin >> mail;
    cout << "Es finger? (1-Si, 0-No)" << endl;
    isFinger = leerBoolean();
    try {
        sistema.agregarHuesped(name, mail, isFinger);
        cout << "Nuevo huesped agregado" << endl;
    } catch (std::invalid_argument &ex) {
        cout << "El mail que acaba de ingresar ya se encuentra registrado." << endl;
    }
}

void leerHabitacion(Sistema &sistema) {
    int numero;
    float precio;
    int capacidad;
    cout << "Cual es su numero?" << endl;
    cin >> numero;
    cout << "Cual es su precio?" << endl;
    cin >> precio;
    cout << "Cual es su capacidad?" << endl;
    cin >> capacidad;
    try {
        sistema.agregarHabitacion(numero, precio, capacidad);
        cout << "Nueva habitacion agregada" << endl;
    } catch (std::invalid_argument &ex) {
        cout << "Ya se encuentra una habitacion con ese numero." << endl;
    }
}

void emitirHuespedes(Sistema &sistema) {
    int cantHuesp = 0;
    DtHuesped **huespedesAux = sistema.obtenerHuespedes(cantHuesp);
    for (int i = 0; i < cantHuesp; ++i) {
        cout << huespedesAux[i] << endl;
        delete huespedesAux[i];
    }
    delete[]huespedesAux;
}

void emitirHabitaciones(Sistema &sistema) {
    int cantidadHab = 0;
    DtHabitacion **habitaciones = sistema.obtenerHabitaciones(cantidadHab);
    for (int i = 0; i < cantidadHab; i++) {
        cout << habitaciones[i] << endl;
        delete habitaciones[i];
    }
    if (cantidadHab == 0)
        cout << "No hay habitaciones registradas" << endl;
    delete[]habitaciones;
}

void ingresarReserva(Sistema &sistema) {
    string mail;
    int tipoReserva, hab;

    cout << "Ingrese el mail del reservante:" << endl;
    cin >> mail;
    bool isMayor = false;
    DtFecha fecha1;
    DtFecha fecha2;
    do {
        cout << "Por favor ingrese la fecha de check in (DD MM AAAA)" << endl;
        fecha1 = leerFecha();

        cout << "Por favor ingrese la fecha de check out (DD MM AAAA)" << endl;
        fecha2 = leerFecha();
        isMayor = (fecha1 <= fecha2);
        if (!isMayor) cout << "Ingrese un checkout despues del checkin." << endl;
    } while (!isMayor);

    cout << "Ingrese el numero de habitacion que quiere reservar:" << endl;
    cin >> hab;

    int cantidadHabitaciones = 0;
    DtHabitacion **habitaciones = sistema.obtenerHabitaciones(cantidadHabitaciones);
    int i = 0;
    do {
        cout << "Seleccione el tipo de reserva (1- Individual, 2- Grupal)" << endl;
        cin >> tipoReserva;
        switch (tipoReserva) {
            case 1: {
                bool isPaga;
                cout << "La reserva fue paga? (1-Si , 0-No)" << endl;
                isPaga = leerBoolean();
                auto *individual = new DtReservaIndividual(sistema.getNuevoCodigoReserva(), fecha1, fecha2, Abierta, 0, hab, isPaga);
                try {
                    sistema.registrarReserva(mail, individual);
                    cout << "La reserva fue hecha con exito" << endl;
                } catch (invalid_argument &ex) {
                    cout << ex.what() << endl << "Intentelo de nuevo" << endl;
                }
                delete individual;
                break;
            }
            case 2: {
                auto **huespedes = new DtHuesped *[MAX_HUESPEDES];
                bool siOno = true;
                string email;
                cout
                        << "A continuacion se le van a pedir los emails de los huepedes que forman parte de la reserva"
                        << endl;
                int cantHuespedes = 0;
                DtHuesped **huespedesAux = sistema.obtenerHuespedes(cantHuespedes);
                int agregados = 0;
                do {
                    cout << endl << "Escriba el email de un huesped" << endl;
                    cin >> email;
                    DtHuesped *maybeHuesped = nullptr;
                    i = 0;
                    while (i < cantHuespedes && huespedesAux[i] != nullptr) {
                        if (huespedesAux[i]->getEmail() == email)
                            maybeHuesped = huespedesAux[i]->copy();
                        i++;
                    }
                    if (maybeHuesped != nullptr) {
                        huespedes[agregados] = maybeHuesped;
                        agregados++;
                    } else {
                        cout << "No se encontro a un huesped con el email ingresado" << endl;
                    }
                    siOno = leerBooleanParaContinuar();
                } while (siOno);
                for (int j = 0; j < cantHuespedes; j++) {
                    delete huespedesAux[j];
                }
                delete[]huespedesAux;
                auto *grupal = new DtReservaGrupal(sistema.getNuevoCodigoReserva(), fecha1, fecha2, Abierta, 0, hab, huespedes);
                try {
                    sistema.registrarReserva(mail, grupal);
                    cout << "La reserva fue hecha con exito" << endl;
                } catch (std::invalid_argument &ex) {
                    cout << ex.what() << "Intentelo de nuevo" << endl;
                }
                int j = 0;
                while (j < MAX_HUESPEDES && huespedes[j] != nullptr) {
                    delete huespedes[j];
                    j++;
                }
                delete[]huespedes;
                break;
            }
            default:
                cout << "Valor no aceptado, intentelo de nuevo." << endl;
                break;
        }
    } while (tipoReserva != 1 && tipoReserva != 2);
    for (int j = 0; j < cantidadHabitaciones; j++) {
        delete habitaciones[j];
    }
    delete[]habitaciones;
}

void emitirReservas(Sistema &sistema) {
    int cantReservas = 0;
    cout << "Para continuar seleccione la fecha de la que quiere obtener las reservas:" << endl;
    DtFecha fecha = leerFecha();
    DtReserva **reservas = sistema.obtenerReservas(fecha, cantReservas);
    if (cantReservas == 0)
        cout << "No hay reservas en esa fecha" << endl;
    else {
        for (int i = 0; i < cantReservas; i++) {
            cout << reservas[i] << endl;
            delete reservas[i];
        }
    }
    delete[]reservas;
}

int main() {
    Sistema hub;
    int opcion = 0;
    do {
        dibujarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1: {
                leerHuesped(hub);
                break;
            }
            case 2: {
                leerHabitacion(hub);
                break;
            }
            case 3: {
                emitirHuespedes(hub);
                break;
            }
            case 4: {
                emitirHabitaciones(hub);
                break;
            }
            case 5: {
                ingresarReserva(hub);
                break;
            }
            case 6: {
                emitirReservas(hub);
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

        }
    } while (opcion != 7);
    return 0;
}

#pragma clang diagnostic pop