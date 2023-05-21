#include <arbolHMI_HD.hh>

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
        if(n->hijoFinal == false){
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
    raiz = new caja{e, nullptr, nullptr, false};
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
        // asignamos al padre como "hermano derecho"
        nuevoNodo = new caja{e, nullptr, n, true};
        n->HijoMasIzquierdo = nuevoNodo;
    } else{

        //Si el k no es valido, el programa se va a caer porque va a realizar nullptr->HermanoDerecho    
        while (i < k && continuar){
            //Este if es para poder diferencia cuando se insertar en la posición NumHijos o NumHijos + 1
            if(nodoAux->hijoFinal == true){
                continuar = false;
            }else{
                nodoAux = nodoAux->HermanoDerecho;
            }
        }

        if(!continuar){
            //Insertar al final de la lista de hijos
            nuevoNodo = new caja{e, nullptr, nodoAux->HermanoDerecho, true}; //HermanoDerecho es el padre
            nodoAux->hijoFinal = false;

        } else { 
            //Hay que realizar desplazamientos 
            etiquetaAux = nodoAux->valor;
            nodoAux->valor = e;
            //
            if(nodoAux->hijoFinal == true){
            //Caso en que es el "nodo final", por lo que hay que señalar al padre
                nuevoNodo = new caja{etiquetaAux, nullptr, n, true};
                nodoAux->hijoFinal = false;
            }else {
                //Caso en que no es el "nodo final"
                nuevoNodo = new caja{etiquetaAux, nullptr, nodoAux->HermanoDerecho, false};
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


void Arbol::ModificaEtiqueta(nodo_t n, int e){
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
        return nullptr;
    }  
}

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

nodo_t Arbol::HermanoDerecho(nodo_t n){
    return n->HermanoDerecho;
}

//HermanoIzquierdo
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

/*
Creo que nos puede ayudar para la siguiente parte de la tarea 
nodo_t Arbol::Padre(nodo_t n){
    if(n == raiz){
        return nullptr;
    } else {
        return (PadreRecursivo(n, raiz));
    }
}

nodo_t Arbol::PadreRecursivo(nodo_t n_buscado, nodo_t n_actual){
    //if(n == nullptr){
      //  return nullptr;
    //}

    nodo_t cajaHijo = n_actual->HijoMasIzquierdo;
    nodo_t cajaPadre;

    //if(cajaHijo == n_buscado){
      //  return n_actual;
    //}

    while(cajaHijo != nullptr){
        if(cajaHijo == n_buscado){
            return n_actual;
        }

        cajaPadre = PadreRecursivo(n_buscado, cajaHijo);

        if(cajaPadre != nullptr){
            return cajaPadre;
        }

        cajaHijo = cajaHijo->HermanoDerecho;

    }

    return nullptr;
}
*/

