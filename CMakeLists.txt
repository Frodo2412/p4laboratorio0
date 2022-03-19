cmake_minimum_required(VERSION 3.21)
project(p4laboratorio0)

set(CMAKE_CXX_STANDARD 14)

add_executable(p4laboratorio0 main.cpp src/Sistema.cpp include/Sistema.h datatypes/EstadoReserva.cpp datatypes/DtFecha.cpp datatypes/DtFecha.h)
