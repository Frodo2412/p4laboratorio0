#include "../include/c.h"
#include <iostream>

using namespace std;

//void printf(int x){}

C::C(int n, A* refA, B* refB){
    this->c = n;
    this->linkA = &refA;
    this->linkB = &refB;
}


C::~C(){
}


void C::setC(int n){
    this->c = n;
}


int C::getC(){
    return c;
}


void C::printInt(){
    cout << "c es ";
    cout << c;
    cout << endl;
}