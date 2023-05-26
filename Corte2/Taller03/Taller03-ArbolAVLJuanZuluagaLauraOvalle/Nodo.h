#ifndef Nodo_H
#define Nodo_H

class Nodo {
private:
  // Se definen los atributos del nodo, que son el valor que va a contener, su
  // altura y los apuntadores a cada uno de sus posibles hijos, el de la derecha
  // y el de la izquierda
  int valor;
  int altura;
  Nodo *izquierda;
  Nodo *derecha;

public:
  // Getters & Setters
  int getValor();
  void setValor(int valor);
  Nodo *getIzquierda();
  void setIzquierda(Nodo *izquierda);
  Nodo *getDerecha();
  void setDerecha(Nodo *derecha);
  int getAltura();
  void setAltura(int altura);
};

//#include "Nodo.cpp"
#endif