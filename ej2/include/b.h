#ifndef P4LABORATORIO0_B
#define P4LABORATORIO0_B

#include "c.h"

class B{
private:
    int b;

    A** linkA;
    C** linkC;

public:
    B(int, A*, C*);
    ~B();

    void setB(int);
    int getB();

    void printInt();
};


#endif