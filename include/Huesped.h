
#ifndef P4LABORATORIO0_HUESPED_H
#define P4LABORATORIO0_HUESPED_H

#include <string>
#include "../datatypes/DtHuesped.h"

using namespace std;

class Huesped {
private:
    string nombre;
    string email;
    bool esFinger;
public:
    Huesped(string = "", string  = "", bool = true);

    string getNombre();

    string getEmail();

    bool isFinger();

    void setNombre(string nombre);

    void setFinger(bool esFinger);

    DtHuesped toDt();
};


#endif //P4LABORATORIO0_HUESPED_H
