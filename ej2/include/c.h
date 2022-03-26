#ifndef P4LABORATORIO0_C
#define P4LABORATORIO0_C
class A;
class B;

class C{
private:
    int c;

    A** linkA;
    B** linkB;

public:
    C(int, A*, B*);
    ~C();

    void setC(int);
    int getC();

    void printInt();
};


#endif