#ifndef COLA_HH
#define COLA_HH

#include <iostream>
using namespace std;

template <typename T>
struct  Caja {
  T elemento;
  Caja<T>* next;
};

template <typename T>
class Cola {
  private:
    Caja<T> *primero;
    Caja<T> *ultimo;
    int largo;
  public:
    Cola();
    void vaciar();
    bool vacia();
    void agregar(T e);
    T sacar();
    T frente();
    int getLargo();
    ~Cola();
};

//Al momento de compilar, los templates suelen dar problemas si la declaración y definición se encuentran en archivos separados
/**
 * Efecto: Inicializa la Cola.
 * Requiere: Cola no inicializada o Cola destruida.
 * Modifica: La Cola.
 */
template <typename T>
Cola<T>::Cola() : primero(NULL),
               ultimo(NULL), largo(0)
{
}

/**
 * Efecto: Destruye la Cola.
 * Requiere: Cola inicializada.
 * Modifica: La Cola.
 */
template <typename T>
Cola<T>::~Cola()
{
  vaciar();
}

/**
 * Efecto: Vacía la Cola.
 * Requiere: Cola inicializada.
 * Modifica: La Cola.
 */
template <typename T>
void Cola<T>::vaciar() {
  while (!vacia()) {
    largo--;
    sacar(); //Liberamos la memoria a la que apunta el puntero
  }
}

/**
 * Efecto: Devuelve verdadero si la Cola está vacía o falso si no.
 * Requiere: Cola inicializada.
 * Modifica: N/A
 */
template <typename T>
bool Cola<T>::vacia() {
  if (primero == NULL && ultimo == NULL){
    return true;
  } else {
    return false;
  }
}

/**
 * Efecto: Agrega un elemento e de tipo entero en la parte posterior de la Cola. 
 * Requiere: Cola inicializada.
 * Modifica: La Cola.
 */
template <typename T>
void Cola<T>::agregar(T e) {
  Caja<T> *temp = new Caja<T>();
  temp -> elemento = e;
  temp->next = NULL;
  if (primero == NULL) {
    primero = temp;
    ultimo = temp;
  } else {
    ultimo -> next = temp;
    ultimo = temp;
  }
  largo++;
}

/**
 * Efecto: Saca un elemento del frente de la cola
 * Requiere: Cola inicializada y no vacía. 
 * Modifica: La Cola.
 */
template <typename T>
T Cola<T>::sacar() {
  Caja<T> *temp = primero;
  T resultado = temp->elemento;
  primero = primero->next;
  if(primero == NULL) {
    ultimo = NULL;
  }else{
    largo--;
  }
  delete(temp);
  return resultado;
}

/**
 * Efecto: Devuelve el elemento del frente de la Cola
 * Requiere: Cola inicializada  y no vacía.
 * Modifica: N/A
 */
template <typename T>
T Cola<T>::frente() {
  return primero->elemento;
}

template <typename T>
int Cola<T>::getLargo(){
  return largo;
}


#endif