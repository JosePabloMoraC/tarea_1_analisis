#include <iostream>
#include <colaLSE.hh>
#include <traductor.hh>

using namespace std;


void submenuCola(){
  int respuestaC;
  bool stop = false;
  Cola c1 = Cola();
  cout <<  "****  Cola  ***" << endl;
  cout <<  "1) Iniciar" << endl;
  cout <<  "2) Agregar" << endl;
  cout <<  "3) Sacar" << endl;
  cout <<  "4) Frente" << endl;
  cout <<  "5) Vacia" << endl;
  cout <<  "6) Vaciar" << endl;
  cout <<  "7) Destruir" << endl;
  cout <<  "8) Salir" << endl;
  cout << "Por favor utilice sólo los números dados según lo que desee hacer" << endl;
  while (stop != true) {
    cout << "Seleccione el operador que desea utilizar: " << endl;
    cin >> respuestaC;
    switch (respuestaC) {
      case 1: cout << "Ha seleccionado iniciar" << endl;
        c1 = Cola();
        break;
      case 2: cout << "Ha seleccionado agregar" << endl;
        cout << "Digite el elemento a agregar: " << endl;
        int element;
        cin >> element;
        c1.agregar(element);
        cout << "Se agregó el elemento " << element << " a la cola." << endl;
      break;
      case 3: cout << "Ha seleccionado sacar" << endl;
        cout << "Se sacó el elemento " << c1.sacar() << " de la cola." << endl;
        break;
      case 4: cout << "Ha seleccionado frente" << endl;
        cout << "El elemento del frente es " << c1.frente() << endl;
        break;
      case 5: cout << "Ha seleccionado vacia" << endl;
        if (c1.vacia()) {
          cout << "La cola está vacía" << endl;
        } else {
          cout << "La cola no está vacía" << endl;
        }
        break;
      case 6: cout << "Ha seleccionado vaciar" << endl;
        c1.vaciar();
        cout << "Se ha vaciado la cola" << endl;
        break;
      case 7: cout << "Ha seleccionado destruir" << endl;
        c1.~Cola();
        cout << "Se ha destruido la cola" << endl;
        break;
      case 8: cout << "Ha seleccionado salir" << endl, stop = true;
        c1.~Cola();
        break;
      default: cout << "Respuesta inválida" << endl, stop = true;
    }
  }
}

void submenuArbol(){
  int respuestaC;
  int elemento;
  int nodo;
  int pos;
  nodo_t nodoResultado;
  bool stop = false;
  Cola c1 = Cola();
  Arbol a1 = Arbol();
  Traductor trad = Traductor();
  cout <<  "****  Arbol  ***" << endl;
  cout <<  "1) Crear" << endl;
  cout <<  "2) Poner Raiz" << endl;
  cout <<  "3) Agregar Hijo" << endl;
  cout <<  "4) Borrar Hoja" << endl;
  cout <<  "5) Modificar Etiqueta" << endl;
  cout <<  "6) Raíz" << endl;
  cout <<  "7) Hijo" << endl;
  cout <<  "8) Padre" << endl;
  cout <<  "9) Hermano Derecho" << endl;
  cout <<  "10) Hermano Izquierdo" << endl;
  cout <<  "11) Numero de Hijos" << endl;
  cout <<  "12) Numero de Nodos" << endl;
  cout <<  "13) Vacio" << endl;
  cout <<  "14) Vaciar" << endl;
  cout <<  "15) Destruir" << endl;
  cout <<  "16) Salir" << endl;
  cout << "Por favor utilice sólo los números dados según lo que desee hacer" << endl;

  while (stop != true) {
    cout << "Seleccione el operador que desea utilizar: " << endl;
    cin >> respuestaC;
    switch (respuestaC) {
      case 1: cout << "Ha seleccionado crear" << endl;
        a1 = Arbol();
        break;
      case 2: cout << "Ha seleccionado Poner Raiz" << endl;
        cout << "Digite el elemento de tipo entero que pertenece a la raiz: " << endl;
        cin >> elemento;
        a1.PonerRaiz(elemento);
        cout << "El elemento " << elemento << " es la raiz." << endl;
      break;
      case 3: cout << "Ha seleccionado Agregar Hijo" << endl;
        cout << "Introduzca el nodo al que le quiere agregar un hijo" << endl;
        cin >> nodo;
        cout << "Introduzca la etiqueta perteneciente al nuevo nodo" << endl;
        cin >> elemento;
        cout << "Introduzca la posición que va a ocupar el nuevo nodo dentro de los nodos hijos" << endl;
        cin >> pos;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a1);
        cout << "Se agrego el nodo " << elemento << " al nodo padre " << a1.Etiqueta(nodoResultado) << endl;
        a1.AgregarHijo(nodoResultado, elemento, pos); 
        break;
      case 4: cout << "Ha seleccionado Borrar Hoja" << endl;
        cout << "Introduzca la hoja que desea borrar " << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a1);
        cout << "Se ha eliminado la hoja " << a1.Etiqueta(nodoResultado) << endl; //No estamos realizando controles de entrada
        a1.BorrarHoja(nodoResultado); 
        break;
      case 5: cout << "Ha seleccionado Modificar Etiqueta" << endl;
        cout << "Introduzca el nodo al que le quiere modificar la etiqueta " << endl;
        cin >> nodo;
        cout << "Introduzca la nueva etiqueta " << endl;
        cin >> elemento;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a1);
        a1.ModificarEtiqueta(nodoResultado, elemento);
        cout << "La nueva Etiqueta del nodo es " << a1.Etiqueta(nodoResultado) << endl;
        break;
      case 6: cout << "Ha seleccionado Raiz" << endl;
        cout << "La raiz es " << a1.Etiqueta(a1.Raiz()) << endl;
        break;
      case 7: cout << "Ha seleccionado Hijo" << endl;
        cout << "Introduzca el nodo padre " << endl;
        cin >> nodo;
        cout << "Introduzca la posición del nodo hijo " << endl;
        cin >> pos;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a1);
        cout << "El nodo hijo es: " << a1.Etiqueta(a1.Hijo(nodoResultado, pos)) << endl;
        break;
      case 8: cout << "Ha selecionado Padre" << endl, 
        cout << "Introduzca el nodo hijo " << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a1);
        cout << "El padre es: " << a1.Etiqueta(a1.Padre(nodoResultado)) << endl;
        break;
      case 9: cout << "Ha selecionado Hermano derecho" << endl, 
        cout << "Introduzca el nodo" << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a1);
        cout << "El hermano derecho es: " << a1.Etiqueta(a1.HermanoDerecho(nodoResultado)) << endl;
        break;
      case 10: cout << "Ha selecionado Hermano Izquierdo" << endl, 
        cout << "Introduzca el nodo" << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a1);
        cout << "El hermano izquierdo es: " << a1.Etiqueta(a1.HermanoIzquierdo(nodoResultado)) << endl;
        break;
      case 11: cout << "Ha selecionado Numero de Hijos" << endl, 
        cout << "Introduzca el nodo" << endl;
        cin >> nodo;
        nodoResultado = trad.Etiqueta_a_Nodo(nodo, a1);
        cout << "El numero de hijos es " << a1.NumHijos(nodoResultado) << endl;
        break;
      case 12: cout << "Ha selecionado Numero Nodos" << endl, 
        cout << "El numero de nodos es " << a1.NumNodos() << endl;
        break;
      case 13: cout << "Ha selecionado Vacio" << endl;
        if(a1.Vacio()){
          cout << "El arbol esta vacio." << endl;
        } else {
          cout << "El arbol no esta vacio" << endl;
        }
        break;
      case 14: cout << "Ha selecionado Vaciar" << endl;
        a1.Vaciar();
        cout << "Se ha vaciado el arbol" << endl;
      case 15: cout << "Ha seleccionado Destruir" << endl;
        a1.~Arbol();
        cout << "Se ha destruido el arbol" << endl;
        break;
      case 16: cout << "Ha saleccionado Salir", stop = true;
        a1.~Arbol();
        break;
      default: cout << "Respuesta inválida" << endl;
    }
  }
}

int main () {
  int respuesta;
  cout <<  "****  MENU  ***" << endl;
  cout << "1) Desea utilizar el modelo Arbol" << endl;
  cout << "2) Desea utilizar el modelo Cola" << endl;
  cout << "3) Desea salir del programa" << endl;
  cout << "Por favor utilice sólo los números dados según lo que desee hacer" << endl;
  cout << "Ingrese su respuesta: " << endl;
  cin >> respuesta;
  switch (respuesta) {
    case 1 : cout << "Ha seleccionado el modelo árbol" << endl, submenuArbol();
    break;
    case 2 : cout << "Ha seleccionado el modelo cola" << endl, submenuCola();
    break;
    case 3 : cout << "Programa finalizado" << endl;
    break;
    default: cout << "Respuesta inválida" << endl;
  }

  return 0;
}