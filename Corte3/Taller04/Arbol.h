#ifndef __ARBOL__H__
#define __ARBOL__H__

#include "Nodo.h"
#include <vector>

class Arbol {
protected:
  Nodo *raiz;

public:
  Arbol();
  Arbol(int val);
  ~Arbol();
  int datoRaiz();
  Nodo *obtenerRaiz();
  void fijarRaiz(Nodo *n_raiz);
  bool esVacio();
  bool insertar(int val);
  bool insertarNodo(int nval, Nodo *nodo);
  void preOrden();
  void preOrden(Nodo *nodo);
  void inOrden();
  void inOrden(Nodo *nodo);
  void posOrden();
  void posOrden(Nodo *nodo);
  void armarMatriz(std::vector<std::vector<int>> &imagen, int tamano);
  void armarMatriz(Nodo *nodo, std::vector<std::vector<int>> &imagen,
                   int tamano, int inicioI, int inicioJ);
};

#endif