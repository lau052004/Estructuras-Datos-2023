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
//Clase Rectangulo, utilizada para representar cada elemento y cuadrante
class Rectangulo{
    private:
    int xmin, xmax, ymin, ymax;
    string tipo;
    public:
    Rectangulo(int x1, int x2, int y1, int y2, string t);//Constructor
    //Setters
    void fijarXmin(int x1);
    void fijarXmax(int x2);
    void fijarYmin(int y1);
    void fijarYmax(int y2);
    void fijarTipo(string t);
    //Getters
    int obtenerXmin();
    int obtenerXmax();
    int obtenerYmin();
    int obtenerYmax();
    string obtenerTipo();
    bool intersecta(const Rectangulo& o);//Función que determina si dos rectángulos se intersectan
    bool contiene(const Rectangulo& o);//Función que determina si un rectángulo contiene a otro
};

//Clase nodo, utilizada por el KDTree
class Nodo{
    private:
    Rectangulo *obstaculo;//Obstaculo que contiene el nodo(Roca, duna, etc)
    Nodo *izq, *der;
    public:
    Nodo(Rectangulo *o);//Constructor
    ~Nodo();//Destructor
    //Setters
    void fijarObstaculo(Rectangulo *o);
    void fijarIzq(Nodo *nodo);
    void fijarDer(Nodo *nodo);
    //Getters
    Rectangulo *obtenerObstaculo();
    Nodo *obtenerIzq();
    Nodo *obtenerDer();
    Nodo *&obtenerIzqRef();//Referencia al puntero izquierdo, utilizada para modificar el puntero en la función de insertar del KDTree
    Nodo *&obtenerDerRef();

};

//Clase KDTree
class KDTree{
    private:
    Nodo*raiz;
    bool insertar(Rectangulo *o, Nodo *&nodo, bool eje);//Función recursiva que inserta un rectángulo en el KDTree
    bool buscar(Nodo *nodo, Rectangulo *rect, bool &hayUno);//Función recursiva que busca un rectángulo dentro de otro rectangulo
    public:
    KDTree();//Constructor
    ~KDTree();//Destructor
    void fijarRaiz(Nodo *nodo);//Setter
    Nodo *obtenerRaiz();//Getter
    bool insertar(Rectangulo *o);//Función pública que llama a la función recursiva de insertar
    bool buscar(Rectangulo *rect);//Función pública que llama a la función recursiva de buscar
    bool vacio();//Función que determina si el KDTree está vacío
};

#endif