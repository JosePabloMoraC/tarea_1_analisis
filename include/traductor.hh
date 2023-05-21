#ifndef TRADUCTOR_HH
#define TRADUCTOR_HH

#include <arbolHMI_HD_ptr.hh>

#include <iostream>
using namespace std; 
class Traductor
{
private:
    nodo_t BuscarRecursivo(nodo_t nodoActual, Arbol& arb, int etiqueta);
public:
    int Nodo_a_Etiqueta(nodo_t n, Arbol& arb);
    nodo_t Etiqueta_a_Nodo(int etiqueta, Arbol& arb);
    Traductor();
    ~Traductor();

};




#endif