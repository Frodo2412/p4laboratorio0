#include "../include/a.h"
#include <iostream>

using namespace std;

//void printf(int x){}

A::A(int n, B* refB, C* refC){
    this->a = n;
    this->linkB = &refB;
    this->linkC = &refC;
}


A::~A(){
}


void A::setA(int n){
    this->a = n;
}


int A::getA(){
    return a;
}


void A::printInt(){
    cout << "a es ";
    cout << a;
    cout << endl;
}