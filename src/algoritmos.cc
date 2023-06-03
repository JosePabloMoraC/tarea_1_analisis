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

void etiquetasNivel(int nivel, Arbol& a){
  if(!a.Vacio()){
    Cola<nodo_t> c1;
    nodo_t nodoHijo;
    int tamanoCola;
    int j = 1; // Se considera la raíz como el nivel 1 
    cout << "Las etiquetas de los nodos en el nivel " << nivel << " son: ";
    if(nivel == 1){
      cout << a.Etiqueta(a.Raiz()) << " ";
    } else {
        c1.agregar(a.Raiz());
        while(!c1.vacia()){
          j++;
          tamanoCola = c1.getLargo();
          //Notar que está implementación evita tener dos colas (o una cola de structs).
          //Notar que el ciclo for itera sobre todos los elementos de un nivel. Cuando termina el for, 
          //en la cola solo quedan elementos del siguiente nivel. Por lo que pedir getLargo() es análogo a consultar la 
          //cantidad de elementos en el nivel.
          for(int i = 0; i < tamanoCola; i++){
            nodoHijo = a.Hijo(c1.sacar(), 1); //Hijo más izquierdo
            while (nodoHijo != a.NodoNulo())
            {
              if(j == nivel){
                cout << a.Etiqueta(nodoHijo) << " ";
              } else {
                c1.agregar(nodoHijo);
              }
              nodoHijo = a.HermanoDerecho(nodoHijo);
            }  
          }
        }
      }
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
//Arbol inicializado y n valido en a, con raiz
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

//Arbol inicializado y n valido, con raiz 
int alturaNodo(nodo_t n, Arbol& a){
  int altura = 0;
  //notar que el problema a resolver es el mismo que ya resuelve nivelesArbolRecursivo(), por lo que podemos reutilizar está función.
  //(nodo_t nodoActual, int nivelActual, Arbol& a, int& nNiveles);
  //Primero revisamos que n tenga hijos y despues llamamos a la función recursiva
  if(a.Hijo(n, 1) != a.NodoNulo()){
      nivelesArbolRecursivo(n, 0, a, altura);
  }

  return altura;
}


bool existeEtiqueta(int e, Arbol& a){
  bool pertenece = false; 
  if(a.Raiz() != a.NodoNulo()){
    existeEtiquetaRecursivo(a.Raiz(), e, a, pertenece);
  }

  return pertenece;
}

void existeEtiquetaRecursivo(nodo_t nodoActual, int e, Arbol& a, bool& pertenece){
  if(e == a.Etiqueta(nodoActual)){
    pertenece = true;
  } else{
    nodo_t nodoHijo = a.Hijo(nodoActual, 1); //Hijo más izquierdo
    while(nodoHijo != a.NodoNulo() && pertenece == false){
      existeEtiquetaRecursivo(nodoHijo, e, a, pertenece);
      nodoHijo = a.HermanoDerecho(nodoHijo);
    }
  }
}
