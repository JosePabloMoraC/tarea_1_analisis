#ifndef TIEMPODURACION_HH
#define TIEMPODURACION_HH

#include <algoritmos.hh>



/* 
* Efecto: construye un árbol k-ésimo con n cantidad de nodos. En caso de que el árbol no este vació, 
* lo vacia previo a la construcción del árbol. La asignación de las etiquedas se da de forma secuencial de 1
* hasta n.  
* Requiere: árbol a inicializado y vacío.
* Modifica: árbol a.
*/
void construirArbol(Arbol& a, int k, int n);

float medirPadrePromedio(Arbol& a, int n, bool ancho);

float medirHermanoDerechoPromedio(Arbol& a, int n, bool ancho);

//Siempre es peor caso
float medirNivelesArbol(Arbol& a, int n, bool ancho);

//Raíz es peor caso
float medirAlturaRaiz(Arbol& a, int n, bool ancho);

//Caso promedio
float medirAlturaPromedio(Arbol& a, int n, bool ancho);

//Se realiza para el peor caso, el ultimo nivel
float medirListarEtiquetasNiveles(Arbol& a, int n, bool ancho);

//Siempre es peor caso
float medirEtiquetasRepetidas(Arbol& a, int n, bool ancho);

//
void imprimirExperimento(int n, bool ancho);



#endif  TIEMPODURACION_HH