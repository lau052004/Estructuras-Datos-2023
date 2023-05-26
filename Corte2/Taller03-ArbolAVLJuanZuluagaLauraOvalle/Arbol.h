#ifndef Arbol_H
#define Arbol_H
#include "Nodo.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

class Arbol {
private:
  Nodo *raiz;

public:
  Arbol() { 
    raiz = nullptr; 
  }

  int altura(Nodo *temp);
  int diferencia(Nodo *temp);
  Nodo *RR_rotacion(Nodo *padre);
  Nodo *LL_rotacion(Nodo *padre);
  Nodo *RL_rotacion(Nodo *padre);
  Nodo *LR_rotacion(Nodo *padre);
  Nodo *balance(Nodo *temp);
  Nodo *insertar(Nodo *raiz, int value);
  void inorder(Nodo *raiz, std::list<int> Lista);
  void inorder2(Nodo *raiz, std::vector<int> &vect);
  Nodo *Min(Nodo *nodo);
  Nodo *Max(Nodo *nodo);
  Nodo *eliminar(Nodo *nodo, int value);
  int buscar(Nodo *raiz, int value, int nivel);
  void mediana(int canti, Nodo *raiz);

  // Getters & Setters
  Nodo *getRaiz();
  void setRaiz(Nodo *raiz);
};

//#include "Arbol.cpp"
#endif
