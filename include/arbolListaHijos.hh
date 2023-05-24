#ifndef ARBOLLISTAHIJOS_HH
#define ARBOLLISTAHIJOS_HH

#include <iostream>
using namespace std;

struct CajaPrincipal
{
    int valor;
    CajaPrincipal* siguiente;
    ListaHijos sublista;
};

struct CajaHijo
{
    int valor;
    CajaHijo* siguiente;
};

typedef int nodo_t;

class ListaPrincipal
{
  private:
    CajaPrincipal* primero;

  public:
    Vaciar(nodo_t nodo);
    AgregarHijo(nodo_t nodo, int elemento, int pos);
    BorrarHoja(nodo_t nodo);
};

class ListaHijos
{
  private:
    CajaHijo* primero;

  public:
    Vaciar(nodo_t nodo);
    AgregarHijo(nodo_t nodo, int elemento, int pos);
    BorrarHoja(nodo_t nodo);
};

class Arbol
{
  private:
    nodo_t raiz;
    int contadorNodos = 0;
    void VaciarRecursivo(nodo_t n);
  public:
    void Vaciar();
    bool Vacio();
    void PonerRaiz(int e);
    nodo_t AgregarHijo(nodo_t n, int e, int k); //no
    void BorrarHoja(nodo_t n); //no
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
