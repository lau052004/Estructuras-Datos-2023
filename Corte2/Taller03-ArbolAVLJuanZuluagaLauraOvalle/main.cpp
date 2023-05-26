#include <iostream>
#include "Arbol.h"
#include <math.h>
#include <list>
#include <fstream>
#include <vector>


using namespace std;

void procesarLineaAVL(string linea, Arbol &arbol, int &cant)
{
  // Separamos la l�nea en dos partes: el prefijo y el valor
  char prefijo = linea[0];
  string valor = linea.substr(2); // La posici�n 0 contiene el prefijo, y la 1 contiene un espacio en blanco

  // Enviamos la l�nea a la funci�n correspondiente dependiendo del prefijo
  if (prefijo == 'A')
  {
    arbol.setRaiz(arbol.insertar(arbol.getRaiz(), stoi(valor)));
    cant++;
    //avl.display(root, 1);
  }
  else if (prefijo == 'E')
  {
    if((arbol.buscar(arbol.getRaiz(), stoi(valor), 0))!=-1){
      cant--;
    }
    arbol.setRaiz(arbol.eliminar(arbol.getRaiz(), stoi(valor)));
    //avl.display(root, 1);
  }
  else
  {
    //para hacer cout de un error
    cerr << "Error: prefijo desconocido en la linea " << linea << endl;
  }
}

int cargarInformacion(string nombreArchivo, Arbol &arbol)
{
  int cant=0;
  string linea;
  ifstream archivoAVL(nombreArchivo);
  if (archivoAVL.is_open())
  {
    cout << "Archivo abierto correctamente"<<endl;
    while (getline(archivoAVL, linea))
    {
      procesarLineaAVL(linea,arbol,cant);
    }
    archivoAVL.close();
  }
  else
  {
    //para hacer cout de un error
    cerr << "No se pudo abrir el archivo AVL " << nombreArchivo << endl;
  }
  return cant;
}


int main() {
  int canti;
  string nombreArchivo = "entrada.txt";
  vector <int> vect;

  cout << "Creando Arbol AVL..." << endl;
  Arbol arbol;

  cout << "Cargando la información del archivo en el arbol..." << endl;
  canti = cargarInformacion(nombreArchivo,arbol);
  cout << "Fueron cargados " << canti << " elementos en el arbol " << endl;
  cout << "Calculando la mediana del arbol..." << endl;
  arbol.mediana(canti,arbol.getRaiz());
  //arbol.inorder2(arbol.getRaiz(), vect);
}