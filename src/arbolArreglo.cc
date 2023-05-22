#include <arbolArreglo.hh>

Arbol::Arbol(){
}

Arbol::~Arbol(){
}

void Arbol::Vaciar(){
    ultimo = 0;
}

bool Arbol::Vacio(){
    if(ultimo == 0){
        return true;
    }
    return false;
}


void Arbol::PonerRaiz(int e){
    //Raíz siempre va en la primera posición. Desperdiciamos un espacio en el array pero no necesitamos una variable
    //extra para diferenciar si el arreglo está vacio o no.
    arreglo[1].Etiqueta = e;
    arreglo[1].Padre = -1;
    ultimo = 1;
}

//Se asume que usuario es responsable y no va a agregar más de 30 nodos.
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

void Arbol::ModificarEtiqueta(nodo_t n, int e){
    arreglo[n].Etiqueta = e;
}


nodo_t Arbol::Raiz(){
    return 1;
}


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


nodo_t Arbol::Padre(nodo_t n){
    return arreglo[n].Padre;
}

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


int Arbol::Etiqueta(nodo_t n){
    return arreglo[n].Etiqueta;
}


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

int Arbol::NumNodos(){
    return ultimo;
}

nodo_t Arbol::NodoNulo(){
    return -1;
}
