#include <tiempoDuracion.hh>
#include <stdio.h>

using namespace std;

void construirArbol(Arbol& a, int k, int n){
    int etiqueta = 2;
    int i = 0;
    int j;
    bool continuar = true;
    nodo_t nodoActual;

    // Inicializamos una cola
    Cola<nodo_t> cola;
    // Agregar raíz del árbol
    a.PonerRaiz(1);
    // Encolar raíz
    cola.agregar(a.Raiz());

    // Bucle enterno se encarga de revisar la cantidad total de nodos
    // (n - 1) porque ya se agregó la raíz
    while (i < n - 1)
    {  
        j = 0;
        nodoActual = cola.sacar();
        // Bucle interno se encarga de insertar hijos
        while(continuar && j < k){   
            if(i == n){
                // Está condición es importante para evitar que el árbol tenga más de n nodos
                continuar = false;
            } else {
                // Agregamos el nuevo nodo al árbol y lo encolamos
                cola.agregar(a.AgregarHijo(nodoActual, etiqueta, j + 1));

                etiqueta++;
                j++;
                i++;
            }

        }
    }
}

int main () {
    cout << "Hola mundo" << endl;
    Arbol a1;
    construirArbol(a1, 5, 30000);
    cout << "La cantidad de niveles del árbol es: " << nivelesArbol(a1) << endl;
    /*
    etiquetasNivel(1, a1);
    cout << "\n" << endl;
    etiquetasNivel(2, a1);
    cout << "\n" << endl;
    etiquetasNivel(3, a1);
    cout << "\n" << endl;
    etiquetasNivel(4, a1);
    cout << "\n" << endl;
    */

    cout << "Fin del programa" << endl;
    std::cin.ignore();

    return 0;
}