#ifndef COLA_HH
#define COLA_HH

#include <iostream>
using namespace std;

struct  Caja {
  int elemento;
  Caja* next;
};

class Cola {
  private:
    Caja *primero;
    Caja *ultimo;
  public:
    Cola();
    void vaciar();
    bool vacia();
    void agregar(int e);
    int sacar();
    int frente(); 
    ~Cola();
};


#endif