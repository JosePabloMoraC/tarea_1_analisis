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
    arreglo[1][1] = e;
    arreglo[2][1] = -1;
    ultimo = 1;
}

//Se asume que usuario es responsable y no va a agregar más de 30 nodos.
nodo_t Arbol::AgregarHijo(nodo_t n, int e, int k){
    //Debemos considerar que importa el orden de los hijos. 
    //Etiquetas
    int contadorHermanos = 0;
    nodo_t nodoNuevo = -1;
    nodo_t nodoActual = 2; //no consideramos a la raíz
    nodo_t etiquetaAux = -1;
    nodo_t etiquetaAux2 = -1;
    
    while (nodoActual <= ultimo) 
    {
        //Si se encontró a un hermano
        if(arreglo[2][nodoActual] == n){
            //si el hermano está en la posición k
            contadorHermanos++;
            if(contadorHermanos == k){
                //Debemos insertar y realizar corrimientos
                etiquetaAux = arreglo[1][nodoActual];
                arreglo[1][nodoActual] = e;
                nodoNuevo = nodoActual;

            }else{
                //Debemos continuar el corrimiento
                if(contadorHermanos > k){
                    etiquetaAux2 = arreglo[1][nodoActual];
                    arreglo[1][nodoActual] = etiquetaAux;
                    etiquetaAux = etiquetaAux2;
                }
            }
        }
        nodoActual ++;
    }
    ultimo++;
    if(etiquetaAux == -1){
        //En este caso el nodo nuevo se inserta en la posición final. Notar que no diferencia si K = numHijos + 1 o k > numHijos + 1 
        arreglo[1][ultimo] = e;
        arreglo[2][ultimo] = n;
        cout << "Entre con etiqueta " << e << endl;
        nodoNuevo = ultimo;
    }else{
        //Terminar el corrimiento
        arreglo[1][ultimo] = etiquetaAux;
        arreglo[2][ultimo] = n;
    }
    return nodoNuevo;
}

void Arbol::BorrarHoja(nodo_t n){
    //Se deben realizar corrimientos 
    nodo_t nodoActual = n;
    while(nodoActual < ultimo){
        arreglo[1][nodoActual] = arreglo[1][nodoActual + 1];
        arreglo[2][nodoActual] = arreglo[2][nodoActual + 1];
        nodoActual++;
    }
    ultimo--;
}

void Arbol::ModificarEtiqueta(nodo_t n, int e){
    arreglo[1][n] = e;
}


nodo_t Arbol::Raiz(){
    return 1;
}

nodo_t Arbol::Hijo(nodo_t n, int i){
    nodo_t nodoActual = n+1;
    nodo_t nodoHijo = -1;
    int contadorHijos = 0;
    bool continuar = true;
    while (continuar && nodoActual <= ultimo)
    {    
        if(arreglo[2][nodoActual] == n){
            contadorHijos ++;
            if(contadorHijos == i){
                continuar = false;
                nodoHijo = nodoActual;
            } 
                
        }
        nodoActual ++;
    }
    return nodoHijo;
    
}

nodo_t Arbol::Padre(nodo_t n){
    return arreglo[2][n];
}

nodo_t Arbol::HermanoDerecho(nodo_t n){
    nodo_t nodoActual = n + 1;
    nodo_t nodoPadre = Padre(n);
    bool continuar = true;
    while(nodoActual <= ultimo && continuar){
        if(arreglo[2][nodoActual] == nodoPadre){
            continuar = false;
        }else{
            nodoActual++;
        }
    }
    if(!continuar){
        return nodoActual;
    }else {
        return -1;
    }
    
}


nodo_t Arbol::HermanoIzquierdo(nodo_t n){
    nodo_t nodoActual = n - 1;
    nodo_t nodoPadre = arreglo[2][n];
    bool continuar = true;
    while(nodoActual > 1 && continuar){
        if(arreglo[2][nodoActual] == nodoPadre){
            continuar = false;
        }else{
            nodoActual--;
        }
    }
    if(!continuar){
        return nodoActual;
    }else {
        return -1;
    }
    
}

int Arbol::Etiqueta(nodo_t n){
    return arreglo[1][n];
}

int Arbol::NumHijos(nodo_t n){
    nodo_t nodoActual = n;
    int contadorHijos = 0;
    while(nodoActual <= ultimo){
        if(arreglo[2][nodoActual] == n){
            contadorHijos++;
        }
        nodoActual++;
    }
    return contadorHijos++;
}

int Arbol::NumNodos(){
    return ultimo;
}

nodo_t Arbol::NodoNulo(){
    return -1;
}