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
//Arbol inicializado y n valido en a
int profundidadNodo(nodo_t n, Arbol& a){
  int profundidad = 0;

  //Notar que si consideramos unicamente los operadores del modelo, tenemos dos opciones.
  //La primera consiste llevar un contador e ir llamando al nodo padre hasta la raíz. Pero sabemos que está implementación es muy
  //ineficiente para algúnas estructruas en que Padre() es O(n). Por lo tanto, vamos a recorrer el árbol para encontrar al nodo actual. 
  //Se podría realizar en post-orden o por niveles. Notar que la escencia de la implementación es similar a la de Etiqueta_a_Nodo de la clase traductor.
  if(n != a.Raiz()){
    // Se le asigna a la raíz una profundidad de 0
    profundidadRecursivo(n, a.Raiz(), 0, a, profundidad);
  }

  return profundidad;
}

void profundidadRecursivo(nodo_t nodoBuscado, nodo_t nodoActual, int profundidadActual, Arbol& a, int& profundidad){
  if(nodoActual == nodoBuscado){
    profundidad = profundidadActual;
  }else{
    nodo_t nodoHijo = a.Hijo(nodoActual, 1); //Hijo más izquierdo
    while(nodoHijo != a.NodoNulo() && profundidad == 0){ //Con profundidad == 0 nos aseguramos de detener el bucle cuando se encontró el nodoBuscado. Notar que profundidad solo se debe modificar 1 vez
      profundidadRecursivo(nodoBuscado, nodoHijo, profundidadActual + 1, a, profundidad);
      nodoHijo = a.HermanoDerecho(nodoHijo);
    }
  }
}




