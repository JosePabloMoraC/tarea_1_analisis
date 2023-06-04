#include <iostream>
#include <colaLSE.hh>
#include <algoritmos.hh>


using namespace std;

void menuOperadores(Arbol& a, Arbol& b){
  //a es el árbol con el que se va a trabajar
  int respuestaC;
  int elemento;
  int nodo;
  int pos;
  nodo_t nodoResultado;
  bool stop = false;
  Traductor trad = Traductor();
  cout <<  "****  Operadores básicos modelo árbol  ***" << endl;
  cout <<  "0) Regresar al menú principal" << endl;
  cout <<  "1) Poner Raiz" << endl;
  cout <<  "2) Agregar Hijo" << endl;
  cout <<  "3) Borrar Hoja" << endl;
  cout <<  "4) Modificar Etiqueta" << endl;
  cout <<  "5) Raíz" << endl;
  cout <<  "6) Hijo" << endl;
  cout <<  "7) Padre" << endl;
  cout <<  "8) Hermano Derecho" << endl;
  cout <<  "9) Hermano Izquierdo" << endl;
  cout <<  "10) Numero de Hijos" << endl;
  cout <<  "11) Numero de Nodos" << endl;
  cout <<  "12) Vacio" << endl;
  cout <<  "13) Vaciar" << endl;
  cout << "Por favor utilice sólo los números dados según lo que desee hacer" << endl;

  while (stop != true) {
    cout << "Seleccione el operador que desea utilizar: " << endl;
    cin >> respuestaC;
    switch (respuestaC) {
      case 0: cout << "Ha seleccionado regresar al menu principal" << endl;
        cout << endl;
        stop = true;
        break;
      case 1: cout << "Ha seleccionado Poner Raiz" << endl;
        cout << "Digite el elemento de tipo entero que pertenece a la raiz: " << endl;
        cin >> elemento;
        a.PonerRaiz(elemento);
        cout << "El elemento " << elemento << " es la raiz." << endl;
        break;
      case 2: cout << "Ha seleccionado Agregar Hijo" << endl;
        cout << "Introduzca el nodo al que le quiere agregar un hijo" << endl;
        cin >> nodo;
        cout << "Introduzca la etiqueta perteneciente al nuevo nodo" << endl;
        cin >> elemento;
        cout << "Introduzca la posición que va a ocupar el nuevo nodo dentro de los nodos hijos" << endl;
        cin >> pos;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a);
        cout << "Se agrego el nodo " << elemento << " al nodo padre " << a.Etiqueta(nodoResultado) << endl;
        a.AgregarHijo(nodoResultado, elemento, pos); 
        break;
      case 3: cout << "Ha seleccionado Borrar Hoja" << endl;
        cout << "Introduzca la hoja que desea borrar " << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a);
        cout << "Se ha eliminado la hoja " << a.Etiqueta(nodoResultado) << endl; //No estamos realizando controles de entrada
        a.BorrarHoja(nodoResultado); 
        break;
      case 4: cout << "Ha seleccionado Modificar Etiqueta" << endl;
        cout << "Introduzca el nodo al que le quiere modificar la etiqueta " << endl;
        cin >> nodo;
        cout << "Introduzca la nueva etiqueta " << endl;
        cin >> elemento;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a);
        a.ModificarEtiqueta(nodoResultado, elemento);
        cout << "La nueva Etiqueta del nodo es " << a.Etiqueta(nodoResultado) << endl;
        break;
      case 5: cout << "Ha seleccionado Raiz" << endl;
        cout << "La raiz es " << a.Etiqueta(a.Raiz()) << endl;
        break;
      case 6: cout << "Ha seleccionado Hijo" << endl;
        cout << "Introduzca el nodo padre " << endl;
        cin >> nodo;
        cout << "Introduzca la posición del nodo hijo " << endl;
        cin >> pos;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a);
        cout << "El nodo hijo es: " << a.Etiqueta(a.Hijo(nodoResultado, pos)) << endl;
        break;
      case 7: cout << "Ha selecionado Padre" << endl, 
        cout << "Introduzca el nodo hijo " << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a);
        cout << "El padre es: " << a.Etiqueta(a.Padre(nodoResultado)) << endl;
        break;
      case 8: cout << "Ha selecionado Hermano derecho" << endl, 
        cout << "Introduzca el nodo" << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a);
        cout << "El hermano derecho es: " << a.Etiqueta(a.HermanoDerecho(nodoResultado)) << endl;
        break;
      case 9: cout << "Ha selecionado Hermano Izquierdo" << endl, 
        cout << "Introduzca el nodo" << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a);
        cout << "El hermano izquierdo es: " << a.Etiqueta(a.HermanoIzquierdo(nodoResultado)) << endl;
        break;
      case 10: cout << "Ha selecionado Numero de Hijos" << endl, 
        cout << "Introduzca el nodo" << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a);
        cout << "El numero de hijos es " << a.NumHijos(nodoResultado) << endl;
        break;
      case 11: cout << "Ha selecionado Numero Nodos" << endl, 
        cout << "El numero de nodos es " << a.NumNodos() << endl;
        break;
      case 12: cout << "Ha selecionado Vacio" << endl;
        if(a.Vacio()){
          cout << "El arbol esta vacio." << endl;
        } else {
          cout << "El arbol no esta vacio" << endl;
        }
        break;
      case 13: cout << "Ha selecionado Vaciar" << endl;
        a.Vaciar();
        cout << "Se ha vaciado el arbol" << endl;
      default: cout << "Respuesta inválida" << endl;
    }
  }
}

void menuAlgoritmos(Arbol& a, Arbol& b){
  int respuestaC;
  //int elemento;
  int nodo;
  int pos;
  nodo_t nodoResultado;
  bool stop = false;
  Traductor trad = Traductor();
  cout <<  "****  Algoritmos para el modelo árbol  ***" << endl;
  cout <<  "0) Regresar al menú principal" << endl;
  cout <<  "1) Listar las etiquetas de todos los hermanos de un nodo" << endl;
  cout <<  "2) Listar las etiquetas de todos los nodos del i-ésimo nivel del árbol" << endl;
  cout <<  "3) Cantidad de niveles del árbol" << endl;
  cout <<  "4) Averiguar si el árbol tiene etiquetas repetidas" << endl;
  cout <<  "5) Copiar el árbol actual al árbol restante" << endl;
  cout <<  "6) Averiguar si el árbol actual es igual al restante" << endl;
  cout <<  "7) Averiguar cuál es la profundidad de un nodo" << endl;
  cout <<  "8) Averiguar cuál es la altura de un nodo" << endl;
  cout <<  "9) Averiguar si una etiqueta está en el árbol" << endl;

 while (stop != true) {
    cout << "Seleccione el algoritmo que desea utilizar: " << endl;
    cin >> respuestaC;
    switch (respuestaC) {
      case 0: cout << "Ha seleccionado regresar al menu principal" << endl;
        cout << endl;
        stop = true;
        break;
      case 1: cout << "Ha seleccionado listar las etiquetas de todos los hermanos de un nodo" << endl;
        cout << "Introduzca el nodo" << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a);
        etiquetasHermanos(nodoResultado, a);
        cout << endl;
        break;
      case 2: cout << "Ha seleccionado listar las etiquetas del i-ésimo nivel del árbol " << endl; 
        cout << "Introduzca el nivel a listar" << endl;
        cin >> pos;
        etiquetasNivel(pos, a);
        cout << endl;
        break;
      case 4: cout << "Ha seleccionado Averiguar si el árbol tiene etiquetas repetidas" << endl; 
        /*
        if(etiquetasRepetidas(Arbol& a)){
          cout << "El árbol presenta etiquetas repetidas" << endl;
        } else {
           cout << "El árbol no presenta etiquetas repetidas" << endl;
        }
        */
        cout << "Falta" << endl;
        break;
      case 5: cout << "Ha seleccionado copiar el árbol" << endl;
        copiarArbol(a, b);
        cout << "Se ha vaciado el árbol restante" << endl;
        cout << "Se ha copiado el árbol actual en el árbol restante" << endl;
        break;
      case 6: cout << "Ha seleccionado averiguar si los árboles son iguales" << endl;
        if(iguales(a, b)){
          cout << "Los árboles son iguales" << endl;
        } else {
          cout << "Los árboles no son iguales" << endl;
        }
        break;
      case 7: cout << "Ha seleccionado averiguar cuál es la profundidad de un nodo" << endl;
        cout << "Introduzca el nodo" << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a);
        cout << "La profundidad del nodo es: " << profundidadNodo(nodoResultado, a) << endl;
        break;
      case 8: cout << "Ha selecciona averiguar cuál es la altura de un nodo" << endl;
        cout << "Introduzca el nodo" << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a);
        cout << "La altura del nodo es: " << alturaNodo(nodoResultado, a) << endl;
        break;
      case 9: cout << "Ha seleccionado averiguar si una etiqueta está en el árbol" << endl;
        cout << "Introduzca la etiqueta" << endl;
        cin >> nodo;
        if(existeEtiqueta(nodo, a)){
          cout << "La etiqueta " << nodo << " se encuentra en el árbol" << endl;
        } else {
          cout << "La etiqueta " << nodo << " no se encuentra en el árbol" << endl;
        }
        break;
      default: cout << "Respuesta inválida" << endl;
    }
 }
}

void subMenuArbol(Arbol& a, Arbol& b){
    bool continuar = true;
    int respuesta;

    while(continuar) {
    cout << "1) Utilizar operadores básicos del modelo árbol" << endl;
    cout << "2) Utilizar algoritmos para el modelo árbol" << endl;
    cout << "3) Regresar al menu anterior" << endl;
    cout << "Ingrese su respuesta: " << endl;
    cin >> respuesta;
    
    switch (respuesta) {
      case 1 : 
        cout << "Ha seleccionado operadores básicos del modelo árbol" << endl;
        continuar = false;
        menuOperadores(a, b);
      break;
      case 2 : cout << "Ha seleccionado algoritmos para el modelo árbol" << endl;
        continuar = false;
        menuAlgoritmos(a, b);
      break;
      case 3 : cout << "Programa finalizado" << endl, continuar = false;
      break;
      default: cout << "Respuesta inválida, seleccione un valor válido. " << endl;
    }
  }
}

int main () {
  cout << "El siguiente programa te permite trabajar con dos árboles por separado (a1 y a2)." << endl;
  cout << "Considera el siguiente menú" << endl;  
  int respuesta;
  Arbol a1 = Arbol();
  Arbol a2 = Arbol();
  bool continuar = true;

  while(continuar) {
    cout <<  "****  MENU  ***" << endl;
    cout << "1) Desea utilizar el árbol a1" << endl;
    cout << "2) Desea utilizar el árbol a2" << endl;
    cout << "3) Desea salir del programa" << endl;
    cout << "Por favor utilice sólo los números dados según lo que desee hacer" << endl;
    cout << "Ingrese su respuesta: " << endl;
    cin >> respuesta;
    
    switch (respuesta) {
      case 1 : cout << "Ha seleccionado el árbol a1" << endl, subMenuArbol(a1, a2);
      break;
      case 2 : cout << "Ha seleccionado el árbol a2" << endl, subMenuArbol(a2, a1);
      break;
      case 3 : cout << "Programa finalizado" << endl, continuar = false;
      break;
      default: cout << "Respuesta inválida, seleccione un valor válido. " << endl;
    }
  }

  return 0;
}
