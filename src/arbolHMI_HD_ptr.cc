#include <arbolHMI_HD_PTR.hh>

Arbol::Arbol() : raiz(nullptr)
{
}

Arbol::~Arbol()
{
    Vaciar(); 
}


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

bool Arbol::Vacio(){
    if(raiz == nullptr){
        return true;
    }else {
        return false;
    }
}

void Arbol::PonerRaiz(int e){
    raiz = new caja{e, nullptr, nullptr, nullptr, nullptr};
    contadorNodos++;
}

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


void Arbol::ModificarEtiqueta(nodo_t n, int e){
    n->valor = e;
}


nodo_t Arbol::Raiz(){
    return raiz;
}

//falta
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

nodo_t Arbol::Padre(nodo_t n){
    if(n == raiz){
        return nullptr;
    } else {
        return n->Padre;
    }
}

nodo_t Arbol::HermanoDerecho(nodo_t n){
    if(n == raiz){
        return nullptr;
    } else {
        return n->HermanoDerecho;
    }
}

//HermanoIzquierdo
nodo_t Arbol::HermanoIzquierdo(nodo_t n){
    if(n == raiz){
        return nullptr;
    }else{
        return n->HermanoIzquierdo;
    } 
}


int Arbol::Etiqueta(nodo_t n){
    return n->valor;
}

//NumHijos
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

//NumNodos
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
