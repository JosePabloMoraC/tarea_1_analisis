#include <arbol_lista.hh>
// Modelo Árbol utilizando la estructura de datos Lista de Hijos por lista simplemente enlazada
// (lista principal) y lista simplemente enlazada (sublistas).

/*
 * Efecto: Inicializa el Árbol.
 * Requiere: Árbol no inicializado o Árbol destruido.
 * Modifica: El Árbol.
*/
Arbol::Arbol() : raiz(nullptr), contadorNodos(0)
{
}

/*
 * Efecto: Destruye el Árbol.
 * Requiere: Árbol inicializado.
 * Modifica: El Árbol.
*/
Arbol::~Arbol()
{
    Vaciar(); 
}

/*
 * Efecto: Vacía el Árbol.
 * Requiere: Árbol inicializado.
 * Modifica: El Árbol.
 */
void Arbol::Vaciar() {
    if (raiz != nullptr) {
        nodo_t principalAux1;
        nodo_t principalAux2;
        cajaHijo* sublistaAux1;
        cajaHijo* sublistaAuxAnterior;
        contadorNodos = 0; 
        principalAux1 = raiz;
        raiz = nullptr;
        //Ciclo externo para borrar las cajas de la lista principal
        while(principalAux1 != nullptr){
            sublistaAux1 = principalAux1->sublista;
            //Ciclo interno para borrar las cajas de la lista de hijos
            while(sublistaAux1 != nullptr){
                sublistaAuxAnterior = sublistaAux1->siguiente;
                delete(sublistaAux1);
                sublistaAux1 = sublistaAuxAnterior;
            }
            principalAux2 = principalAux1->siguiente;
            delete(principalAux1);
            principalAux1 = principalAux2;
        }

    }
}

/*
 * Efecto: Devuelve verdadero si el Árbol está vacío y falso si no.
 * Requiere: Árbol inicializado.
 * Modifica: N/A
*/
bool Arbol::Vacio(){
    if(raiz == nullptr){
        return true;
    }else {
        return false;
    }
}

/*
 * Efecto: Crea la raíz del Árbol, con etiqueta e.
 * Requiere: Árbol inicializado y vacío.
 * Modifica: El Árbol.
*/
void Arbol::PonerRaiz(int e){
    raiz = new cajaPrincipal{e, nullptr, nullptr};
    contadorNodos++;
}

/*
 * Efecto: Devuelve el nodo raíz del Árbol. Si está vacío devuelve 		 NodoNulo.
 * Requiere: Árbol inicializado.
 * Modifica: N/A
*/
nodo_t Arbol::Raiz(){
    return raiz;
}

/*
 * Efecto: Devuelve la etiqueta de n.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
*/
int Arbol::Etiqueta(nodo_t n){

    return n->valor;
}

/*
 * Efecto: Cambia la etiqueta del nodo n al valor e. 
 * Requiere: Árbol inicializado y nodo n válido en este.
 * Modifica: El Árbol
*/
void Arbol::ModificarEtiqueta(nodo_t n, int e){
    n->valor = e;
}


/*
 * Efecto: Agrega un nodo hijo con la etiqueta e en la posición k de la lista de hijos del nodo n. 
   Si la posición k está ocupada, todos los hijos con una posición mayor o igual a k se desplazan una posición 
   hacia la derecha y se asigna la posición k al nuevo nodo.
 * Requiere: Árbol inicializado, n válido en A, k mayor o igual a 1 y menor o igual al número de hijos + 1.
 * Modifica: El Árbol.
*/
nodo_t Arbol::AgregarHijo(nodo_t n, int e, int k)
{
    //Creamos un nuevo nodo hijo
    //Siempre se mete como primero despues de la raíz 
    nodo_t nuevoNodo = new cajaPrincipal(); 
    nuevoNodo->valor = e;
    nuevoNodo->siguiente = raiz->siguiente; //Se asume que método únicamente se llama cuando el árbol tiene raíz 

    //Le asignamos a la raíz el nuevo siguiente
    raiz->siguiente = nuevoNodo;

    //Creamos la nueva caja para la lista de hijos
    cajaHijo* nuevoHijoLista = new cajaHijo;
    nuevoHijoLista->principal = nuevoNodo;

    
    // Verificamos si el nodo padre tiene hijos
    if (n->sublista == nullptr) {
        // Si no tiene hijos, asignamos el nuevo nodo hijo como el primer hijo
        n->sublista = nuevoHijoLista;
    } 
    else {
        // Si ya tiene hijos, buscamos la posición para insertar el nuevo nodo
        cajaHijo* nodoActual = n->sublista;
        int contador = 1;

        while (nodoActual->siguiente != nullptr && contador < k) {
            nodoActual = nodoActual->siguiente;
            contador++;
        }

        if(nodoActual->siguiente == nullptr && contador < k){
            //Insertar en la posición del final
            nodoActual->siguiente = nuevoHijoLista;
        } else {
            //Posición que necesitamos está "en medio"
            //"Abrimos espacio" y realizamos la inserción
            nuevoHijoLista->siguiente = nodoActual->siguiente;
            nuevoHijoLista->principal = nodoActual->principal;

            nodoActual->siguiente = nuevoHijoLista;
            nodoActual->principal = nuevoNodo;
        }

    }
    contadorNodos++;  // Incrementamos el contador de nodos del árbol
    return nuevoNodo;
}



/* 
 * Efecto: Devuelve el i-esimo nodo hijo del nodo n. Si el i-esimo término no existe, devuelve NodoNulo. 
 * Requiere: Árbol inicializado, n válido en A. 
 * Modifica: N/A
*/
nodo_t Arbol::Hijo(nodo_t n, int i){
    cajaHijo* nodoAux = n->sublista;
    int contador = 1;

    while (nodoAux != nullptr && contador<i)
    {
        nodoAux = nodoAux->siguiente;
        contador ++;
        //cout << "count: " << contador << endl;
    }
    
    if(nodoAux != nullptr){
        //cout << "diferente" << endl;
        return nodoAux->principal;
    }else{
        return nullptr;
    }  
}


 /*
 * Efecto: Devuelve el padre de n. Si n es la raíz devuelve NodoNulo.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
 */
nodo_t Arbol::Padre(nodo_t n){
    if(n == raiz) {
        return nullptr;
    }
    
    bool continuar = true;
    nodo_t nodoActual = raiz;
    nodo_t nodoIzquierdo = nullptr;
    cajaHijo* nodoLista;
    //Iterar sobre lista principal
    while(nodoActual != nullptr && continuar){
        nodoLista = nodoActual->sublista;
        //Iterar sobre lista de hijos
        while(nodoLista != nullptr && continuar){
            if(nodoLista->principal == n){
                continuar = false;
                nodoIzquierdo = nodoActual;
            }
            nodoLista = nodoLista->siguiente;
        }
        nodoActual = nodoActual->siguiente;
    }
    return nodoIzquierdo;
}

/*
* Efecto: Devuelve el hermano derecho de n. Si no existe devuelve NodoNulo.
* Requiere: Árbol inicializado y n válida en este.
* Modifica: N/A
*/
nodo_t Arbol::HermanoDerecho(nodo_t n) {
    if (n == nullptr || n == raiz) {
        return nullptr;
    }
    //Misma lógica de Padre()
    bool continuar = true;
    nodo_t nodoActual = raiz;
    nodo_t nodoIzquierdo = nullptr;
    cajaHijo* nodoLista;
    //Iterar sobre lista principal
    while(nodoActual != nullptr && continuar){
        nodoLista = nodoActual->sublista;
        //Iterar sobre lista de hijos
        while(nodoLista != nullptr && continuar){
            if(nodoLista->principal == n){
                continuar = false;
                if(nodoLista->siguiente != nullptr){
                    nodoIzquierdo = nodoLista->siguiente->principal;
                }
            }
            nodoLista = nodoLista->siguiente;
        }
        nodoActual = nodoActual->siguiente;
    }
    return nodoIzquierdo;
}

/*
 * Efecto: Devuelve el hermano izquierdo de n. Si no existe devuelve NodoNulo.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
*/
nodo_t Arbol::HermanoIzquierdo(nodo_t n) {
    if (n == nullptr || n == raiz) {
        return nullptr;
    }
    //Misma lógica de Padre()
    bool continuar = true;
    nodo_t nodoActual = raiz;
    nodo_t nodoIzquierdo = nullptr;
    cajaHijo* nodoLista;
    cajaHijo* nodoListaAnterior;
    //Iterar sobre lista principal
    while(nodoActual != nullptr && continuar){
        nodoListaAnterior = nodoActual->sublista;
        //Si nodoListaAnterior->principal == n, entonces n es el primer elemento de la lista de hijos y no tiene hermano derecho
        if(nodoListaAnterior->principal == n){
            continuar = false;
        } else {
            nodoLista = nodoListaAnterior->siguiente;
            //Iterar sobre lista de hijos
            //aquí
            while(nodoLista != nullptr && continuar){
                if(nodoLista->principal == n){
                    continuar = false;
                    nodoIzquierdo = nodoListaAnterior->principal;
                }
                nodoListaAnterior = nodoLista;
                nodoLista = nodoLista->siguiente;
            }
            nodoActual = nodoActual->siguiente;
            }
    }
    return nodoIzquierdo; 
}


/*
 * Efecto: Devuelve la cantidad de hijos de n.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
*/
int Arbol::NumHijos(nodo_t n) {
    int contador = 0;

    if (n == nullptr || n->sublista == nullptr) {
        // Si el nodo es nulo o no tiene hijos
        return contador;
    }

    cajaHijo* nodoLista = n->sublista;

    while (nodoLista != nullptr) {
        contador++;
        nodoLista = nodoLista->siguiente;
    }

    return contador;
}

/*
 * Efecto: Devuelve la cantidad de nodos del Árbol.
 * Requiere: Árbol inicializado.
 * Modifica: N/A
*/
int Arbol::NumNodos(){
    return contadorNodos;
}

nodo_t Arbol::NodoNulo(){
    return nullptr;
}


/*
 * Efecto: Borra el nodo n del árbol. 
 * Requiere: Árbol inicializado,  nodo n válido y sin hijos.
 * Modifica: El Árbol.
*/
void Arbol::BorrarHoja(nodo_t n) {
    if(n == raiz){
        //Liberamos la memoria 
        delete(raiz);
        raiz = nullptr;
        contadorNodos--;
        return;
    }
    //Primero hay que encontrar el nodo anterior en la lista principal y además encontrar en que sublista está. Como padre es O(n) no lo vamos a usar
    bool buscarPrincipal = true;
    bool continuarSublista = true;

    nodo_t principalAux;
    cajaHijo* sublistaAux;
    cajaHijo* sublistaAuxAnterior = nullptr;

    principalAux = raiz;
    while((continuarSublista || buscarPrincipal) && principalAux != nullptr){
        sublistaAux = principalAux->sublista;

        //Primero realizamos las verificaciones necesarias para la lista principal
        if(buscarPrincipal && principalAux->siguiente == n){
            buscarPrincipal = false;
            principalAux->siguiente = n->siguiente;
            //Liberamos la memoria (de n) despues, porque aún necesitamos n para comparar dentro del while
        }

        while(continuarSublista && sublistaAux != nullptr){
            if(sublistaAux->principal == n){
                    //Notar que al momento de borrar una hoja hay 3 posibilidades.
                    //1) Hoja es el hijo más izquierdo [con hermanoDerecho o sin hermanoDerecho]
                    //2) Hoja es un hijo del "centro"
                    //3) Hoja es el hijo más derecho
                    //Lo anterior afecta las modificaciones que hay que hacer en las listas.

                    //Caso (1)
                    if(sublistaAux == principalAux->sublista){
                        principalAux->sublista = sublistaAux->siguiente;
                    } else {
                        //Casos (2) y (3)
                        sublistaAuxAnterior->siguiente = sublistaAux->siguiente;
                    }
                    delete(sublistaAux);
                    continuarSublista = false;
            } else {
                sublistaAuxAnterior = sublistaAux;
                sublistaAux = sublistaAux->siguiente;
            }         
        }
        principalAux = principalAux->siguiente;
    }
    delete(n);
}
