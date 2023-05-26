#include <iostream>
#include<stdio.h>
using namespace std;

int x=0;

/*
    Para poder ubicar las reinas se deben comprobar tres cosas 
    (1) que ninguna reina esté en la misma fila que otra
    (2) que ninguna reina esté en la misma columna que otra
    (3) que ninguna reina esté en la diagonal de otra

    Para esto se crea un arreglo de tamaño [n], y solo se va a por ubicar una reina
    en cada una de las pocisiones de este, representando las columnas.

    Posteriormente, el valor que tendrá el arreglo mencionado en la pocisión [n] va
    a ser igual a la fila en la que se ubicará la reina número [n].

    Finalmente, para comprobar que no se crucen las diagonales, se comparará el 
    resultado del valor absoluto de la resta entre columna y fila de la nueva reina que 
    se quiera ubicar, con el resultado del valor absoluto de la resta de columna y fila 
    de todas las reinas existentes. En caso de que estos dos resultados sean iguales en 
    alguna de las comparaciones, se sabe que allí no se puede ubicar la nueva reina.
*/

/*
    Comprobamos si la reina está en una posicion válida.
    
    Nota: Para que la posicion sea valida las reinas no deben estar 
    en la misma columna, en la misma fila, ni en diagonal
*/
bool comprobar(int reinas[],int n, int k){
	int i;
	for(i=0;i<k;i++){
		if( (reinas[i]==reinas[k]) or (abs(k-i) == abs(reinas[k]-reinas[i]))){
			return false;
		}
	}
	return true;
}
	
void buscarSoluciones(int reinas[],int cantidad, int k){
	// Se comprueba si la cantidad de reinas ubicadas corresponde a la totalida de las reinas
	if(k==cantidad){
		x++;
		cout<<"Solucion "<< x <<" : ";
		for(int i=0;i<cantidad;i++){
			cout<<reinas[i]<<" , ";
		}
		cout << endl;	
	}
	//Si aún quedan reinas por ubicar el algoritmo debe seguir ejecutandose
	else{
		for(reinas[k]=0;reinas[k]<cantidad;reinas[k]++){
			if(comprobar(reinas,cantidad,k)){
				buscarSoluciones(reinas,cantidad,k+1);
			}
		}
	}
}
		
int main(int argc, char *argv[]) {
	int k=0;
	int cantidad;

	cout << "Cantidad de reinas : ";
	cin >> cantidad;

	int *reinas = new int[cantidad];

    // Se inicializan las reinas en -1 para saber que aún no están pocisionadas
	for(int i=0;i<cantidad;i++){
		reinas[i]=-1;
	}

	buscarSoluciones(reinas,cantidad,k);

	return 0;
}
