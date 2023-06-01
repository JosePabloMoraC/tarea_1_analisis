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
