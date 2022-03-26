
OBJETOS = src/a.o src/b.o src/c.o

OPCIONES = -g -Wall
CC = g++

OBJB = src/c.o

OBJA = src/b.o

FUENTES = main.cpp src/a.cpp src/b.cpp src/c.cpp \
 include/a.h include/b.h include/c.h

ejec_Ej2: $(OBJETOS) main.cpp Makefile
	$(CC) $(OPCIONES) -o ejec_Ej2 main.cpp $(OBJETOS)

a.o: $(OBJA) src include
	$(CC) $(OPCIONES) -c -o a.o a.cpp

b.o: $(OBJB) src include
	$(CC) $(OPCIONES) -c -o b.o b.cpp

c.o: src include
	$(CC) $(OPCIONES) -c -o c.o c.cpp

clean:
	rm -f $(OBJETOS) ejec_Ej2

rebuild:
	make clean
	make

entrega: $(FUENTES) Makefile
	rm -f ej2.tar.gz
	tar -cvf ej2.tar $(FUENTES) Makefile
	gzip ej2.tar


