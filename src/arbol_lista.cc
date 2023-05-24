#include <arbol_lista.hh>

Arbol::Arbol() : raiz(nullptr)
{
}

Arbol::~Arbol()
{
    Vaciar(); 
}


void Arbol::Vaciar() {
    if (raiz != nullptr) {
        VaciarRecursivo(raiz); 
        raiz = nullptr; 
        final = nullptr; 
        contadorNodos = 0; 
    }
}

void Arbol::VaciarRecursivo(nodo_t n) {
    if (n != nullptr) {
        VaciarRecursivo(n->sublista->principal);
        cajaHijo* nodoLista = n->sublista;
        cajaHijo* borrarLista;
        while (nodoLista != nullptr) {
            borrarLista = nodoLista;
            nodoLista = nodoLista->siguiente;
            delete borrarLista;
        }
        VaciarRecursivo(n->siguiente);
        delete n;
    }
}



bool Arbol::Vacio(){
    if(raiz == nullptr){
        return true;
    }else {
        return false;
    }
}


void Arbol::PonerRaiz(int e){
    raiz = new cajaPrincipal{e, nullptr, nullptr};
    final = raiz;
    contadorNodos++;
}

nodo_t Arbol::Raiz(){
    return raiz;
}

int Arbol::Etiqueta(nodo_t n){

    return n->valor;
}

void Arbol::ModificarEtiqueta(nodo_t n, int e){
    n->valor = e; //
    cajaHijo* nodoHijo = Padre(n)->sublista; //arreglar para 3 etapa...
    bool continuar = true;
    while(continuar && nodoHijo!= nullptr){
        if(nodoHijo->principal == n){
            nodoHijo->valor = e;
            continuar = false;
        } else {
            nodoHijo = nodoHijo->siguiente;
        }
    }

}



nodo_t Arbol::AgregarHijo(nodo_t n, int e, int k)
{
    // Creamos un nuevo nodo hijo
    if(n->sublista == nullptr){
        cout << "FFUUUUUUUUUUC" << endl;
    }
    nodo_t nuevoNodo = new cajaPrincipal;
    cajaHijo* nuevoHijoLista = new cajaHijo;
    //nuevoHijoLista->principal = nuevoNodo;
    nuevoNodo->valor = e;


    // Verificamos si el nodo padre tiene hijos
    if (n->sublista == nullptr) {
        // Si no tiene hijos, asignamos el nuevo nodo hijo como el primer hijo
        n->sublista = nuevoHijoLista;
        nuevoHijoLista->valor = e;
        nuevoHijoLista->siguiente = nullptr;
        nuevoHijoLista->principal = nuevoNodo;
        cout << "Estamos dentro de la raíz con " << n->sublista->valor << endl;
    } 
    else {
        // Si ya tiene hijos, buscamos la posición para insertar el nuevo nodo
        cajaHijo* nodoActual = n->sublista;
        int etiquetaAux;
        int contador = 1;

        while (nodoActual->siguiente != nullptr && contador < k) {
            nodoActual = nodoActual->siguiente;
            contador++;
        }

        if(nodoActual->siguiente == nullptr){
            //Insertar en la posición del final
            nuevoHijoLista->valor = e;
            nodoActual->siguiente = nuevoHijoLista;
            nuevoHijoLista->siguiente = nullptr;
            nuevoHijoLista->principal = nuevoNodo;
        } else {
            //Realizamos la inserción
            etiquetaAux = nodoActual->valor;
            nuevoHijoLista->siguiente = nodoActual->siguiente;
            nuevoHijoLista->principal = nodoActual->principal;
            nodoActual->siguiente = nuevoHijoLista;
            nuevoHijoLista->valor = etiquetaAux;
            nodoActual->principal = nuevoNodo;
        }

    }
    
    final->siguiente = nuevoNodo;

    contadorNodos++;  // Incrementamos el contador de nodos del árbol

    return nuevoNodo;
}




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

nodo_t Arbol::Padre(nodo_t n){
    if(n == raiz) {
        return nullptr;
    }
    
    //int etiqueta = n->valor;
    bool continuar = true;
    nodo_t nodoActual = raiz;
    nodo_t nodoEncontrado = nullptr;
    cajaHijo* nodoLista;

    while(nodoActual != nullptr && continuar){
        nodoLista = nodoActual->sublista;
        while(nodoLista != nullptr && continuar){
            if(nodoLista->principal == n){
                continuar = false;
                nodoEncontrado = nodoActual;
            }
            nodoLista = nodoLista->siguiente;
        }
        if(continuar){
            nodoActual = nodoActual->siguiente;
        }
    }
    return nodoEncontrado;
}

nodo_t Arbol::HermanoDerecho(nodo_t n) {
    if (n == nullptr || n == raiz) {
        return nullptr;
    }

    cajaHijo* nodoLista = Padre(n)->sublista;  //Modificar luego

    while (nodoLista != nullptr) {
        if (nodoLista->principal == n && nodoLista->siguiente != nullptr) {
            // Si el nodo actual de la lista es n
            return nodoLista->siguiente->principal;
        }

        nodoLista = nodoLista->siguiente;
    }
    return nullptr;
}

nodo_t Arbol::HermanoIzquierdo(nodo_t n) {
    if (n == nullptr || n == raiz) {
        return nullptr;
    }
    nodo_t padre = Padre(n);

    cajaHijo* nodoLista = padre->sublista;

    if (nodoLista->principal == n) {
        return nullptr;  // Es el hijo más izq. 
    }

    while (nodoLista->siguiente != nullptr) {
        if (nodoLista->siguiente->principal == n) {
            return nodoLista->principal;
        }

        nodoLista = nodoLista->siguiente;
    }

    return nullptr;  
}



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


int Arbol::NumNodos(){
    return contadorNodos;
}

nodo_t Arbol::NodoNulo(){
    return nullptr;
}

void Arbol::BorrarHoja(nodo_t n) {
    cout << "No nos dio tiempo de implementar este algoritmo. Se agrega en la siguiente etapa. " << endl;
}