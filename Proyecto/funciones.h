#ifndef funciones_h
#define funciones_h
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
// prototipos de la funcion
bool esNumero(string num);
void ayuda(vector<string> &tokens);
bool cargar_comandos(Curiosity &robot, string nomarchivo) ;
bool cargar_elementos(Curiosity &robot, string nomarchivo);
bool agregar_movimiento(Curiosity &robot, string tipo_mov, string magnitud,string unidadm);
bool agregar_analisis(Curiosity &robot, string tipoa, string objeto, string comentario);
// 
bool agregar_elemento(Curiosity &robot, string tipoe, string tamano, string unidadm, string x, string y);
void imprimir(Curiosity &robot);
bool guardar(Curiosity &robot, string tipoA, string nombre);
bool simularMov(string x, string y, Curiosity &robot);
bool ubicar_elementos(Curiosity &robot,KDTree &arbol);
bool en_cuadrante(Curiosity &robot, KDTree &arbol, string x1, string x2, string y1, string y2);
#endif