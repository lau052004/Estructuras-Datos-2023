#include "funciones.h"
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


// -------------------------------------------------------------------------------------------------------------



int main() {

  KDTree arbol;//Estructura tipo KDTree, almacena los elementos
  vector<string> tokens;
  string input;
  string palabra;
  int i = 0;
  Curiosity robot;
  list<analisis> pruebaA;
  list<movimiento> pruebaM;
  list<elemento> pruebaE;

  /*
    Lectura del archivo
    a|tipo_analisis(fotografiar, composicion o perforar) objeto(roca, crater,
    monticulo o duna) comentario m|tipo_movimiento(avanzar o girar) magnitud
    unidad_medida
  */

  // Consola que permite al usuario ingresar comandos
  do {
    cout << "-$ ";
    // para que se guarde con los espacios
    getline(cin, input);

    if (input != "salir") {
      stringstream ss(input);
      while (ss >> palabra && i < 10) {
        tokens.push_back(palabra);
      }

      if (tokens.size() == 1 && tokens[0] == "ayuda") {
        ayuda(tokens);
      }
      
      // Opciones para cada comando 
      //Valida la cantidad de "palabras" que ingresa el usuario
      if(tokens.size()==1){
        if(tokens[0]=="ubicar_elementos"){
          if(ubicar_elementos(robot,arbol)){
            cout<<"Los elementos han sido procesados correctamente"<<endl;
          }         
        }
      }else if (tokens.size() == 2) {
        if (tokens[0] == "cargar_comandos") {
          cargar_comandos(robot,tokens[1]);
          } else if (tokens[0] == "cargar_elementos") {
          cargar_elementos(robot,tokens[1]);
          }
        }else if(tokens.size()==3){
          if (tokens[0] == "guardar"){
            if(guardar(robot, tokens[1], tokens[2])){
              cout<<"El comando de movimiento ha sido agregado correctamente"<<endl;
            }else 
              cout<<"La información de movimiento no corresponde a los datos esperados(tipo,nombre)"<<endl;
        }else if (tokens[0] == "simular_comandos"){
            simularMov(tokens[1], tokens[2], robot);
        }
        }else if(tokens.size()==4){
          if (tokens[0] == "agregar_movimiento"){
            if(agregar_movimiento(robot, tokens[1], tokens[2], tokens[3])){
              cout<<"El comando de movimiento ha sido agregado correctamente"<<endl;
          }else cout<<"La información de movimiento no corresponde a los datos esperados(tipo,magnitud,unidad)"<<endl;
        }
        if (tokens[0] == "agregar_analisis"){
          if(agregar_analisis(robot, tokens[1], tokens[2], tokens[3])){
            cout<<"El comando de análisis ha sido agregado correctamente";
          }else cout<<"La información de análisis no corresponde a los datos esperados(tipo,objeto,comentario)"<<endl;
        }
        
      }else if(tokens.size()==5){
        if(tokens[0]=="en_cuadrante"){
          en_cuadrante(robot,arbol,tokens[1],tokens[2],tokens[3],tokens[4]);
        }
      }else if(tokens.size()==6){
         if (tokens[0] == "agregar_elemento"){
          if(agregar_elemento(robot,tokens[1],tokens[2],tokens[3],tokens[4],tokens[5])){
            cout<<"El elemento ha sido agregado correctamente" << endl;
          }
          else cout<< "La información de elemento no corresponde a los datos esperados(tipo,tamaño,unidad,x,y)" << endl;
        }
      }
    }
    tokens.clear();
  } while (input != "salir");
 
  return 0;
}


