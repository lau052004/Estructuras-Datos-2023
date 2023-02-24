/*
  Pasos:
    1. Definir una clase "Cancion" con  los siguientes atributos
       a. nombre, de tipo cadena de caracteres
       b. autor, de tipo cadena de caracteres
       c. genero, de tipo cadena de caracteres
       d. album, de tipo cadena de caracteres
       e. year, de tipo entero
       f. duracion, de tipo decimal
       g. calificacion, de tipo decimal
    2. Crear vector de tipo Cancion
       Se decidió utilizar un vector ya que es más fácil la manipulación de los datos en esta estructura que en una queu, stack        o lista, y debido a que se va a estar constantemente accediendo y comparando los datos que se encuentran dentro de la            estructura, es mas sencillo poder acceder a ellos de manera aleatoria y no secuencial
    3. Leer el archivo de texto de canciones y capturar los datos guardandolos en el vector creado anteriormente
    4. Listar todos los autores presentes, ordenados alfabéticamente
       a. Crear una función personalizada para comparar los nombres de los autores
       b. Utilizar la función sort() en conjunto con la función de comparar creada anteriormente
       c. Imprimir la lista de autores ordenada de manera alfabetica
    6. Dado un autor, listar todas sus canciones ordenadas alfabéticamente
       a. Se captura el nombre del autor de cual se desea saber el nombre de sus canciones 
       b. Se almacenan las canciones que pertenezcan al autor seleccionado en un vector
       c. Se ordenan alfabeticamente las canciones con ayuda de una función que compara los nombres de las canciones y la función sort()
    7. Listar todos los álbumes presentes, ordenados cronológicamente.
       a. Se recorre el vector de canciones
       b. Se almacenan los album sin repeticion en un nuevo vector
       c. Se organizan por año los album con ayuda de una función personalizada que compara el año de cada album en conjunto con la función sort()
    8. Dado un álbum, listar todas las canciones que componen un álbum, ordenadas alfabéticamente por el nombre
de la canción.
       a. Se ordena el vector de canciones alfabeticamente utilizando una funcion personalizada que compara los nombres de las canciones en conjunto con la funcion sort()
       b. Se guardan las caciones que pertenezcan a ese album en una cola, debido a que ya fueron previamente ordenadas alfabéticamente aquí ese prden se mantiene
    9. Listar todas las canciones y su álbum, ordenadas alfabéticamente primero por el álbum y después por el
nombre de la canción.
       a. Se ordena el vector de canciones utilizando una funcion personalizada que compara primero por el nombre del album y luego pot el nombre de la canción en conjunto con la función sort()
       b. Las canciones que pertenecen al album seleccionado se guardan en una nueva cola, y debido a que ya se encuentran organizadas de acuerdo al album y al nombre de la canción, este orden se mantiene

*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Cancion {
  public:
      string nombre;
      string autor;
      string genero;
      string album;
      int year;
      float duracion;
      float calificacion;
};

void leerCanciones(vector <Cancion> &canciones)
{   
  Cancion auxCancion;
  string fileName = "example2.txt";
  ifstream archivoCanciones(fileName);
  string line;
  string word;
  int i=0;
  int canti;
  char delimiter = '|';
  
  getline(archivoCanciones, line);
  canti = stoi(line);
    
  //Leer el archivo de texto
  while(getline(archivoCanciones,line))
  {
    stringstream str(line);
    getline( str, word,delimiter);
    auxCancion.nombre = word;
    
    getline( str, word,delimiter);
    auxCancion.autor = word;
   
    getline( str, word,delimiter);
    auxCancion.genero = word;
    
    getline( str, word,delimiter);
    auxCancion.album = word;
    
    getline( str, word,delimiter);
    auxCancion.year = stoi(word);
    
    
    //Guardar la cancion en la estructura de datos de herramientas
    canciones.push_back(auxCancion);
  }
}

void imprimirCanciones(vector <Cancion> &canciones)
{
  cout << "La cantidad de canciones guardadas es " << canciones.size();
  cout << endl << "Datos de las canciones guardadas:" << endl;
  for (vector<Cancion>::iterator it = canciones.begin(); it != canciones.end(); it++) 
  {
    cout << "Nombre: " << it->nombre <<endl;
    cout << "Autor: " << it->autor <<endl;
    cout << "Genero: " << it->genero <<endl;
    cout << "Album: " << it->album <<endl;
    cout << "Año: " << it->year <<endl;
  }
}

//----------------------- OPCIÓN 1 -----------------------------------------------------
bool compararPorNombreAutor(const Cancion& a, const Cancion& b) 
{
  return a.autor < b.autor;
}

void listarAutores(vector<Cancion> /*&*/canciones){
  sort(canciones.begin(), canciones.end(), compararPorNombreAutor);
  cout << "------- Vector ordenado por: Nombres de autor -------" << endl;
  for (vector<Cancion>::iterator it = canciones.begin(); it != canciones.end(); it++) 
  {
    cout << it->autor <<endl;
  }
}

//----------------------- OPCIÓN 2 -----------------------------------------------------
bool compararPorNombreCancion(const Cancion& a, const Cancion& b) 
{
  return a.nombre < b.nombre;
}

void cancionesXAutor(vector<Cancion> &canciones, vector<Cancion> &CancionesXAutor)
{
  string autorBuscar;
  
  cout << "Ingrese el nombre del autor: ";
  cin >> autorBuscar;
  
  for (vector<Cancion>::iterator it = canciones.begin(); it != canciones.end(); it++) 
  {
    if(it->autor==autorBuscar)
    {
      CancionesXAutor.push_back(*it);
    }
  }

  //Organizar alfabéticamente el vector de las canciones que pertenecen al autor que se busca
  sort(CancionesXAutor.begin(), CancionesXAutor.end(), compararPorNombreCancion);
  cout << "------- Vector ordenado por: Nombre de canciones -------" << endl;
  for (vector<Cancion>::iterator it = CancionesXAutor.begin(); it != CancionesXAutor.end(); it++) 
  {
    cout << it->autor << "=" << it->nombre <<endl;
  }
}

//----------------------- OPCIÓN 3 -----------------------------------------------------
bool compararPorYear(const Cancion& a, const Cancion& b) 
{
  return a.year < b.year;
}

void AlbumXyear(vector<Cancion> &canciones, vector<Cancion> &CancionesXAlbum)
{
  bool encontrado;
  for (vector<Cancion>::iterator it = canciones.begin(); it != canciones.end(); it++) 
  {
    encontrado = false;
    // Guardar los album sin repeticion en un nuevo vector
    for (vector<Cancion>::iterator it2 = CancionesXAlbum.begin(); it2 != CancionesXAlbum.end(); it2++)
    {
      if(it->album == it2->album)
      {
        encontrado = true;
      }
    }
    if(encontrado==false)
    {
      CancionesXAlbum.push_back(*it);
    }
  }

  //Organizar alfabéticamente el vector de las canciones que pertenecen al autor que se busca
  sort(CancionesXAlbum.begin(), CancionesXAlbum.end(), compararPorYear);
  cout << "------- Vector ordenado por: Año del album: -------" << endl;
  for (vector<Cancion>::iterator it = CancionesXAlbum.begin(); it != CancionesXAlbum.end(); it++) 
  {
    cout << it->album << "=" << it->year <<endl;
  }
}

//----------------------- OPCIÓN 4 -----------------------------------------------------
void cancionesXAlbum(vector<Cancion> canciones, queue <Cancion> &CancionesXalbum)
{
  string albumBuscar;
  //Ordenar el vector de canciones 
  sort(canciones.begin(), canciones.end(), compararPorNombreCancion);

  cout << "Nombre del album:";
  cin >> albumBuscar;
    
  for (vector<Cancion>::iterator it = canciones.begin(); it != canciones.end(); it++) 
  {
    if(it->album==albumBuscar)
    {
      CancionesXalbum.push(*it);
    }
  }
}

//----------------------- OPCIÓN 5 -----------------------------------------------------
bool comparar(Cancion a, Cancion b) 
{
  if(a.album < b.album) 
  {
    return true;
  }
  else if(a.album == b.album) 
  {
    if(a.nombre < b.nombre) 
    {
      return true;
    }
  }
  return false;
}


void AlbumANDcancion(vector<Cancion> canciones, queue<Cancion> &AlbumANDCancion)
{
  //Se ordena el vector original por album y canciones para luego guardarlo en la cola de canciones ordenada igualmente
  sort(canciones.begin(), canciones.end(), comparar);

  for (vector<Cancion>::iterator it = canciones.begin(); it != canciones.end(); it++) 
  {
      AlbumANDCancion.push(*it);
  }
}

//----------------------- MAIN -----------------------------------------------------
int main() {
 //Declaración de estructuras 
  vector <Cancion> canciones;
  vector <Cancion> CancionesXAutor;
  vector <Cancion> album;
  queue <Cancion> CancionesXalbum;
  queue <Cancion> AlbumANDCancion;
  
  int opcion;

  //Lectura de canciones
  leerCanciones(canciones);
  //Imprimir canciones leidas del archivo .txt
  imprimirCanciones(canciones);
  

  // Menú
  do
  {
    cout<< endl << endl << "1. Listar todos los autores presentes, ordenados alfabéticamente"<<endl;
    cout<<"2. Dado un autor, listar todas sus canciones ordenadas alfabéticamente"<<endl;
    cout<<"3. Listar todos los álbumes presentes, ordenados cronológicamente"<<endl;
    cout<<"4. Dado un álbum, listar todas las canciones que componen un álbum, ordenadas alfabéticamente por el nombre de la canción" <<endl;
    cout<<"5. Listar todas las canciones y su álbum, ordenadas alfabéticamente primero por el álbum y después por el nombre de la canción"<<endl;
    cout<<"6. salir"<<endl;
    cin>>opcion;
    
    switch (opcion)
    {
        case 1:
          listarAutores(canciones);   
          break; 
        
        case 2:
          cancionesXAutor(canciones, CancionesXAutor);
          break; 
            
        case 3: 
          AlbumXyear(canciones, album); 
          break; 
        
        case 4:
          cancionesXAlbum(canciones, CancionesXalbum); 
          // Imprimir las canciones del album
          cout << "------- Canciones de un album ordenadas alfabeticamente -------" << endl;
          while(!CancionesXalbum.empty()) {
            cout << "Album: " << CancionesXalbum.front().album << " Cancion: " <<  CancionesXalbum.front().nombre << endl;
            CancionesXalbum.pop();
          }
          break;  
         
        case 5:
          AlbumANDcancion(canciones, AlbumANDCancion);
          cout << "------- Canciones organizadas por album y luego por canciones -------" << endl;
          while(!AlbumANDCancion.empty()) {
            cout << "Album: " << AlbumANDCancion.front().album << " Cancion: " <<  AlbumANDCancion.front().nombre << endl;
            AlbumANDCancion.pop();
          }
          break;
    
        case 6:
          cout<<"TEMINO EL PROGRAMA";
          break; 
        default:
          cout<<"\nEl numero ingresado no es valido, ingrese uno nuevo\n";
          break;
    }
  } while(opcion!=6);
    return 0;
}
  
