// Modelo Árbol utilizando la estructura de datos Hijo más Izquierdo-Hermano Derecho por punteros, 
// tal que el último hijo de un nodo apunta a su padre

#include <arbolHMI_HD_PTR.hh>

/*
 * Efecto: Inicializa el Árbol.
 * Requiere: Árbol no inicializado o Árbol destruido.
 * Modifica: El Árbol.
*/
Arbol::Arbol() : raiz(nullptr)
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
void Arbol::Vaciar(){
    if(raiz != nullptr){
        VaciarRecursivo(raiz);
    }
}

void Arbol::VaciarRecursivo(nodo_t n){
    if(n!=nullptr){
        VaciarRecursivo(n->HijoMasIzquierdo);
        if(n->HermanoDerecho != nullptr){
            VaciarRecursivo(n->HermanoDerecho);
        }
        delete n;
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
    raiz = new caja{e, nullptr, nullptr, nullptr, nullptr};
    contadorNodos++;
}

/*
 * Efecto: Agrega un nodo hijo con la etiqueta e en la posición k de la lista de hijos del nodo n. 
   Si la posición k está ocupada, todos los hijos con una posición mayor o igual a k se desplazan una posición 
   hacia la derecha y se asigna la posición k al nuevo nodo.
 * Requiere: Árbol inicializado, n válido en A, k mayor o igual a 1 y menor o igual al número de hijos + 1.
 * Modifica: El Árbol.
*/
nodo_t Arbol::AgregarHijo(nodo_t n, int e, int k){ //se asume que método recibe k valida. 
    nodo_t nuevoNodo = nullptr;
    nodo_t nodoAux = n->HijoMasIzquierdo;
    int etiquetaAux;
    bool continuar = true;
    int i = 1;
    //Caso en que nodo n no tiene hijos 
    if(nodoAux == nullptr && k == 1){
        nuevoNodo = new caja{e, nullptr, nullptr, n, nullptr};
        n->HijoMasIzquierdo = nuevoNodo;
    } else{
        //Si el k no es valido, el programa se va a caer porque va a realizar nullptr->HermanoDerecho    
        while (i < k && continuar){
            //Este if es para poder diferencia cuando se insertar en la posición NumHijos o NumHijos + 1
            //Esto no sería necesario si tubieramos un contador para la cantidad de hijos.
            if(nodoAux->HermanoDerecho == nullptr){
                continuar = false;
            }else{
                nodoAux = nodoAux->HermanoDerecho;
                i++;
            }
        }

        if(!continuar){
            //Insertar al final de la lista de hijos
            nuevoNodo = new caja{e, nullptr, nullptr, n, nodoAux}; 

        } else { 
            //Hay que realizar desplazamientos 
            etiquetaAux = nodoAux->valor;
            nodoAux->valor = e;
            //
            if(nodoAux->HermanoDerecho == nullptr){
            //Caso en que es el "nodo final", por lo que no tiene hermano derecho
                nuevoNodo = new caja{etiquetaAux, nullptr, nullptr, n, nodoAux};
            }else {
                //Caso en que no es el "nodo final", tiene hermano derecho
                nuevoNodo = new caja{etiquetaAux, nullptr, nodoAux->HermanoDerecho, n, nodoAux};
            }
            //
        }
        nodoAux->HermanoDerecho = nuevoNodo;
    }
    contadorNodos++; 
    return nuevoNodo;
}

/*
 * Efecto: Borra el nodo n del árbol. 
 * Requiere: Árbol inicializado,  nodo n válido y sin hijos.
 * Modifica: El Árbol.
*/
void Arbol::BorrarHoja(nodo_t n){
    if(n == raiz){
        //Liberamos la memoria 
        delete raiz;
        raiz = nullptr;
        contadorNodos--;
        return;
    }
    //Notar que al momento de borrar una hoja hay 3 posibilidades.
    //1) Hoja es el hijo más izquierdo [con hermanoDerecho o sin hermanoDerecho]
    //2) Hoja es un hijo del "centro"
    //3) Hoja es el hijo más derecho
    //Lo anterior afecta las modificaciones que hay que hacer para los miembros del struct. 
    nodo_t nodoPadre = n->Padre;
    nodo_t nodoAux = nodoPadre->HijoMasIzquierdo;
    nodo_t nodoHermanoIzquierdo;
    if(n == nodoAux){
        //n es el hijo más izquierdo y no tiene hermano derecho 
        if(nodoAux->HermanoDerecho == nullptr){
            nodoPadre->HijoMasIzquierdo = nullptr;
        } else {
            //tiene hermano derecho 
            nodoPadre -> HijoMasIzquierdo = nodoAux->HermanoDerecho;
            nodoAux->HermanoDerecho->HermanoIzquierdo = nullptr;
        }
    } else{
        //Nodo a borrar está "en medio" de otros dos nodos o es el nodo más derecho.
        nodoHermanoIzquierdo = n->HermanoIzquierdo;
        //Es el hijo final
        if(n->HermanoDerecho == nullptr){
            nodoHermanoIzquierdo->HermanoDerecho = nullptr;
        }else{
            //Es hijo "intermedio"
            nodoHermanoIzquierdo->HermanoDerecho = n->HermanoDerecho;
            n->HermanoDerecho->HermanoIzquierdo = nodoHermanoIzquierdo;
            
        }

    }
    delete n;
    contadorNodos--;
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
 * Efecto: Devuelve el nodo raíz del Árbol. Si está vacío devuelve 		 NodoNulo.
 * Requiere: Árbol inicializado.
 * Modifica: N/A
*/
nodo_t Arbol::Raiz(){
    return raiz;
}

/* 
 * Efecto: Devuelve el i-esimo nodo hijo del nodo n. Si el i-esimo término no existe, devuelve NodoNulo. 
 * Requiere: Árbol inicializado, n válido en A. 
 * Modifica: N/A
*/
nodo_t Arbol::Hijo(nodo_t n, int i){
    nodo_t nodoAux = n->HijoMasIzquierdo;
    int contador = 1;
    while (nodoAux != nullptr && contador<i)
    {
        nodoAux = nodoAux->HermanoDerecho;
        contador ++;
        //cout << "count: " << contador << endl;
    }
    
    if(nodoAux != nullptr){
        //cout << "diferente" << endl;
        return nodoAux;
    }else{
        cout << "Igual" << endl;
        return nullptr;
    }  
}

 /*
 * Efecto: Devuelve el padre de n. Si n es la raíz devuelve NodoNulo.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
 */
nodo_t Arbol::Padre(nodo_t n){
    if(n == raiz){
        return nullptr;
    } else {
        return n->Padre;
    }
}

/*
* Efecto: Devuelve el hermano derecho de n. Si no existe devuelve NodoNulo.
* Requiere: Árbol inicializado y n válida en este.
* Modifica: N/A
*/
nodo_t Arbol::HermanoDerecho(nodo_t n){
    if(n == raiz){
        return nullptr;
    } else {
        return n->HermanoDerecho;
    }
}

/*
 * Efecto: Devuelve el hermano izquierdo de n. Si no existe devuelve NodoNulo.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
*/
nodo_t Arbol::HermanoIzquierdo(nodo_t n){
    if(n == raiz){
        return nullptr;
    }else{
        return n->HermanoIzquierdo;
    } 
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
 * Efecto: Devuelve la cantidad de hijos de n.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
*/
int Arbol::NumHijos(nodo_t n){
    int contador = 0;
    nodo_t nodoAux = n->HijoMasIzquierdo;
    while (nodoAux != nullptr)
    {
        nodoAux = nodoAux->HermanoDerecho;
        contador++;
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

//borrar -> Destructor 
void Arbol::funciona(){
    cout << "Sí funciono" << endl;
    if (raiz == nullptr)
    {
        cout << "Raíz nula" << endl;  
    } else {
        cout << "Raíz ptr:" << raiz << endl;  
    }  
}

nodo_t Arbol::NodoNulo(){
    return nullptr;
}
