#ifndef P4LABORATORIO0_A
#define P4LABORATORIO0_A

#include "b.h"

class A{
private:
    int a;

    B** linkB;
    C** linkC;
    
public:
    A(int, B*, C*);
    ~A();

    void setA(int);
    int getA();

    void printInt();
};


#endif