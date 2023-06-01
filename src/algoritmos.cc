#include <algoritmos.hh>
//Algoritmos
//De acuerdo a la profesora, para evitar complicaciones, podemos realizar los algoritmos en el main y usando variables globales. 
void etiquetasHermanos(nodo_t n,  Arbol& a){
  //Tenemos dos opciones, ver todos los hermanos izquierdos y derechos o llamar al padre. La opción más eficiente depende de la estructura de datos.
  //Vamos a llamar al padre
  nodo_t nodoAux = a.Hijo(a.Padre(n), 1); //Hijo máz izquierdo del padre 
  cout << "La lista de Hermanos es: ";
  while(nodoAux != a.NodoNulo()){
    if(nodoAux != n){
      cout <<a.Etiqueta(nodoAux) << " " ; //Listar los hermanos
    }
    nodoAux = a.HermanoDerecho(nodoAux);
  }
}

//Requiere árbol inicializado 
int nivelesArbol(Arbol& a){
  int niveles = 0;
  if(a.Raiz() != a.NodoNulo()){
    nivelesArbolRecursivo(a.Raiz(), 1, a, niveles); //Se pasa niveles por referencia 
  }

return niveles;
}

void nivelesArbolRecursivo(nodo_t nodoActual, int nivelActual, Arbol& a, int& nNiveles){
  if(nivelActual > nNiveles){
    nNiveles = nivelActual;
  }
  nodo_t nodoHijo = a.Hijo(nodoActual, 1); //Hijo más izquierdo
  //Para este caso, no queda de otra que recorrer todo el árbol
  while(nodoHijo != a.NodoNulo()){
    nivelesArbolRecursivo(nodoHijo, nivelActual + 1, a, nNiveles);
    nodoHijo = a.HermanoDerecho(nodoHijo);
  }
}





