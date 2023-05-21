#include <iostream>
#include <ColaLSE.hh>

using namespace std;

void submenuCola(){
  int respuestaC;
  bool stop = false;
  cout <<  "****  Cola  ***" << endl;
  cout <<  "1) Iniciar" << endl;
  cout <<  "2) Agregar" << endl;
  cout <<  "3) Sacar" << endl;
  cout <<  "4) Frente" << endl;
  cout <<  "5) Vacia" << endl;
  cout <<  "6) Vaciar" << endl;
  cout <<  "7) Salir" << endl;
  cout << "Por favor utilice sólo los números dados según lo que desee hacer" << endl;
  while (stop != true) {
    cout << "Ingrese su respuesta: " << endl;
    cin >> respuestaC;
    switch (respuestaC) {
      case 1: cout << "Ha seleccionado iniciar" << endl;
      break;
      case 2: cout << "Ha seleccionado agregar" << endl;
      break;
      case 3: cout << "Ha seleccionado sacar" << endl;
      break;
      case 4: cout << "Ha seleccionado frente" << endl;
      break;
      case 5: cout << "Ha seleccionado vacia" << endl;
      break;
      case 6: cout << "Ha seleccionado vaciar" << endl;
      break;
      case 7: cout << "Ha seleccionado salir" << endl, stop = true;
      break;
      default: cout << "Respuesta inválida" << endl, stop = true;
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
    case 1 : cout << "Ha seleccionado el modelo árbol" << endl;
    break;
    case 2 : cout << "Ha seleccionado el modelo cola" << endl, submenuCola();
    break;
    case 3 : cout << "Salir" << endl;
    break;
    default: cout << "Respuesta inválida" << endl;
  }
  return 0;
}