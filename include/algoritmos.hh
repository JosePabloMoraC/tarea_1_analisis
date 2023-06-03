#ifndef ALGORITMOS_HH
#define ALGORITMOS_HH

#include <traductor.hh>
#include <colaLSE.hh>

void etiquetasHermanos(nodo_t n, Arbol& a);

void etiquetasNivel(int nivel, Arbol& a);

int nivelesArbol(Arbol& a);
void nivelesArbolRecursivo(nodo_t nodoActual, int nivelActual, Arbol& a, int& nNiveles);

bool etiquetasRepetidas(Arbol& a);

void copiar(Arbol& a, Arbol& b);

bool iguales(Arbol& a, Arbol& b);

int profundidadNodo(nodo_t n, Arbol& a);
void profundidadRecursivo(nodo_t nodoBuscado, nodo_t nodoActual, int profundidadActual, Arbol& a, int& profundidad);

int alturaNodo(nodo_t n, Arbol& a);

bool existeEtiqueta(int e, Arbol& a);
void existeEtiquetaRecursivo(nodo_t nodoActual, int e, Arbol& a, bool& pertenece);




#endif  ALGORITMOS_HH
