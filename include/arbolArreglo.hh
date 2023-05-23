#ifndef ARBOLHMIARREGLO_HH
#define ARBOLHMIARREGLO_HH

#include <iostream>
using namespace std; 

struct caja
{
    int Etiqueta;
    int Padre;
};


typedef int nodo_t; // para el resto de los árboles, cambiar según el tipo nodo. Notar que aquí el tipo nodo es un entero;

class Arbol
{
private:
    int ultimo;
    caja arreglo[21]; //Consideramos un árbol con máximo 30 nodos. Primera fila es de etiquetas, segunda es el señalador al padre. 
public:
    void Vaciar();
    bool Vacio();
    void PonerRaiz(int e);
    nodo_t AgregarHijo(nodo_t n, int e, int k);
    void BorrarHoja(nodo_t n);
    void ModificarEtiqueta(nodo_t n, int e);
    nodo_t Raiz();
    nodo_t Hijo(nodo_t n, int i); 
    nodo_t Padre(nodo_t n); 
    nodo_t HermanoDerecho(nodo_t n); 
    nodo_t HermanoIzquierdo(nodo_t n); 
    int Etiqueta(nodo_t n);
    int NumHijos(nodo_t n); 
    int NumNodos(); 
    nodo_t NodoNulo();

    Arbol();
    ~Arbol();
};



#endif
