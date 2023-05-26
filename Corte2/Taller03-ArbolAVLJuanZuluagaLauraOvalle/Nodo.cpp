#include "Nodo.h"

int Nodo::getValor() {
    return valor;
  }

void Nodo::setValor(int valor) {
    this->valor = valor;
  }

Nodo* Nodo::getIzquierda() {
    return izquierda;
  }

void Nodo::setIzquierda(Nodo* izquierda) {
    this->izquierda = izquierda;
  }

Nodo* Nodo::getDerecha() {
    return derecha;
  }

void Nodo::setDerecha(Nodo* derecha) {
    this->derecha = derecha;
  }

int Nodo::getAltura() {
    return altura;
  }

void Nodo::setAltura(int altura) {
    this->altura = altura;
  }
