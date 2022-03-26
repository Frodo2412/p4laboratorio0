
OBJETOS = src/Habitacion.o src/Huesped.o src/Reserva.o src/ReservaGrupal.o \
 src/ReservaIndividual.o src/Sistema.o datatypes/DtReservaIndividual.o \
 datatypes/DtReservaGrupal.o datatypes/DtReserva.o \
 datatypes/DtHuesped.o datatypes/DtHabitacion.o datatypes/DtFecha.o

AUX = utils.o TipoReserva.o EstadoReserva.o

OBJRESERVA = datatypes/DtFecha.o EstadoReserva.o TipoReserva.o src/Habitacion.o src/Huesped.o

OBJGRUPAL = src/Reserva.o src/Huesped.o datatypes/DtHuesped.o utils.o

OBJDTRESERVA = datatypes/DtFecha.o src/Habitacion.o src/Huesped.o src/Reserva.o

OBJDTGRUPAL = datatypes/DtHuesped.o src/ReservaGrupal.o datatypes/DtReserva.o utils.o

OBJSISTEMA = src/Reserva.o datatypes/DtReserva.o datatypes/DtHabitacion.o datatypes/DtHuesped.o utils.o

OPCIONES = -g -Wall
CC = g++

FUENTES = main.cpp src/Habitacion.cpp src/Huesped.cpp \
 src/Reserva.cpp src/ReservaGrupal.cpp \
 src/ReservaIndividual.cpp src/Sistema.cpp \
 include/Habitacion.h include/Huesped.h include/Reserva.h \
 include/ReservaIndividual.h include/ReservaGrupal.h \
 include/Sistema.h include/utils.h datatypes/DtFecha.h datatypes/DtFecha.cpp \
 datatypes/DtHabitacion.h datatypes/DtHabitacion.cpp datatypes/DtHuesped.h \
 datatypes/DtHuesped.cpp  datatypes/DtReserva.cpp datatypes/DtReserva.h \
 datatypes/DtReservaGrupal.cpp datatypes/DtReservaGrupal.h datatypes/DtReservaIndividual.cpp \
 datatypes/DtReservaIndividual.h datatypes/EstadoReserva.h datatypes/TipoReserva.h \
 ej2/* resp_lab0.txt integrantes.txt

FingVMB: $(OBJETOS) $(AUX) main.cpp Makefile
	$(CC) $(OPCIONES) -o FingVMB main.cpp $(OBJETOS)

Sistema.o: $(OBJSISTEMA) src/Sistema.cpp include/Sistema.h
	$(CC) $(OPCIONES) -c -o Sistema.o Sistema.cpp $(OBJSISTEMA)

Habitacion.o: src/Habitacion.cpp include/Habitacion.h
	$(CC) $(OPCIONES) -c -o Habitacion.o habitacion.cpp

Huesped.o: src/Huesped.cpp include/Huesped.h
	$(CC) $(OPCIONES) -c -o Habitacion.o habitacion.cpp

Reserva.o: $(OBJRESERVA) src/Reserva.cpp include/Reserva.h
	$(CC) $(OPCIONES) -c -o Reserva.o Reserva.cpp $(OBJRESERVA)

ReservaGrupal.o: $(OBJGRUPAL) src/ReservaGrupal.cpp include/ReservaGrupal.h
	$(CC) $(OPCIONES) -c -o ReservaGrupal.o ReservaGrupal.cpp $(OBJGRUPAL)

ReservaIndividual.o: src/Reserva.o src/ReservaIndividual.cpp include/ReservaIndividual.h
	$(CC) $(OPCIONES) -c -o ReservaIndividual.o ReservaIndividual.cpp src/Reserva.o

DtReserva.o: $(OBJDTRESERVA) datatypes/DtReserva.cpp datatypes/DtReserva.h
	$(CC) $(OPCIONES) -c -o DtReserva.o DtReserva.cpp $(OBJDTRESERVA)

DtReservaIndividual.o: datatypes/DtReserva.o src/ReservaIndividual.o datatypes/DtReservaIndividual.cpp datatypes/DtReservaIndividual.h
	$(CC) $(OPCIONES) -c -o DtReservaIndividual.o DtReservaIndividual.cpp datatypes/DtReserva.o src/ReservaIndividual.o

DtReservaGrupal.o: $(OBJDTGRUPAL) datatypes/DtReservaGrupal.cpp datatypes/DtReserva.h
	$(CC) $(OPCIONES) -c -o DtReservaGrupal.o DtReservaGrupal.cpp $(OBJDTGRUPAL)


DtHuesped.o: src/Huesped.o datatypes/DtHuesped.cpp datatypes/DtHuesped.h
	 $(CC) $(OPCIONES) -c -o DtReservaGrupal.o DtReservaGrupal.cpp src/Huesped.o


DtHabitacion.o: src/Habitacion.o datatypes/DtHabitacion.cpp datatypes/DtHabitacion.h
	$(CC) $(OPCIONES) -c -o DtHabitacion.o DtHabitacion.cpp src/Habitacion.o


DtFecha: datatypes/DtFecha.cpp datatypes/DtFecha.h
	$(CC) $(OPCIONES) -c -o DtFecha.o DtFecha.cpp

utils.o: include/utils.h
	$(CC) $(OPCIONES) -c -o utils.o include/utils.h

EstadoReserva.o: datatypes/EstadoReserva.h
	$(CC) $(OPCIONES) -c -o EstadoReserva.o datatypes/EstadoReserva.h

TipoReserva.o: datatypes/TipoReserva.h
	$(CC) $(OPCIONES) -c -o TipoReserva.o datatypes/TipoReserva.h

clean:
	rm -f $(OBJETOS) $(AUX) FingVMB

rebuild:
	make clean
	make

entrega: $(FUENTES) Makefile
	rm -f 45_lab0.tar.gz
	tar -cvf 45_lab0.tar $(FUENTES) Makefile
	gzip 45_lab0.tar
