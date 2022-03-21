
#ifndef P4LABORATORIO0_HABITACION_H
#define P4LABORATORIO0_HABITACION_H



class Habitacion {
private:
    int numero;
    float precio;
    int capacidad;
public:
    Habitacion(int = 0, float = 0, int = 0);
    int getNumero();
    float getPrecio();
    int getCapacidad();

    void setPrecio(float);
    void setCapacidad(int);
};


#endif //P4LABORATORIO0_HABITACION_H
