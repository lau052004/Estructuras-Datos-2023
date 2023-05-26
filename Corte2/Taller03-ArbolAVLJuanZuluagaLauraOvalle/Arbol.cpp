#include "Arbol.h"
#include <vector>
using namespace std;

struct dato  
{
  float num;
  int nivel;
};

  //----------------------------------------------------------------------------------//
  // Calcula la altura de un subárbol que comienza desde el nodo "temp".
  int Arbol::altura(Nodo *temp) {
    int h = 0;
    if (temp != NULL) {
      int l_height = altura(temp->getIzquierda());
      int r_height = altura(temp->getDerecha());
      int max_height = std::max(l_height, r_height);
      h = max_height + 1;
    }
    return h;
  }

  //----------------------------------------------------------------------------------//
  // Función para calcular la diferencia de altura entre el subarbol derecho e
  // izquierdo de un nodo "temp"
  int Arbol::diferencia(Nodo *temp) {
    int l_height = altura(temp->getIzquierda());
    int r_height = altura(temp->getDerecha());
    int b_factor = l_height - r_height;
    return b_factor;
  }

  //-------FUNCIONES DE ROTACIÓN PARA BALANCEAR EL ÁRBOL------------//

  // Rotación -> Right-Right (Simple a la derecha)
  Nodo* Arbol::RR_rotacion(Nodo *padre) {
    Nodo *temp;
    temp = padre->getDerecha();
    padre->setDerecha(temp->getIzquierda());
    temp->setIzquierda(padre);
    return temp;
  }

  // Rotación -> Left-Left (Simple a la izquierda)
  Nodo* Arbol::LL_rotacion(Nodo *padre) {
    Nodo *temp;
    temp = padre->getIzquierda();
    padre->setIzquierda(temp->getDerecha());
    temp->setDerecha(padre);
    return temp;
  }

  // Rotación Right-Left = Rotación simple a la derecha y despues rotación
  // simple a la izquierda. 
  Nodo* Arbol::RL_rotacion(Nodo *padre) {
    Nodo *temp;
    temp = padre->getIzquierda();
    padre->setIzquierda(RR_rotacion(temp));
    return LL_rotacion(padre);
  }

  // Rotation Left-Right = Rotación simple a la izquierda y despues rotación
  // simple a la derecha
  Nodo* Arbol::LR_rotacion(Nodo *padre) {
    Nodo *temp;
    temp = padre->getDerecha();
    padre->setDerecha(LL_rotacion(temp));
    return RR_rotacion(padre);
  }

  //----------------------------------------------------------------------------------//
  // Función de balanceo
  Nodo* Arbol::balance(Nodo *temp) {
    int bal_factor = diferencia(temp);
    if (bal_factor > 1) {
      if (diferencia(temp->getIzquierda()) > 0)
        temp = LL_rotacion(temp);
      else
        temp = RL_rotacion(temp);
    } else if (bal_factor < -1) {
      if (diferencia(temp->getDerecha()) > 0)
        temp = LR_rotacion(temp);
      else
        temp = RR_rotacion(temp);
    }
    return temp;
  }

  //----------------------------------------------------------------------------------//
  // Insertar elementos en el arbol
  Nodo* Arbol::insertar(Nodo *raiz, int value) {
    if (raiz == nullptr) {
      raiz = new Nodo;
      raiz->setValor(value);
		  raiz->setIzquierda(NULL);
		  raiz->setDerecha(NULL);
      return raiz;
    }
    else if (value < raiz->getValor()) {
      raiz->setIzquierda(insertar(raiz->getIzquierda(), value));
      raiz = balance(raiz);
    } else if (value >= raiz->getValor()) {
      raiz->setDerecha(insertar(raiz->getDerecha(), value));
      raiz = balance(raiz);
    }
    return raiz;
  }

  //----------------------------------------------------------------------------------//
  // Recorrer el árbol en orden -> Subárbol izquierdo, Dato, Subárbol derecho
  // La función toma un puntero a un nodo como argumento, que representa el nodo
  // actual del árbol
  /*void Arbol::inorder(Nodo *raiz, std::list<int> Lista) {
    if (raiz == NULL)
    {
      return;
    }
    
	  inorder(raiz->getIzquierda(),Lista);
	   //std::cout<<tree->getValor()<<" ";
  	Lista.push_back(raiz->getValor());
  	inorder(raiz->getDerecha(),Lista);
  }*/

  void Arbol::inorder2(Nodo *raiz, std::vector<int> &vect) {
    if (raiz == NULL)
    {
      return;
    }

	  inorder2(raiz->getIzquierda(),vect);
	  //cout<<raiz->getValor()<< "  ";
  	vect.push_back(raiz->getValor());
  	inorder2(raiz->getDerecha(),vect);
  }

  //----------------------------------------------------------------------------------//
  // Función para encontrar el nodo con el valor mínimo en un subarbol
  Nodo* Arbol::Min(Nodo *nodo) {
    if (nodo == NULL)
      return NULL;
    else if (nodo->getIzquierda() == NULL)
      return nodo;
    else
      return Min(nodo->getIzquierda());
  }

  //----------------------------------------------------------------------------------//
  // Función para encontrar el nodo con el valor máximo en un subarbol
  Nodo* Arbol::Max(Nodo *nodo) {
    if (nodo == NULL)
      return NULL;
    else if (nodo->getDerecha() == NULL)
      return nodo;
    else
      return Max(nodo->getDerecha());
  }


  Nodo* Arbol::eliminar(Nodo *nodo, int value) {
    Nodo *temp;
    if (nodo == NULL) {
      return NULL;
    }
    else if (value < nodo->getValor()) {
      nodo->setIzquierda(eliminar(nodo->getIzquierda(), value));
    }
    else if (value > nodo->getValor()) {
      nodo->setDerecha(eliminar(nodo->getDerecha(), value));
    }
    else if (nodo->getIzquierda() && nodo->getDerecha()) {
      temp = Min(nodo->getDerecha());
      nodo->setValor(temp->getValor());
      nodo->setDerecha(eliminar(nodo->getDerecha(), nodo->getValor()));
    }
    else {
      temp = nodo;
      if (nodo->getIzquierda() == NULL)
        nodo = nodo->getDerecha();
      else if (nodo->getDerecha() == NULL)
        nodo = nodo->getIzquierda();
      delete temp;
    }
    if (nodo == NULL)
      return nodo;
    
    nodo = balance(nodo);
    return nodo;
  }

void Arbol::setRaiz(Nodo *raiz)
{
  this->raiz = raiz;
}

Nodo* Arbol::getRaiz()
{
  return raiz;
}

int Arbol::buscar(Nodo *raiz, int value, int nivel) {
    if (raiz == nullptr) {
        //cout << "El dato no fue encontrado en el árbol";
        return -1; // El valor no se encontró en el árbol
    } else if (value == raiz->getValor()) {
        return nivel; // El valor se encontró en el nivel actual
    } else if (value < raiz->getValor()) {
        return buscar(raiz->getIzquierda(), value, nivel + 1);
    } else {
        return buscar(raiz->getDerecha(), value, nivel + 1);
    }
}

void Arbol::mediana(int canti, Nodo *raiz)
{
  vector <int> vect;
  dato dato1;
  float median;
  if(canti%2==0)
  {
    dato dato2;
    cout << "La cantidad de datos es par " << endl;
    //Datos centrales
    inorder2(raiz, vect);
    dato1.num=vect[(canti/2)-1];
    dato2.num=vect[(canti/2)];
    
    //Nivel de cada uno -> Búsqueda en el arbol 
    //Busqueda del nivel del primer dato
    dato1.nivel=buscar(raiz,dato1.num,0);
    //Busqueda del nivel del segundo dato
    dato2.nivel=buscar(raiz,dato2.num,0);

    cout << "Los datos medios del arbol son: " << dato1.num << " y " << dato2.num << endl; 
    cout<< "Sus niveles son respectivamente: " << dato1.nivel << " y " << dato2.nivel << endl;
    
    //Mediana
    median = (dato1.num+dato2.num)/2;
    cout << "La mediana del árbol es: " << median << endl;
  }
  else
  {
    cout << "La cantidad de datos es impar " << endl;
    inorder2(raiz, vect);
    dato1.num=vect[canti/2];
    dato1.nivel=buscar(raiz,dato1.num,0);
    cout << "El dato medio del arbol es: " << dato1.num << endl; 
    cout<< "Su nivel es: " << dato1.nivel << endl;
  }
}