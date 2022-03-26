#ifndef P4LABORATORIO0_MAIN2
#define P4LABORATORIO0_MAIN2

#include "include/a.h"


int main(){
    A* objA;
    B* objB;
    C* objC;
    
    objA = new A(5, objB, objC);
    objB = new B(10, objA, objC);
    objC = new C(25, objA, objB);

    objA->printInt();
    objB->printInt();
    objC->printInt();

    objA->~A();
    objB->~B();
    objC->~C();

    delete objA;
    delete objB;
    delete objC;

    return 0;
}




#endif