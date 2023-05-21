#include <traductor.hh>

Traductor::Traductor()
{
}

Traductor::~Traductor()
{
}

int Traductor::Nodo_a_Etiqueta(nodo_t n, Arbol& arb){
    return arb.Etiqueta(n);

}

nodo_t Traductor::Etiqueta_a_Nodo(int etiqueta, Arbol& arb){
    if(!arb.Vacio()){
       return BuscarRecursivo(arb.Raiz(), arb, etiqueta);
    }
    return arb.NodoNulo();
}

nodo_t Traductor::BuscarRecursivo(nodo_t nodoActual, Arbol& arb, int etiqueta){
    nodo_t nodoHijo;
    nodo_t nodoEncontrado;
    if(arb.Etiqueta(nodoActual) == etiqueta){
        return nodoActual;
    }
    else{
        nodoHijo= arb.Hijo(nodoActual, 1);
        while(nodoHijo != arb.NodoNulo()){
            nodoEncontrado = BuscarRecursivo(nodoHijo, arb, etiqueta);
            if(nodoEncontrado != arb.NodoNulo()){
                return nodoEncontrado;
            }
            nodoHijo = arb.HermanoDerecho(nodoHijo);
        }
    }
    return arb.NodoNulo();
}