
OBJETOS = src/Habitacion.o src/Huesped.o src/Reserva.o src/ReservaGrupal.o \
 src/ReservaIndividual.o src/Sistema.o datatypes/DtReservaIndividual.o \
 datatypes/DtReservaGrupal.o datatypes/DtReserva.o \
 datatypes/DtHuesped.o datatypes/DtHabitacion.o datatypes/DtFecha.o

OBJRESERVA = datatypes/DtFecha.o datatypes/EstadoReserva.o datatypes/TipoReserva.o src/Habitacion.o src/Huesped.o

OBJGRUPAL = src/Reserva.o src/Huesped.o datatypes/DtHuesped.o

OBJDTRESERVA = datatypes/DtFecha.o src/Habitacion.o src/Huesped.o src/Reserva.o

OBJDTGRUPAL = datatypes/DtHuesped.o src/ReservaGrupal.o datatypes/DtReserva.o

OBJSISTEMA = src/Reserva.o datatypes/DtReserva.o datatypes/DtHabitacion.o datatypes/DtHuesped.o

AUX = include/utils.h datatypes/TipoReserva.h datatypes/EstadoReserva.h

OPCIONES = -g -Wall
CC = g++

FUENTES = main.cpp src/Habitacion.cpp src/Huesped.cpp \
 src/Reserva.cpp src/ReservaGrupal.cpp \
 src/ReservaIndividual.cpp src/Sistema.cpp \
 include/Habitacion.h include/Huesped include/Reserva.h \
 include/ReservaIndividual.h include/ReservaGrupal.h \
 include/Sistema.h include/utils.h datatypes/DtFecha.h datatypes/DtFecha.cpp \
 datatypes/DtHabitacion.h datatypes/DtHabitacion.cpp datatypes/DtHuespedes.h \
 datatypes/DtHuespedes.cpp  datatypes/DtReserva.cpp datatypes/DtReserva.h \
 datatypes/DtReservaGrupal.cpp datatypes/DtReservaGrupal.h datatypes/DtReservaIndividual.cpp \
 datatypes/DtReservaIndividual.h datatypes/EstadoReserva.h datatypes/TipoReserva.h

ejec: $(OBJETOS) $(AUX) main.cpp Makefile
	$(CC) $(OPCIONES) -c -o ejec main.cpp $(OBJETOS)

Sistema.o: $(OBJSISTEMA) include/utils.h src/Sistema.cpp include/Sistema.h
	$(CC) $(OPCIONES) $(OBJSISTEMA) -c -o Sistema.o Sistema.cpp

Habitacion.o: src/Habitacion.cpp include/Habitacion.h
	$(CC) $(OPCIONES) -c -o Habitacion.o habitacion.cpp

Huesped.o: src/Huesped.cpp include/Huesped.h
	$(CC) $(OPCIONES) -c -o Habitacion.o habitacion.cpp

Reserva.o: $(OBJRESERVA) src/Reserva.cpp include/Reserva.h
	$(CC) $(OPCIONES) $(OBJRESERVA) -c -o Reserva.o Reserva.cpp

ReservaGrupal.o: $(OBJGRUPAL) include/utils.h src/ReservaGrupal.cpp include/ReservaGrupal.h
	$(CC) $(OPCIONES) $(OBJGRUPAL) -c -o ReservaGrupal.o ReservaGrupal.cpp

ReservaIndividual.o: src/Reserva.o src/ReservaIndividual.cpp include/ReservaIndividual.h
	$(CC) $(OPCIONES) src/Reserva.o -c -o ReservaIndividual.o ReservaIndividual.cpp

DtReserva.o: $(OBJDTRESERVA) datatypes/DtReserva.cpp datatypes/DtReserva.h
	$(CC) $(OPCIONES) $(OBJDTRESERVA) -c -o DtReserva.o DtReserva.cpp

DtReservaIndividual.o: datatypes/DtReserva.o src/ReservaIndividual.o datatypes/DtReservaIndividual.cpp datatypes/DtReservaIndividual.h
	$(CC) $(OPCIONES) datatypes/DtReserva.o src/ReservaIndividual.o -c -o DtReservaIndividual.o DtReservaIndividual.cpp

DtReservaGrupal.o: $(OBJDTGRUPAL) include/utils.h
	$(CC) $(OPCIONES) $(OBJDTGRUPAL) -c -o DtReservaGrupal.o DtReservaGrupal.cpp


DtHuesped.o: src/Huesped.o datatypes/DtHuesped.cpp datatypes/DtHuesped.h
	 $(CC) $(OPCIONES) src/Huesped.o -c -o DtReservaGrupal.o DtReservaGrupal.cpp


DtHabitacion.o: src/Habitacion.o datatypes/DtHabitacion.cpp datatypes/DtHabitacion.h
	$(CC) $(OPCIONES) src/Habitacion.o -c -o DtHabitacion.o DtHabitacion.cpp


DtFecha: datatypes/DtFecha.cpp datatypes/DtFecha.h
	$(CC) $(OPCIONES) -c -o DtFecha.o DtFecha.cpp

clean:
	rm -f $(OBJETOS) ejec

rebuild:
	make clean
	make

entrega: $(FUENTES) Makefile
	rm -f entrega.tar.gz
	tar -cvf entrega.tar $(FUENTES) Makefile
	gzip entrega.tar
