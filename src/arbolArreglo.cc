#include <arbolArreglo.hh>

/**
 * Efecto: Inicializa el Árbol.
 * Requiere: Árbol no inicializado o Árbol destruido.
 * Modifica: El Árbol.
 */
Arbol::Arbol(){
}

/**
 * Efecto: Destruye el Árbol.
 * Requiere: Árbol inicializado.
 * Modifica: El Árbol.
 */
Arbol::~Arbol(){
}

/**
 * Efecto: Vacía el Árbol.
 * Requiere: Árbol inicializado.
 * Modifica: El Árbol.
 */
void Arbol::Vaciar(){
    ultimo = 0;
}

/**
 * Efecto: Devuelve verdadero si el Árbol está vacío y falso si no.
 * Requiere: Árbol inicializado.
 * Modifica: N/A
 */
bool Arbol::Vacio(){
    if(ultimo == 0){
        return true;
    }
    return false;
}

/*
 * Efecto: Crea la raíz del Árbol, con etiqueta e.
 * Requiere: Árbol inicializado y vacío.
 * Modifica: El Árbol.
*/
void Arbol::PonerRaiz(int e){
    //Raíz siempre va en la primera posición. Desperdiciamos un espacio en el array pero no necesitamos una variable
    //extra para diferenciar si el arreglo está vacio o no.
    arreglo[1].Etiqueta = e;
    arreglo[1].Padre = -1;
    ultimo = 1;
}

/*
 * Efecto: Agrega un nodo hijo con la etiqueta e en la posición k de la lista de hijos del nodo n. 
   Si la posición k está ocupada, todos los hijos con una posición mayor o igual a k se desplazan una posición 
   hacia la derecha y se asigna la posición k al nuevo nodo.
 * Requiere: Árbol inicializado, n válido en A, k mayor o igual a 1 y menor o igual al número de hijos + 1.
 * Modifica: El Árbol.
*/
//Se asume que usuario es responsable y no va a agregar más de 20 nodos.
nodo_t Arbol::AgregarHijo(nodo_t n, int e, int k){
    //Debemos considerar que importa el orden de los hijos. 
    //Etiquetas
    int contadorHermanos = 0;
    nodo_t nodoNuevo;
    int posicionActual = 2; //no consideramos a la raíz
    int etiquetaAux = -1;
    int etiquetaAux2 = -1;
    
    while (posicionActual <= ultimo) 
    {
        //Si se encontró a un hermano
        if(arreglo[posicionActual].Padre == n){
            //si el hermano está en la posición k
            contadorHermanos++;
            if(contadorHermanos == k){
                //Debemos insertar y realizar corrimientos
                etiquetaAux = arreglo[posicionActual].Etiqueta;
                arreglo[posicionActual].Etiqueta = e;
                nodoNuevo = posicionActual;

            }else{
                //Debemos continuar el corrimiento
                if(contadorHermanos > k){
                    etiquetaAux2 = arreglo[posicionActual].Etiqueta;
                    arreglo[posicionActual].Etiqueta = etiquetaAux;
                    etiquetaAux = etiquetaAux2;
                }
            }
        }
        posicionActual ++;
    }
    ultimo++;
    if(etiquetaAux == -1){
        //En este caso el nodo nuevo se inserta en la posición final. Notar que no diferencia si K = numHijos + 1 o k > numHijos + 1 
        arreglo[ultimo].Etiqueta = e;
        arreglo[ultimo].Padre = n;
        nodoNuevo = ultimo;
    }else{
        //Terminar el corrimiento
        arreglo[ultimo].Etiqueta = etiquetaAux;
        arreglo[ultimo].Padre = n;
    }
    return nodoNuevo;
}

/*
 * Efecto: Borra el nodo n del árbol. 
 * Requiere: Árbol inicializado,  nodo n válido y sin hijos.
 * Modifica: El Árbol.
*/
void Arbol::BorrarHoja(nodo_t n){
    //Se deben realizar corrimientos 
    nodo_t posicionActual = n;
    while(posicionActual < ultimo){
        arreglo[posicionActual].Etiqueta = arreglo[posicionActual + 1].Etiqueta;
        arreglo[posicionActual].Padre = arreglo[posicionActual + 1].Padre;
        posicionActual++;
    }
    ultimo--;
}

/*
 * Efecto: Cambia la etiqueta del nodo n al valor e. 
 * Requiere: Árbol inicializado y nodo n válido en este.
 * Modifica: El Árbol.
*/
void Arbol::ModificarEtiqueta(nodo_t n, int e){
    arreglo[n].Etiqueta = e;
}

/*
 * Efecto: Devuelve el nodo raíz del Árbol. Si está vacío devuelve 		 NodoNulo.
 * Requiere: Árbol inicializado.
 * Modifica: N/A
*/
nodo_t Arbol::Raiz(){
    return 1;
}

/*
 * Efecto: Devuelve el i-esimo nodo hijo del nodo n. Si el i-esimo término no existe, devuelve NodoNulo. 
 * Requiere: Árbol inicializado, n válido en A. 
 * Modifica: N/A
*/
nodo_t Arbol::Hijo(nodo_t n, int i){
    nodo_t posicionActual = n+1;
    nodo_t nodoHijo = -1;
    int contadorHijos = 0;
    bool continuar = true;
    while (continuar && posicionActual <= ultimo)
    {    
        if(arreglo[posicionActual].Padre == n){
            contadorHijos ++;
            if(contadorHijos == i){
                continuar = false;
                nodoHijo = posicionActual;
            } 
                
        }
        posicionActual ++;
    }
    return nodoHijo;   
}

/*
 * Efecto: Devuelve el padre de n. Si n es la raíz devuelve NodoNulo.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
*/
nodo_t Arbol::Padre(nodo_t n){
    return arreglo[n].Padre;
}

/*
 * Efecto: Devuelve el hermano derecho de n. Si no existe devuelve NodoNulo.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
*/
nodo_t Arbol::HermanoDerecho(nodo_t n){
    nodo_t posicionActual = n + 1;
    nodo_t nodoPadre = Padre(n);
    bool continuar = true;
    while(posicionActual <= ultimo && continuar){
        if(arreglo[posicionActual].Padre == nodoPadre){
            continuar = false;
        }else{
            posicionActual++;
        }
    }
    if(!continuar){
        return posicionActual;
    }else {
        return -1;
    }   
}

/*
 * Efecto: Devuelve el hermano izquierdo de n. Si no existe devuelve NodoNulo.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
*/
nodo_t Arbol::HermanoIzquierdo(nodo_t n){
    nodo_t posicionActual = n - 1;
    nodo_t nodoPadre = arreglo[n].Padre;
    bool continuar = true;
    while(posicionActual > 1 && continuar){
        if(arreglo[posicionActual].Padre == nodoPadre){
            continuar = false;
        }else{
            posicionActual--;
        }
    }
    if(!continuar){
        return posicionActual;
    }else {
        return -1;
    }
    
}

/**
 * Efecto: Devuelve el hermano izquierdo de n. Si no existe devuelve NodoNulo.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
 */
int Arbol::Etiqueta(nodo_t n){
    return arreglo[n].Etiqueta;
}

/*
 * Efecto: Devuelve la cantidad de hijos de n.
 * Requiere: Árbol inicializado y n válida en este.
 * Modifica: N/A
*/
int Arbol::NumHijos(nodo_t n){
    nodo_t posicionActual = n;
    int contadorHijos = 0;
    while(posicionActual <= ultimo){
        if(arreglo[posicionActual].Padre == n){
            contadorHijos++;
        }
        posicionActual++;
    }
    return contadorHijos++;
}

/*
 * Efecto: Devuelve la cantidad de nodos del Árbol.
 * Requiere: Árbol inicializado.
 * Modifica: N/A
*/
int Arbol::NumNodos(){
    return ultimo;
}

nodo_t Arbol::NodoNulo(){
    return -1;
}
