#ifndef ALGORITMOS_HH
#define ALGORITMOS_HH

#include <traductor.hh>

void etiquetasHermanos(nodo_t n, Arbol& a);

int nivelesArbol(Arbol& a);
void nivelesArbolRecursivo(nodo_t nodoActual, int nivelActual, Arbol& a, int& nNiveles);

int profundidadNodo(nodo_t n, Arbol& a);
void profundidadRecursivo(nodo_t nodoBuscado, nodo_t nodoActual, int profundidadActual, Arbol& a, int& profundidad);

int alturaNodo(nodo_t n, Arbol& a);


#endif  ALGORITMOS_HH