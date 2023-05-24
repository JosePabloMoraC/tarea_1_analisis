#include <colaLSE.hh>

#include <iostream>
using namespace std;


/**
 * Efecto: Inicializa la Cola.
 * Requiere: Cola no inicializada o Cola destruida.
 * Modifica: La Cola.
 */
Cola::Cola() : primero(NULL),
               ultimo(NULL)
{
}

/**
 * Efecto: Destruye la Cola.
 * Requiere: Cola inicializada.
 * Modifica: La Cola.
 */
Cola::~Cola()
{
  vaciar();
}

/**
 * Efecto: Vacía la Cola.
 * Requiere: Cola inicializada.
 * Modifica: La Cola.
 */
void Cola::vaciar() {
  while (!vacia()) {
    sacar();
  }
}

/**
 * Efecto: Devuelve verdadero si la Cola está vacía o falso si no.
 * Requiere: Cola inicializada.
 * Modifica: N/A
 */
bool Cola::vacia() {
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
void Cola::agregar(int e) {
  Caja *temp = new Caja();
  temp -> elemento = e;
  temp->next = NULL;
  if (primero == NULL) {
    primero = temp;
    ultimo = temp;
  } else {
    ultimo -> next = temp;
    ultimo = temp;
  }
}

/**
 *  Efecto: Saca un elemento del frente de la cola
 * Requiere: Cola inicializada y no vacía. 
 * Modifica: La Cola.
 */
int Cola::sacar() {
  Caja *temp = primero;
  primero = primero -> next;
  if(primero == NULL) {
    ultimo = NULL;
  }
  return temp->elemento;
  delete(temp);
}

/**
 * Efecto: Devuelve el elemento del frente de la Cola
 * Requiere: Cola inicializada  y no vacía.
 * Modifica: N/A
 */
int Cola::frente() {
  return primero->elemento;
}