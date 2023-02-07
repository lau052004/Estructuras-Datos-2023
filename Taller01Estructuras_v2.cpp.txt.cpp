#include <iostream>
#include <fstream>
using namespace std;
#define max 100

/*
    Nombre: Laura Valentina Ovalle Benítez 
    Fecha: 01-Feb-2023
    
    Problema: Se requiere crear un tipo de dato abstracto en C++ tal que pueda capturar info significativa del usuario 
    
    Solución: a) Se crea una estructura que captura los siguientes datos
                    1. "Nombre" de tipo char[20]
                    2. "Edad" de tipo int
                    3. "Cedula" de tipo long
                    4. "Movil" de tipo long
                    5. "Genero" de tipo char
                    6. "Masa corporal" de tipo float
                    7. "Direccion" de tipo String
                    8. "Cantidad de hijos" de tipo int
                    9. "Correo" de tipo String
                    10."Franja horaria" de tipo int[2]
              b) Se crea un vector para almacenar n cantidad de usuarios
              c) Se pregunta el ingreso de cada dato
              d) Finaliza mostrando los nombres de los usuarios registrados
*/


// PASO a.
struct cliente 
{
    char nombre[20]; 
    int edad;
    long cedula;
    long movil;
    char genero;
    float imc;
    char direccion[20];
    int cantHijos;
    char correo[20];
    int horario[2];
};

int reemplaza(fstream&file, cliente clientes[max]);
int leer(fstream&file, cliente clientes[max]);
void escribir(fstream&fileapp, cliente clientes[max], int j);


int main()
{ 
  //Flujo de entrada/salida llamado arch_sale
  fstream file;
  int opcion;
  //PASO b.
  cliente clientes[max];
  int canti = 0;
  char continuar = 's';

  while(continuar=='s')
    {
        cout << "------------------MENU------------------" << endl;
        cout << "1. Reemplazar o crear por primera vez el archivo" << endl;
        cout << "2. Leer archivo y agregarle datos" << endl;
        cin >>  opcion;
        switch(opcion)
        {
            case 1:
                file.open("clientes.dat",ios::binary|ios::out);
                if(!file)
                {
                  cout << endl << "No se pudo abrir el archivo de salida ";
                  return 1;
                }
                else
                {
                 canti = reemplaza(file, clientes);
                }
                file.close();
            break;
            case 2:
                file.open("clientes.dat",ios::binary|ios::in);
                if(!file)
                {
                  cout << endl << "No se pudo abrir el archivo de salida ";
                  return 1;
                }
                else
                {
                  canti = leer(file, clientes);
                }
                file.close();
            break;
        }
  
        cout << "Desea ingresar una nueva opcion (s/n)";
        cin >> continuar;
    }
  
    // PASO d.
    cout << endl << "------ Listado de clientes registrados ------" << endl;
    
    // Se imprime la información de cada una de las personas que se crearon en el arrglo 
    for(int i=0;i<canti;i++)
    {
        cout << clientes[i].nombre << endl;
        cout << clientes[i].edad << endl;
        cout << clientes[i].cedula << endl;
        cout << clientes[i].movil << endl;
        cout << clientes[i].genero << endl;
        cout << clientes[i].imc << endl;
        cout << clientes[i].direccion << endl;
        cout << clientes[i].cantHijos << endl;
        cout << clientes[i].correo << endl;
        cout << clientes[i].horario[0] << endl;
        cout << clientes[i].horario[1] << endl;
    }
}


//////////////////////////////////////////////////////////////////
int reemplaza(fstream&file, cliente clientes[max])
{
  //reemplazar el archivo
  //escribir en el archivo
  cliente clientep;
  int canti;
  
  // Se pide al usuario que ingrese la cantidad de personas que desea crear
    cout << "Ingrese la cantidad de personas que desea crear: ";
    cin >> canti;

  // PASO c.
    for(int i=0;i<canti;i++)
    {
        cout << "Nombre " << i << " ";
        cin >> clientes[i].nombre;
        cout << "Edad ";
        cin >> clientes[i].edad;
        cout << "Cedula ";
        cin >> clientes[i].cedula;
        cout << "Movil ";
        cin >> clientes[i].movil;
        cout << "Genero de la persona (m/f) ";
        cin >> clientes[i].genero;
        cout << "Indice de Masa Corporal (IMC) ";
        cin >> clientes[i].imc;
        cout << "Dirección ";
        cin >> clientes[i].direccion;
        cout << "Cantidad de Hijos ";
        cin >> clientes[i].cantHijos;
        cout << "Correo ";
        cin >> clientes[i].correo;
        cout << "Hora de llegada habitual al Gym ";
        cin >> clientes[i].horario[0];
        cout << "Hora de salida habitual al Gym ";
        cin >> clientes[i].horario[1];

        clientep = clientes[i];

        file.write((char*)&clientep,sizeof(cliente));
    }
  return canti;
}


///////////////////////////////////////////////////////////////////////
int leer(fstream&file, cliente clientes[max])
{
  cliente clientep;
  int i=0;
  int canti;
   
  file.read((char*)&clientep,sizeof(cliente));
    
  cout << " ------------------ DATOS LEIDOS DEL ARCHIVO ------------------";
  
  while(!file.eof())
  {
    cout << endl;
    cout << endl << "Nombre " << clientep.nombre;
    cout << endl << "Edad " << clientep.edad;
    cout << endl << "Cedula " << clientep.cedula;
    cout << endl << "Movil " << clientep.movil;
    cout << endl << "Genero " << clientep.genero;
    cout << endl << "Imc " << clientep.imc;
    cout << endl << "Direccion " << clientep.direccion;
    cout << endl << "CantHijos " << clientep.cantHijos;
    cout << endl << "Correo " << clientep.correo;
    cout << endl << "Llegada " << clientep.horario[1];
    cout << endl << "Salida " << clientep.horario[2];

    clientes[i] = clientep;
    i++;
  
    file.read((char*)&clientep,sizeof(cliente));
  }
    
  //Cierro el archivo y quedan los datos guardados
  file.close();

  file.open("clientes.dat",ios::binary|ios::out);
  if(!file)
  {
    cout << endl << "No se pudo abrir el archivo de salida ";
    return 1;
  }
  else
  {
    cout << endl << "Ingrese la cantidad de personas que desea agregar: ";
    cin >> canti;

    //Agreagar al archivo nuevamente lo que lee
    for(int h=0;h<i;h++)
    {
        clientep = clientes[h];

        file.write((char*)&clientep,sizeof(cliente));
    }
    
  // PASO c.
    for(int j=i;j<canti+i;j++)
    {
        cout << "Nombre " << j << " ";
        cin >> clientes[i].nombre;
        cout << "Edad ";
        cin >> clientes[i].edad;
        cout << "Cedula ";
        cin >> clientes[i].cedula;
        cout << "Movil ";
        cin >> clientes[i].movil;
        cout << "Genero de la persona (m/f) ";
        cin >> clientes[i].genero;
        cout << "Indice de Masa Corporal (IMC) ";
        cin >> clientes[i].imc;
        cout << "Dirección ";
        cin >> clientes[i].direccion;
        cout << "Cantidad de Hijos ";
        cin >> clientes[i].cantHijos;
        cout << "Correo ";
        cin >> clientes[i].correo;
        cout << "Hora de llegada habitual al Gym ";
        cin >> clientes[i].horario[0];
        cout << "Hora de salida habitual al Gym ";
        cin >> clientes[i].horario[1];

        clientep = clientes[i];

        file.write((char*)&clientep,sizeof(cliente));
    }
    file.close();
    return canti+i;
  }
}
