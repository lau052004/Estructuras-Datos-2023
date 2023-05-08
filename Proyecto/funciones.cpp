#include "funciones.h"
#include "clases.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// funcion ayuda
void ayuda(vector<string> &tokens) {
  string input;
  string palabra;
  int i = 0;
  vector<string> ayudaComando;

  cout << "\nLista de comandos: " << endl;
  cout << "-$ cargar_comandos \n-$ cargar_elementos\n-$ agregar_movimiento "
          "\n-$ agregar_analisis  \n-$ agregar_elemento\n-$ guardar\n-$ "
          "simular_comandos \n-$ salir";
  cout << "\nPara solicitar ayuda de un comando en especifico escriba $ayuda "
          "nombre_comando"
       << endl;
  cout << "- $ ";
  getline(cin, input);

  stringstream ss(input);
  while (ss >> palabra && i < 10) {
    ayudaComando.push_back(palabra);
  }

  // Condición para saber si el usuario quiere + info de un comando
  if (ayudaComando.size() == 2 && ayudaComando[0] == "ayuda") {
    if (ayudaComando[1] == "cargar_comandos") {
      cout << "\nCarga en memoria los comandos de desplazamiento contenidos en "
              "el archivo identificado por nombre_archivo. \nFormato: "
              "$cargar_comandos nombre_archivo"
           << endl;
    } else if (ayudaComando[1] == "cargar_elementos") {
      cout << "\nCarga en memoria los datos de puntos de interés o elementos "
              "contenidos en el archivo identificado por nombre_archivo. "
              "\nFormato: $cargar_elementos nombre_archivo"
           << endl;
    } else if (ayudaComando[1] == "agregar_movimiento") {
      cout << "\nAgrega el comando de movimiento descrito a la lista de "
              "comandos del robot “Curiosity”. El movimiento puede ser de dos "
              "tipos: avanzar o girar. La magnitud corresponde al valor del "
              "movimiento; si es avanzar, el número de unidades que se espera "
              "avanzar, si es girar la cantidad de grados que debe girar. La "
              "unidad de medida corresponde a la convención con la que se mide "
              "la magnitud del movimiento (centimetros, metros, grados, ...) "
              "\n Formato: $agregar_movimiento tipo_movimiento(string) "
              "magnitud (float) unidad_medida (string) "
           << endl;
    } else if (ayudaComando[1] == "agregar_analisis") {
      cout << "\nAgrega el comando de análisis descrito a la lista de comandos "
              "del robot “Curiosity”. El análisis puede ser de tres tipos: "
              "fotografiar, composicion o perforar. El objeto es el nombre del "
              "elemento que se quiere analizar (roca, arena, monticulo, ...). "
              "El comentario es opcional y permite agregar más información "
              "sobre el elemento o el análisis, este comentario estará "
              "encerrado entre comillas simples (ejemplo: ’roca_cuadrante_32’) "
              "\n Formato: $agregar_analisis tipo_analisis(string) "
              "objeto(string) comentario(string)"
           << endl;
    } else if (ayudaComando[1] == "agregar_elemento") {
      cout << "\nAgrega el componente o elemento descrito a la lista de puntos "
              "de interés del robot “Cuoriosity”. El tipo de componente puede "
              "ser uno entre roca, crater, monticulo o duna. El tamaño es un "
              "valor real que da cuenta de qué tan grande es el elemento; y la "
              "unidad de medida complementa este valor con la convención que "
              "se usó para su medición (centimetros, metros, ...). Finalmente, "
              "las coordenadas x y y corresponden a números reales que "
              "permiten conocer la ubicación del elemento en el sistema de "
              "coordenadas del suelo marciano utilizado por el vehículo.  "
              "Formato: $agregar_elemento tipo_comp(string) tamaño(int) "
              "unidad_med(string) coordX(int) coordY(int)"
           << endl;
    } else if (ayudaComando[1] == "guardar") {
      cout << "\nGuarda en el archivo nombre_archivo la información solicitada "
              "de acuerdo al tipo de archivo: comandos almacena en el archivo "
              "la información de comandos de movimiento y de análisis quedebe "
              "ejecutar el robot, elementos almacena en el archivo la "
              "información de los componentes o puntos de interés conocidos en "
              "el suelo marciano. \nFormato: $guardar tipo_archivo(string) "
              "nombre_archivo(string)"
           << endl;
    } else if (ayudaComando[1] == "simular_comandos") {
      cout
          << "\nPermite simular el resultado de los comandos de movimiento que "
             "se enviarán al robot “Curiosity” desde la Tierra, facilitando "
             "asi la validación de la nueva posición en la que podría "
             "ubicarse. \nFormato: $simular_comandos coordX(int) coordY(int) "
          << endl;
    }
  }

  tokens.clear();
  tokens = ayudaComando;
}

// funcion para cargar comandos
bool cargar_comandos(Curiosity &robot, string nomarchivo) {
  movimiento auxMovimientos;
  analisis auxAnalisis;
  ifstream archivoComandos;
  archivoComandos.open(nomarchivo, ios::in);
  string line;
  string word;
  int i = 0;
  int canti = 0;
  char delimiter = '|';

  if (archivoComandos.fail()) {
    cerr << nomarchivo << "no se encuentra o no puede leerse\n";
    return false;
  }
  if (archivoComandos.eof()) {
    cerr << nomarchivo << "no contiene elementos\n";
    return false;
  }
  // Lectura del archivo para cargar comandos
  cout << "Leyendo archivo '" << nomarchivo << "':" << endl;

  while (getline(archivoComandos, line)) {
    canti++;
    stringstream str(line);
    getline(str, word, delimiter);

    if (word == "m") {
      getline(str, word, delimiter);
      auxMovimientos.fijarTipo_movimiento(word);

      getline(str, word, delimiter);
      auxMovimientos.fijarMagnitud(stof(word));

      getline(str, word, delimiter);
      auxMovimientos.fijarUnidadMedida(word);
      if (word != "metros" && word != "grados") {
        archivoComandos.close();
        cerr << nomarchivo << "no puede leerse\n";
        return false;
      }

      robot.agregarMovimiento(auxMovimientos);
      // auxListaMovimientos.push_back(auxMovimientos);

    } else if (word == "a") {
      getline(str, word, delimiter);
      auxAnalisis.fijarTipo_analisis(word);

      getline(str, word, delimiter);
      auxAnalisis.fijarObjeto(word);

      getline(str, word, delimiter);
      auxAnalisis.fijarComentario(word);

      robot.agregarAnalisis(auxAnalisis);
      // auxListaAnalisis.push_back(auxAnalisis);
    }
  }

  // Guardar la info en el robot
  // robot.fijarListaMovimientos(auxListaMovimientos);
  // robot.fijarListaAnalisis(auxListaAnalisis);

  cout << canti << " comandos cargados correctamente desde:" << nomarchivo
       << endl;
  archivoComandos.close();
  return true;
}

// funcion para cargar elementos
bool cargar_elementos(Curiosity &robot, string nomarchivo) {
  elemento auxElemento;
  ifstream archivoElementos;
  archivoElementos.open(nomarchivo, ios::in);
  string line;
  string word;
  int canti = 0;
  char delimiter = '|';

  if (archivoElementos.fail()) {
    cerr << nomarchivo << " no se encuentra o no puede leerse\n";
    return false;
  }
  if (archivoElementos.eof()) {
    cerr << nomarchivo << " no contiene elementos\n";
    return false;
  }

  // Lectura del archivo para cargar comandos
  cout << "Leyendo archivo '" << nomarchivo << "':" << endl;

  while (getline(archivoElementos, line)) {
    canti++;
    stringstream str(line);
    getline(str, word, delimiter);
    auxElemento.fijarTipoElemento(word);

    getline(str, word, delimiter);
    auxElemento.fijarTamano(stoi(word));

    getline(str, word, delimiter);
    if (word != "metros" && word != "grados") {
      archivoElementos.close();
      cerr << nomarchivo << "no puede leerse\n";
      return false;
    }
    auxElemento.fijarUnidadMedida(word);

    getline(str, word, delimiter);
    auxElemento.fijarCoordenada_x(stoi(word));

    getline(str, word, delimiter);
    auxElemento.fijarCoordenada_y(stoi(word));

    robot.agregarElemento(auxElemento);
  }
  cout << canti << " elementos cargados correctamente desde: " << nomarchivo
       << endl;
  archivoElementos.close();
  return true;
}

// funcion para agregar movimientos
bool agregar_movimiento(Curiosity &robot, string tipo_mov, string magnitud,
                        string unidadm) {
  movimiento auxMov;
  if (tipo_mov != "avanzar" && tipo_mov != "girar") {
    return false;
  }
  if (tipo_mov == "avanzar" && unidadm == "grados") {
    return false;
  }
  if (tipo_mov == "girar" && unidadm == "metros") {
    return false;
  }
  if (unidadm != "metros" && unidadm != "grados") {
    return false;
  }
  if (!esNumero(magnitud)) {
    return false;
  }

  auxMov.fijarTipo_movimiento(tipo_mov);
  auxMov.fijarMagnitud(stof(magnitud));
  auxMov.fijarUnidadMedida(unidadm);
  robot.agregarMovimiento(auxMov);
  return true;
}

bool agregar_analisis(Curiosity &robot, string tipoa, string objeto,
                      string comentario) {
  analisis auxAn;
  if (tipoa != "fotografiar" && tipoa != "composicion" && tipoa != "perforar") {
    return false;
  }
  auxAn.fijarTipo_analisis(tipoa);
  auxAn.fijarObjeto(objeto);
  auxAn.fijarComentario(comentario);
  robot.agregarAnalisis(auxAn);
  return true;
}

// funcion para agregar elementos
bool agregar_elemento(Curiosity &robot, string tipoe, string tamano,
                      string unidadm, string x, string y) {
  elemento auxE;
  if (tipoe != "roca" && tipoe != "crater" && tipoe != "monticulo" &&
      tipoe != "duna") {
    return false;
  }
  if (!esNumero(tamano)) {
    return false;
  }
  if(stoi(tamano) <= 0){
    return false;
  }
  if (!esNumero(x) || !esNumero(y)) {
    return false;
  }
  if (unidadm != "metros") {
    return false;
  }
  auxE.fijarTipoElemento(tipoe);
  auxE.fijarTamano(stoi(tamano));
  auxE.fijarUnidadMedida(unidadm);
  auxE.fijarCoordenada_x(stoi(x));
  auxE.fijarCoordenada_y(stoi(y));
  robot.agregarElemento(auxE);
  return true;
}

// funcion es nu
bool esNumero(string num) {
  char *endptr;
  strtod(num.c_str(), &endptr);

  if (*endptr == '\0') {
    return true;
  } else {
    return false;
  }
}

// funcion para imprimir
void imprimir(Curiosity &robot) {
  list<analisis> auxAn;
  // PRUEBA PARA REVISAR QUE FUNCIONA BIEN
  cout << "Lista analisis: " << endl;

  for (auto it = robot.getAnalisisBegin(); it != robot.getAnalisisEnd(); it++) {
    cout << it->obtenerTipo_analisis() << endl;
    cout << it->obtenerObjeto() << endl;
    cout << it->obtenerComentario() << endl;
  }

  cout << "Lista movimientos: " << endl;

  for (auto it = robot.getMovimientoBegin(); it != robot.getMovimientoEnd();
       it++) {
    cout << it->obtenerTipo_movimiento() << endl;
    cout << it->obtenerMagnitud() << endl;
    cout << it->obtenerUnidadMedida() << endl;
  }
  cout << "Lista de elementos: " << endl;
  for (auto it = robot.getElementoBegin(); it != robot.getElementoEnd(); it++) {
    cout << it->obtenerTipoElemento() << endl;
    cout << it->obtenerTamano() << endl;
    cout << it->obtenerUnidadmedida() << endl;
    cout << it->obtenerCoordenada_x() << endl;
    cout << it->obtenerCoordenada_y() << endl;
  }
}

// funcion para guardar
bool guardar(Curiosity &robot, string tipoA, string nombre) {
  ofstream archivo;
  archivo.open(nombre, ios::out);
  if (!archivo.is_open()) {
    cout << "Problemas en archivo" << nombre << '\n';
  } else {
    // verifica que haya informacion en las listas
    if (tipoA == "comandos" && (robot.obtenerListaMovimientos().size() == 0 ||
                                robot.obtenerListaAnalisis().size() == 0)) {
      cout << "La información requerida no está almacenada en memoria.\n";
    } else if (tipoA == "elementos" && robot.obtenerElementos().size() == 0) {
      cout << "La información requerida no está almacenada en memoria.\n";
    } else if (tipoA == "comandos") {
      // guarda los comandos de movimiento si sí hay información en las listas
      archivo << "Comandos de movimiento: \n";
      for (auto it = robot.getMovimientoBegin(); it != robot.getMovimientoEnd();
           it++) {
        archivo << it->obtenerTipo_movimiento() << endl;
        archivo << it->obtenerMagnitud() << endl;
        archivo << it->obtenerUnidadMedida() << endl;
      }
      // guarda en el archivo los comandos de analisis
      archivo << "\nComandos de analisis: \n";
      for (auto it = robot.getAnalisisBegin(); it != robot.getAnalisisEnd();
           it++) {
        archivo << it->obtenerTipo_analisis() << endl;
        archivo << it->obtenerObjeto() << endl;
        archivo << it->obtenerComentario() << endl;
      }
      cout << "Escritura exitosa" << endl;
    } else if (tipoA == "elementos") {
      // guarda los elementos en el archivo si hay información
      archivo << "Puntos de interes conocidos: \n";
      for (auto it = robot.getElementoBegin(); it != robot.getElementoEnd();
           it++) {
        archivo << it->obtenerTipoElemento() << endl;
        archivo << it->obtenerTamano() << endl;
        archivo << it->obtenerUnidadmedida() << endl;
        archivo << it->obtenerCoordenada_x() << endl;
        archivo << it->obtenerCoordenada_y() << endl;
      }
      cout << "Escritura exitosa" << endl;
    } else {
      // verifica que el tipo de comando esté entre las opciones
      cout << "El tipo de archivo no corresponde con las opciones (comandos o "
              "elementos).\n";
    }
  }
  archivo.close();
  return true;
}

// funcion para simular movimientos
bool simularMov(string x, string y, Curiosity &robot) {
  if (robot.obtenerListaMovimientos().empty()) {
    cout << "La información requerida no está almacenada en memoria" << endl;
    return false;
  }
  if (!esNumero(x) || !esNumero(y)) {
    cout << "Las coordenadas ingresadas son inválidas" << endl;
    return false;
  }
  double coorx;
  double coory;
  double theta = 90.0; // Por defecto está mirando al frente
  double rad;
  double dist; // Distancia que se mueve el robot
  coorx = stod(x);
  coory = stod(y);
  // Calcular el primer angulo en radianes
  rad = atan2(sin(theta *  3.1415926535897932385 / 180.0), cos(theta *  3.1415926535897932385 / 180.0));

  for (auto it = robot.getMovimientoBegin(); it != robot.getMovimientoEnd();
       it++) {
    if (it->obtenerTipo_movimiento() == "avanzar") {
      dist = it->obtenerMagnitud();
      // Calcular la nueva posición
      double dx = dist * cos(rad);
      double dy = dist * sin(rad);

      // Actualizar la posición
      coorx += dx;
      coory += dy;

    } else if (it->obtenerTipo_movimiento() == "girar") {
      // Asignarle el ángulo según los grados en los que está actualmente y
      // restando los 90° del inicio
      theta += it->obtenerMagnitud() - (90.0);
      // Asegurarse que el ángulo esté entre 0 y 360
      theta = fmod(theta, 360.0);
      // Calcular el ángulo en radianes
      rad = atan2(sin(theta *  3.1415926535897932385 / 180.0), cos(theta *  3.1415926535897932385 / 180.0));
    }
  }

  cout << "La simulación de comandos a partir de la posición (" << x << "," << y
       << ") deja al robot en la nueva Posición "
       << "(" << coorx << "," << coory << ")" << endl;
  return true;
}
//Funcion para ubicar los elementos que tiene almacenados en memoria el robot
bool ubicar_elementos(Curiosity &robot,KDTree &arbol) {
  int xmin, xmax, ymin, ymax;//Información del elemento
  string tipo;
  list<elemento> fallidos;//Lista de elementos que no se pudieron procesar
  if (robot.obtenerElementos().empty()) {
    cout << "La información requerida no está almacenada en memoria\n";
    return false;
  }
  for (auto it = robot.getElementoBegin(); it != robot.getElementoEnd(); it++) {//Recorre la lista de elementos del curiosity
    xmin=it->obtenerCoordenada_x();
    xmax=it->obtenerCoordenada_x()+it->obtenerTamano();
     ymin=it->obtenerCoordenada_y();//Toma la coordenada x y y dada por el usuario como la esquina inferior izquierda del elemento
    ymax=it->obtenerCoordenada_y()+it->obtenerTamano();
    tipo=it->obtenerTipoElemento();
    if(!arbol.insertar(new Rectangulo(xmin, xmax, ymin, ymax, tipo))){//Si no se pudo insertar el elemento en el arbol, se agrega a la lista de fallidos
      fallidos.push_back(*it);
    }
  }
  if(!fallidos.empty()){
    cout<<"Los siguientes elementos no pudieron procesarse adecuadamente:\n";
    for(auto it=fallidos.begin();it!=fallidos.end();it++){
      cout<<"Elemento: "<<it->obtenerTipoElemento()<<" Coordenadas: ("<<it->obtenerCoordenada_x()<<","<<it->obtenerCoordenada_y()<<")\n";
    }
    return false;
  }
  return true;
}
//Función para buscar los elementos en cierto cuadrante
bool en_cuadrante(Curiosity &robot, KDTree &arbol, string x1, string x2, string y1, string y2){
  if(arbol.vacio()){
   cout<<"Los elementos no han sido ubicados todavía (con el comando ubicar_elementos)\n"; 
  return false;
  }
  if(!esNumero(x1)||!esNumero(x2)||!esNumero(y1)||!esNumero(y2)){
    cout<<"La información de cuadrante no corresponde a los datos esperados(x_min,x_max,y_min,y_max)\n";
    return false;
  }
  int xmin=stoi(x1);
  int xmax=stoi(x2);
  int ymin=stoi(y1);
  int ymax=stoi(y2);
  if(xmin>xmax||ymin>ymax){
    return false;
  }
  cout<<"Los elementos ubicados en el cuadrante solicitado son:\n";
  if(!arbol.buscar(new Rectangulo(xmin,xmax,ymin,ymax,"Cuadrante"))){  //*Se crea un objeto tipo rectangulo ya que se hace uso de la función 'contiene' propia de la clase Rectangulo*
  cout<<"*No se encontraron elementos en el cuadrante solicitado*\n";
  }
  return true;
}
