#include <colaLSE.hh>

#include <iostream>
using namespace std;

Cola::Cola() : primero(NULL),
               ultimo(NULL)
{
}

void Cola::iniciar() {
  Cola();
}

Cola::~Cola()
{
  vaciar();
}

void Cola::vaciar() {
  while (!vacia()) {
    sacar();
  }
}

bool Cola::vacia() {
  if (primero == NULL && ultimo == NULL){
    return true;
  } else {
    return false;
  }
}

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


//Requiere que la cola tenga elementos
int Cola::sacar() {
  Caja *temp = primero;
  primero = primero -> next;
  if(primero == NULL) {
    ultimo = NULL;
  }
  return temp->elemento;
  delete(temp);
}

int Cola::frente() {
  return primero->elemento;
}