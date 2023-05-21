#ifndef ARBOLHMI_HD_HH
#define ARBOLHMI_HD_HH

#include <iostream>
using namespace std; 

struct caja
{
    int valor;
    caja* HijoMasIzquierdo;
    caja* HermanoDerecho; 
    bool hijoFinal;
};

typedef caja* nodo_t; // para el resto de los árboles, cambiar según el tipo nodo. Notar que aquí el tipo nodo es un ptr. 

class Arbol
{
private:
    nodo_t raiz; 
    int contadorNodos=0;
    //nodo_t PadreRecursivo(nodo_t n_buscado, nodo_t n_actual);
    nodo_t HermanoIzquierdoAux(nodo_t n, nodo_t padre); // Lo necesitamos para el borrar hoja. 
    void VaciarRecursivo(nodo_t n);
public:
    void funciona();  //borrar
    void Vaciar();
    bool Vacio();
    void PonerRaiz(int e);
    nodo_t AgregarHijo(nodo_t n, int e, int k);
    void BorrarHoja(nodo_t n);
    void ModificaEtiqueta(nodo_t n, int e);
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
