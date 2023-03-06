#ifndef clases_h
#define clases_h
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

// DECLARACIÓN DE CLASES
// --------------------------------------------------------------------------------------

// Los enteros pueden cambiarse por float
// elementos = obstaculos

class elemento {
private:
  string tipo_elemento;
  int tamano;
  string unidad_medida;
  int coordenada_x;
  int coordenada_y;

public:
  void fijarTipoElemento(string tipo_elemento);
  void fijarTamano(int tamano);
  void fijarUnidadMedida(string unidad_medida);
  void fijarCoordenada_x(int coordenada_x);
  void fijarCoordenada_y(int coordenada_y);

  // Getters
  string obtenerTipoElemento();
  int obtenerTamano();
  string obtenerUnidadmedida();
  int obtenerCoordenada_x();
  int obtenerCoordenada_y();
};

class movimiento {
private:
  string tipo_movimiento;
  float magnitud;
  string unidad_medida;

public:
  void fijarTipo_movimiento(string tipo_movimiento);
  void fijarMagnitud(float magnitud);
  void fijarUnidadMedida(string unidad_medida);

  // Getters
  string obtenerTipo_movimiento();
  float obtenerMagnitud();
  string obtenerUnidadMedida();
};

class analisis {
private:
  // instruccion
  string tipo_analisis;
  string objeto;
  string comentario;

public:
  void fijarTipo_analisis(string tipo_analisis);
  void fijarObjeto(string objeto);
  void fijarComentario(string comentario);

  // Getters
  string obtenerTipo_analisis();
  string obtenerObjeto();
  string obtenerComentario();
};

class Curiosity {
private:
  list<elemento> elementos;
  list<movimiento> listaMovimientos;
  list<analisis> listaAnalisis;

public:
  // Setters
  void fijarElementos(const list<elemento> &newElementos);
  void fijarListaMovimientos(const list<movimiento> &newListaMovimientos);
  void fijarListaAnalisis(const list<analisis> &newListaAnalisis);

  // Getters
  list<elemento> obtenerElementos();
  list<movimiento> obtenerListaMovimientos() const ;
  list<analisis> obtenerListaAnalisis() const ;
  //Métodos
  void agregarElemento(elemento auxEle);
void agregarMovimiento(movimiento auxMov);
void agregarAnalisis(analisis auxAna);

  list<elemento>::iterator getElementoBegin();
  list<elemento>::iterator getElementoEnd();
  list<analisis>::iterator getAnalisisBegin();
  list<analisis>::iterator getAnalisisEnd();
  list<movimiento>::iterator getMovimientoBegin();
  list<movimiento>::iterator getMovimientoEnd();

};
#endif