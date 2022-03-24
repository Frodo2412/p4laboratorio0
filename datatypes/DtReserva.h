#ifndef P4LABORATORIO0_DTRESERVA_H
#define P4LABORATORIO0_DTRESERVA_H

#include "DtFecha.h"
#include "../include/Habitacion.h"
#include "../include/Huesped.h"
#include "../include/Reserva.h"

class DtReserva {
protected:
    int codigo;
    DtFecha checkIn, checkOut;
    EstadoReserva estado;
    float costo;
    int Habitacion;
public:
    DtReserva(int cod, DtFecha In, DtFecha Out, EstadoReserva estado, float costo, int hab);

    DtReserva(Reserva *reserva);

    virtual ~DtReserva();

    int getCodigoReserva();

    DtFecha getCheckIn();

    DtFecha getCheckOut();

    EstadoReserva getEstado();

    float getCosto();

    int getHabitacion();

    virtual TipoReserva getTipoReserva() = 0;

    virtual string getTipoReservaToString() = 0;

    virtual Reserva *toCore(Huesped *, class Habitacion *) = 0;
};

std::ostream &operator<<(std::ostream &, DtReserva *);


#endif //P4LABORATORIO0_DTRESERVA_H
