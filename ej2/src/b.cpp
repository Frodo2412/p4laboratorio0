#include "../include/b.h"
#include <iostream>

using namespace std;

//void printf(int x){}

B::B(int n, A* refA, C* refC){
    this->b = n;
    this->linkA = &refA;
    this->linkC = &refC;
}


B::~B(){
}


void B::setB(int n){
    this->b = n;
}


int B::getB(){
    return b;
}


void B::printInt(){
    cout << "b es ";
    cout << b;
    cout << endl;
}