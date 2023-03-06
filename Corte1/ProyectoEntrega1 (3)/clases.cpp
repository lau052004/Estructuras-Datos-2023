#include "clases.h"
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


  void elemento::fijarTipoElemento(string tipo_elemento) {
    this->tipo_elemento = tipo_elemento;
  }
  void elemento::fijarTamano(int tamano) { this->tamano = tamano; }
  void elemento::fijarUnidadMedida(string unidad_medida) {
    this->unidad_medida = unidad_medida;
  }
  void elemento::fijarCoordenada_x(int coordenada_x) {
    this->coordenada_x = coordenada_x;
  }
  void elemento::fijarCoordenada_y(int coordenada_y) {
    this->coordenada_y = coordenada_y;
  }

  // Getters
  string elemento::obtenerTipoElemento() { return tipo_elemento; }
  int elemento::obtenerTamano() { return tamano; }
  string elemento::obtenerUnidadmedida() { return unidad_medida; }
  int elemento::obtenerCoordenada_x() { return coordenada_x; }
  int elemento::obtenerCoordenada_y() { return coordenada_y; }



  void movimiento::fijarTipo_movimiento(string tipo_movimiento) {
    this->tipo_movimiento = tipo_movimiento;
  }
  void  movimiento::fijarMagnitud(float magnitud) { this->magnitud = magnitud; }
  void  movimiento::fijarUnidadMedida(string unidad_medida) {
    this->unidad_medida = unidad_medida;
  }

  // Getters
  string  movimiento::obtenerTipo_movimiento() { return tipo_movimiento; }
  float  movimiento::obtenerMagnitud() { return magnitud; }
  string  movimiento::obtenerUnidadMedida() { return unidad_medida; }



  void analisis::fijarTipo_analisis(string tipo_analisis) {
    this->tipo_analisis = tipo_analisis;
  }
  void analisis::fijarObjeto(string objeto) { this->objeto = objeto; }
  void analisis::fijarComentario(string comentario) { this->comentario = comentario; }

  // Getters
  string analisis::obtenerTipo_analisis() { return tipo_analisis; }
  string analisis::obtenerObjeto() { return objeto; }
  string analisis::obtenerComentario() { return comentario; }



  // Setters
  void Curiosity::fijarElementos(const list<elemento> &newElementos) {
    elementos = newElementos;
  }
  void Curiosity::fijarListaMovimientos(const list<movimiento> &newListaMovimientos) {
    listaMovimientos = newListaMovimientos;
  }
  void Curiosity::fijarListaAnalisis(const list<analisis> &newListaAnalisis) {
    listaAnalisis = newListaAnalisis;
  }

  // Getters
  list<elemento> Curiosity::obtenerElementos() { return elementos; }
  list<movimiento> Curiosity::obtenerListaMovimientos() const { return listaMovimientos; }
  list<analisis> Curiosity::obtenerListaAnalisis() const { return listaAnalisis; }
  //Métodos
  void Curiosity::agregarElemento(elemento auxEle){
    elementos.push_back(auxEle);
  }
void Curiosity::agregarMovimiento(movimiento auxMov){
    listaMovimientos.push_back(auxMov);
  }
void Curiosity::agregarAnalisis(analisis auxAna){
    listaAnalisis.push_back(auxAna);
  }

  list<elemento>::iterator Curiosity::getElementoBegin() {
    return elementos.begin();
  }
  list<elemento>::iterator Curiosity::getElementoEnd() {
    return elementos.end();
  }

  list<analisis>::iterator Curiosity::getAnalisisBegin() {
    return listaAnalisis.begin();
  }
  list<analisis>::iterator Curiosity::getAnalisisEnd() {
    return listaAnalisis.end();
  }

  list<movimiento>::iterator Curiosity::getMovimientoBegin() {
    return listaMovimientos.begin();
  }
  list<movimiento>::iterator Curiosity::getMovimientoEnd() {
    return listaMovimientos.end();
  }

