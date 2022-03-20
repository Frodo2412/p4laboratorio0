cmake_minimum_required(VERSION 3.21)
project(p4laboratorio0)

set(CMAKE_CXX_STANDARD 14)


add_executable(p4laboratorio0 main.cpp src/Sistema.cpp include/Sistema.h datatypes/EstadoReserva.h datatypes/DtFecha.cpp datatypes/DtFecha.h datatypes/DtHabitacion.cpp datatypes/DtHabitacion.h datatypes/DtHuesped.cpp datatypes/DtHuesped.h src/Habitacion.cpp include/Habitacion.h src/Huesped.cpp include/Huesped.h datatypes/DtReserva.cpp datatypes/DtReserva.h datatypes/DtReservaGrupal.cpp datatypes/DtReservaGrupal.h datatypes/DtReservaIndividual.cpp datatypes/DtReservaIndividual.h src/Reserva.cpp include/Reserva.h src/ReservaIndividual.cpp include/ReservaIndividual.h include/utils.h src/ReservaGrupal.cpp include/ReservaGrupal.h)

