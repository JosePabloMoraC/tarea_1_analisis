#ifndef TRADUCTOR_HH
#define TRADUCTOR_HH

#include <arbolArreglo.hh>

#include <iostream>
using namespace std; 
class Traductor //Está clase despues se puede transformar en la encargada de manejar los algoritmos
{
    
private:
    nodo_t BuscarRecursivo(nodo_t nodoActual, Arbol& arb, int etiqueta);
public:
    //int Nodo_a_Etiqueta(nodo_t n, Arbol& arb);
    nodo_t Etiqueta_a_Nodo(int etiqueta, Arbol& arb);
    Traductor();
    ~Traductor();
    

};




#endif