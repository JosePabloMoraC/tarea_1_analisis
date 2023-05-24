//Modelo Árbol utilizando la estructura de datos Lista de Hijos por Lista Simplemente Enlazada y Lista Simplemente Enlazada

#include <arbolHMI_HD.hh>

/*
 * Efecto: Inicializa el Árbol.
 * Requiere: Árbol no inicializado o Árbol destruido.
 * Modifica: El Árbol.
*/
Arbol::Arbol() : raiz(nullptr)
{
}

/**
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
        if(n->hijoFinal == false){
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
    raiz = new caja{e, nullptr, nullptr, false};
    contadorNodos++;
}

/*
 * Efecto: Agrega un nodo hijo con la etiqueta e en la posición k de la lista de hijos del nodo n. 
   Si la posición k está ocupada, todos los hijos con una posición mayor o igual a k se desplazan una posición 
   hacia la derecha y se asigna la posición k al nuevo nodo.
 * Requiere: Árbol inicializado, n válido en A, k mayor o igual a 1 y menor o igual al número de hijos + 1.
 * Modifica: El Árbol.
*/
nodo_t Arbol::AgregarHijo(nodo_t n, int e, int k) {
    nodo_t nuevoNodo = nullptr;
    nodo_t nodoAux = n->HijoMasIzquierdo;
    int etiquetaAux;
    bool continuar = true;
    int i = 1;
    
    // Caso en que el nodo n no tiene hijos
    if (nodoAux == nullptr && k == 1) {
        nuevoNodo = new caja{ e, nullptr, n, true }; // El último nodo apunta al padre
        n->HijoMasIzquierdo = nuevoNodo;
    } else {
        while (i < k && continuar) {
            if (nodoAux->hijoFinal == true) {
                continuar = false;
            } else {
                nodoAux = nodoAux->HermanoDerecho;
            }
            i++;
        }

        if (!continuar) {
            // Insertar al final de la lista de hijos
            nuevoNodo = new caja{ e, nullptr, n, true }; // El último nodo apunta al padre
            if (nodoAux != nullptr) {
                nodoAux->hijoFinal = false;
                nodoAux->HermanoDerecho = nuevoNodo;
            } else {
                n->HijoMasIzquierdo = nuevoNodo;
            }
        } else {
            // Hay que realizar desplazamientos
            etiquetaAux = nodoAux->valor;
            nodoAux->valor = e;
            
            if (nodoAux->hijoFinal == true) {
                // Caso en que es el "nodo final", por lo que hay que señalar al padre
                nuevoNodo = new caja{ etiquetaAux, nullptr, n, true }; // El último nodo apunta al padre
                nodoAux->hijoFinal = false;
                nodoAux->HermanoDerecho = nuevoNodo;
            } else {
                // Caso en que no es el "nodo final"
                nuevoNodo = new caja{ etiquetaAux, nullptr, nodoAux->HermanoDerecho, false };
                nodoAux->HermanoDerecho = nuevoNodo;
            }
        }
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
    nodo_t nodoPadre = Padre(n);
    nodo_t nodoAux = nodoPadre->HijoMasIzquierdo;
    nodo_t nodoHermanoIzquierdo;
    if(n == nodoAux){
        // n es el hijo más izquierdo y no tiene hermano derecho 
        if(nodoAux->hijoFinal == true){
            nodoPadre->HijoMasIzquierdo = nullptr;
        } else {
            //tiene hermano derecho 
            nodoPadre -> HijoMasIzquierdo = nodoAux->HermanoDerecho;
        }
    } else{
        //En cualquiera de los dos casos restantes se necesita al hermano izquierdo. Podríamos usar el método HermanoIzquierdo,
        //pero este método llama al método Padre(), por lo que estaríamos recorriendo dos veces el árbol para obtener al padre.
        //por eso, aquí vamos a obtener al hermano izquierdo con el método auxiliar. 
        nodoHermanoIzquierdo = HermanoIzquierdoAux(n, nodoPadre);
        //Es el hijo final
        if(n->hijoFinal == true){
            nodoHermanoIzquierdo->HermanoDerecho = nodoPadre;
            nodoHermanoIzquierdo->hijoFinal = true;
        }else{
            //Es hijo "intermedio"
            nodoHermanoIzquierdo->HermanoDerecho = n->HermanoDerecho;
        }

    }
    delete n;
    contadorNodos--;
}

/*
 * Efecto: Cambia la etiqueta del nodo n al valor e. 
 * Requiere: Árbol inicializado y nodo n válido en este.
 * Modifica: El Árbol.
*/
void Arbol::ModificarEtiqueta(nodo_t n, int e){
    n->valor = e;
}

/*
 * Efecto: Devuelve el nodo raíz del Árbol. Si está vacío devuelve NodoNulo.
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
        return nullptr;
    }  
}

/*
 * Padre(Arbol_T A, Nodo_T n)  nodo
 * Efecto: Devuelve el padre de n. Si n es la raíz devuelve NodoNulo.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
*/
nodo_t Arbol::Padre(nodo_t n){
    if(n == raiz){
        return nullptr;
    } else {
        nodo_t nodoAuxiliar = n;
        
        while (nodoAuxiliar != nullptr)
        {
            if(nodoAuxiliar->hijoFinal == true){
                return nodoAuxiliar->HermanoDerecho;
            }
            nodoAuxiliar = nodoAuxiliar->HermanoDerecho;
        }
        
    }
    //Notar que esto se pone por solicitud del compilador, pero si el árbol esta bien construido, nunca se debería ejecutar está ultima linea.
    return nullptr;
}

/*
 * Efecto: Devuelve el hermano derecho de n. Si no existe devuelve NodoNulo.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
*/
nodo_t Arbol::HermanoDerecho(nodo_t n){
    if(n == raiz){
        return nullptr;
    }

    if(n->hijoFinal == true){
        return nullptr;
    }
    return n->HermanoDerecho;
}

/*
 * Efecto: Devuelve el hermano izquierdo de n. Si no existe devuelve NodoNulo.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
*/
nodo_t Arbol::HermanoIzquierdo(nodo_t n){
    if(n == raiz){
        return nullptr;
    }
    return HermanoIzquierdoAux(n, Padre(n));
}


nodo_t Arbol::HermanoIzquierdoAux(nodo_t n, nodo_t padre){
    nodo_t nodoAux = padre->HijoMasIzquierdo;
    bool continuar = true;

    while (continuar && nodoAux != nullptr)
    {
        if(nodoAux->HermanoDerecho == n){
            continuar = false;
        } else {
            nodoAux = nodoAux->HermanoDerecho;
        }

    }

    return nodoAux;
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
    bool continuar = true;
    while (nodoAux != nullptr && continuar)
    {
        if(nodoAux->hijoFinal == true){
            continuar = false;
        }
        nodoAux = nodoAux->HermanoDerecho;
        contador++;
        
    }
    return contador; 
}

/**
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



