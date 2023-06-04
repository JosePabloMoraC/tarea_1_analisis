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

//Requiere árbol no vacío
bool etiquetasRepetidas(Arbol& a) {
  //Usamos una cola como modelo auxiliar
  Cola<nodo_t> cola;
  nodo_t nodo;
  nodo_t nodoHijo;
  int etiqueta;
  bool repetido = false;
  int* arreglo = new int[a.NumNodos()];
  int numEtiquetas = 0;
  
  //Encolamos la raíz
  cola.agregar(a.Raiz());
  while (!cola.vacia() && !repetido) {
    //Desencolamos el primer elemento
    nodo = cola.sacar();
    etiqueta = a.Etiqueta(nodo);
    //Comparamos la etiqueta que desencolamos con todos los elementos que están en el arreglo
    for (int pos = 0; pos <= numEtiquetas && !repetido; pos++) {
      if (etiqueta == arreglo[pos]) {
        repetido = true;
      }
    }
    if (!repetido) {
      //Si no se encontró en el arreglo entonces agregamos la etiqueta a la siguiente posición vacía del arreglo
      //Notar que el arreglo empieza en 0
      arreglo[numEtiquetas] = etiqueta;
      numEtiquetas++;
      nodoHijo = a.Hijo(nodo, 1); //Hijo más izquierdo
      while (nodoHijo != a.NodoNulo()) {
        //Encolamos los hijos
        cola.agregar(nodoHijo);
        nodoHijo = a.HermanoDerecho(nodoHijo);
      }
    }
  }
  delete[] arreglo;
  return repetido;
}

void copiarArbol(Arbol& a1, Arbol& a2){
  a2.Vaciar();
  if(!a1.Vacio()){
    //Colas que vamos a usar para a1 y a2 
    Cola<nodo_t> colaA1;
    Cola<nodo_t> colaA2;
    nodo_t nodoAux1;
    nodo_t nodoAux2;
    nodo_t nodoAuxHijo2;

    //Le ponemos raíz a a2
    //Notar que se copiar las etiquetas, no los nodos. Pero lo que se encola son nodos. 
    a2.PonerRaiz(a1.Etiqueta(a1.Raiz()));
    //Encolamos ambas raíces 
    colaA1.agregar(a1.Raiz());
    colaA2.agregar(a2.Raiz());
    while(!colaA1.vacia()){
      //sacamos el primer elemento de ambas colas
      nodoAux1 = colaA1.sacar();
      nodoAux2 = colaA2.sacar();
      //hijo máz izquierdo de nodoAux1
      nodoAux1 = a1.Hijo(nodoAux1, 1);
      while(nodoAux1 != a1.NodoNulo()){
        //Agregamos hijo en la ultima posición
        nodoAuxHijo2 = a2.AgregarHijo(nodoAux2, a1.Etiqueta(nodoAux1), a2.NumHijos(nodoAux2) + 1);
        //Encolamos
        colaA1.agregar(nodoAux1);
        colaA2.agregar(nodoAuxHijo2);
        nodoAux1 = a1.HermanoDerecho(nodoAux1);
      }
    }
  }  
}

//No compila - NumElem() no forma parte de los métodos del árbol

bool iguales(Arbol& a1, Arbol& a2) {
  if (a1.NumNodos() != a2.NumNodos()) {
    return false; 
  } else {
    //si ambos árboles están vacíos son iguales
    if (a1.NumNodos() == 0) {
      return true;
    } else {
      if (a1.Etiqueta(a1.Raiz()) != a2.Etiqueta(a2.Raiz())) {
        return false;
      } else {
        Cola<nodo_t> colaA1;
        Cola<nodo_t> colaA2;
        
        //Encolamos las raíces
        colaA1.agregar(a1.Raiz());
        colaA2.agregar(a2.Raiz());
        bool seguir = true;
        nodo_t nodo1;
        nodo_t nodo2;
        nodo_t nodoHijo1;
        nodo_t nodoHijo2;
        
        while (!colaA1.vacia() && seguir) {
          //Desencolamos el primer elemento de ambas colas
          nodo1 = colaA1.sacar();
          nodo2 = colaA2.sacar();
          if (a1.NumHijos(nodo1) != a2.NumHijos(nodo2)) {
            seguir = false;
          } else {
            //Guardamos el hijo más izquierdo de cada sub-árbol
            nodoHijo1 = a1.Hijo(nodo1, 1);
            nodoHijo2 = a2.Hijo(nodo2, 1);
            while (nodoHijo1 != a1.NodoNulo() && seguir) {
              if (a1.Etiqueta(nodoHijo1) != a2.Etiqueta(nodoHijo2)) {
                seguir = false;
              } else {
                //Encolamos
                colaA1.agregar(nodoHijo1);
                colaA2.agregar(nodoHijo2);
                //Pasamos al hermano derecho para realizar todo el recorrido
                nodoHijo1 = a1.HermanoDerecho(nodoHijo1);
                nodoHijo2 = a2.HermanoDerecho(nodoHijo2);
              }
            }
          }
        }
        return seguir;
      }
    }
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
