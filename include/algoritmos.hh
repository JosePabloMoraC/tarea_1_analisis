#ifndef ALGORITMOS_HH
#define ALGORITMOS_HH

#include <traductor.hh>

void etiquetasHermanos(nodo_t n, Arbol& a);

int nivelesArbol(Arbol& a);
void nivelesArbolRecursivo(nodo_t nodoActual, int nivelActual, Arbol& a, int& nNiveles);


#endif  ALGORITMOS_HH