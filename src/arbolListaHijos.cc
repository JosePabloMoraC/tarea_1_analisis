#include <arbolListaHijos.hh>

Arbol::Arbol()
{

}

Arbol::~Arbol()
{
    Vaciar();
}


void ListaPrincipal::Vaciar() {
    if (raiz != nullptr) {
        VaciarRecursivo(raiz);
    }
}

void ListaHijos::Vaciar() {
    if (raiz != nullptr) {
        VaciarRecursivo(raiz);
    }
}

void Arbol::VaciarRecursivo(nodo_t nodo) {
    if (nodo.Siguiente != nullptr) {
        VaciarRecursivo(nodo->hijoMasIzquierdo);
        if (nodo->hermanoDerecho != nullptr) {
            VaciarRecursivo(nodo->hermanodooDerecho);
        }
        delete nodo;
    }
}

bool Arbol::Vacio() {
    if (raiz == nullptr) {
        return true;
    } else {
        return false;
    }
}

void Arbol::PonerRaiz(int e) {
    raiz = new caja{e, nullptr, nullptr, false};
    contadorNodos++;
}


nodo_t Arbol::AgregarHijo(nodo_t nodo, int elemento, int pos) {

}


void Arbol::BorrarHoja(nodo_t n) {

}


void Arbol::ModificarEtiqueta(nodo_t n, int e) {
    n->valor = e;
}


nodo_t Arbol::Raiz() {
    return raiz;
}

//falta
nodo_t Arbol::Hijo(nodo_t n, int i) {
    nodo_t nodoAux = n->hijoMasIzquierdo;
    int contador = 1;
    while (nodoAux != nullptr && contador<i) {
        nodoAux = nodoAux->hermanoDerecho;
        contador ++;
        //cout << "count: " << contador << endl;
    }

    if (nodoAux != nullptr) {
        //cout << "diferente" << endl;
        return nodoAux;
    } else {
        return nullptr;
    }
}

nodo_t Arbol::Padre(nodo_t n) {
    if (n == raiz) {
        return nullptr;
    } else {
        nodo_t nodoAuxiliar = n;

        while (nodoAuxiliar != nullptr) {
            if (nodoAuxiliar->hijoFinal == true) {
                return nodoAuxiliar->hermanoDerecho;
            }
            nodoAuxiliar = nodoAuxiliar->hermanoDerecho;
        }

    }
    //Notar que esto se pone por solicitud del compilador, pero si el árbol esta bien construido, nunca se debería ejecutar está ultima linea.
    return nullptr;
}

int Arbol::Etiqueta(nodo_t n) {
    return n->valor;
}

int Arbol::NumHijos(nodo_t n) {
    int contador = 0;
    nodo_t nodoAux = n->hijoMasIzquierdo;
    bool continuar = true;
    while (nodoAux != nullptr && continuar) {
        if (nodoAux->hijoFinal == true) {
            continuar = false;
        }
        nodoAux = nodoAux->hermanoDerecho;
        contador++;

    }
    return contador;
}

int Arbol::NumNodos() {
    return contadorNodos;
}

nodo_t Arbol::NodoNulo() {
    return nullptr;
}
