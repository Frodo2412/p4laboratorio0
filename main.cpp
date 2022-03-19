#include <iostream>
#include "include/ReservaGrupal.h"


int main() {
    DtFecha hoy(19, 3, 2022);
    DtFecha proxima(20, 3, 2022);
    Huesped yo("Bruno", "brunlemus@gmail.com", true);
    Habitacion miCasa(1, 100, 4);

    std::cout << yo.isFinger();
    Huesped losPibes[3] = {{"Bruno Lemus",   "brunlemus553@gmail.com", true},
                           {"Guillermo Rey", "guillerey@gmail.com",    true},
                           {"Dylan Smyth",   "dylan@gmail.com",        true}};
    ReservaGrupal reserva = ReservaGrupal(1, hoy, proxima, Abierta, yo, miCasa, losPibes);

    std::cout << reserva.getHuesped()->getNombre();
}
