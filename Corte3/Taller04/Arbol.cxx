#include "Arbol.h"
#include <queue>
#include <vector>

Arbol ::Arbol()
{
    this->raiz=NULL;
}

Arbol::Arbol(int val)
{
Nodo* nodo= new Nodo;
nodo->fijarDato(val);
this->raiz=nodo; 
}

Arbol ::~Arbol()
{
if (this->raiz != NULL) 
{
    delete this->raiz;
    this->raiz = NULL;
}
}

int Arbol ::datoRaiz()
{
return (this->raiz)->obtenerDato();
}

Nodo* Arbol ::obtenerRaiz()
{
return this->raiz;
}

void Arbol ::fijarRaiz(Nodo* n_raiz)
{
this->raiz=n_raiz;
}

bool Arbol ::esVacio()
{
    return this->raiz==NULL;
}

bool Arbol::insertar(int val) 
{
    bool estaInsertado{false};

    if (this->raiz==NULL) 
    {
        Nodo* nodo= new Nodo;
        nodo->fijarDato(val);
        this->raiz=nodo;
        estaInsertado = true;
    } 
    else 
    {
        estaInsertado =insertarNodo(val, this->raiz);
    }

    return estaInsertado;
}

// Inserta un nuevo nodo dentro del arbol.
bool Arbol::insertarNodo(int nval, Nodo* nodo) 
{
    bool eval=false;
    
       //si es hoja se ingesa
    if (nodo->obtenerHijoSupIzq() == NULL) 
        {
            Nodo* nuevo=new Nodo;
            nuevo->fijarDato(nval);
            nodo->fijarHijoSupIzq(nuevo);
            eval=true;
        }
        //si es dos y no esta lleno
        else if(nodo->obtenerHijoSupIzq()->obtenerDato()==2 && nodo->obtenerHijoSupIzq()->estaCompletode1sy0s()==-1)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoSupIzq());
        }
        else if(nodo->obtenerHijoSupIzq()->obtenerDato()==2 && nodo->obtenerHijoSupIzq()->estaCompletode1sy0s()==4 && nodo->obtenerHijoSupIzq()->obtenerHijoInfIzq()->estaCompletode1sy0s()!=0)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoSupIzq());
        }
    
    
      //si es hoja se ingesa   
        else if (nodo->obtenerHijoSupDer()== NULL) 
        {
            Nodo* nuevo=new Nodo;
            nuevo->fijarDato(nval);
            nodo->fijarHijoSupDer(nuevo);
            eval=true;
        }
        //si es dos y no esta lleno
        else if(nodo->obtenerHijoSupDer()->obtenerDato()==2 && nodo->obtenerHijoSupDer()->estaCompletode1sy0s()==-1)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoSupDer());
        }
        else if(nodo->obtenerHijoSupDer()->obtenerDato()==2 && nodo->obtenerHijoSupDer()->estaCompletode1sy0s()==4 && nodo->obtenerHijoSupDer()->obtenerHijoInfIzq()->estaCompletode1sy0s()!=0)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoSupDer());
        }
    
    
        else if (nodo->obtenerHijoInfDer()== NULL) 
        {
            Nodo* nuevo=new Nodo;
            nuevo->fijarDato(nval);
            nodo->fijarHijoInfDer(nuevo);
            eval=true;
        }
        else if(nodo->obtenerHijoInfDer()->obtenerDato()==2 && nodo->obtenerHijoInfDer()->estaCompletode1sy0s()==-1)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfDer());
        }
        else if(nodo->obtenerHijoInfDer()->obtenerDato()==2 && nodo->obtenerHijoInfDer()->estaCompletode1sy0s()==4 && nodo->obtenerHijoInfDer()->obtenerHijoInfIzq()->estaCompletode1sy0s()!=0)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfDer());
        }
    
        else if (nodo->obtenerHijoInfIzq()== NULL) 
        {
            Nodo* nuevo=new Nodo;
            nuevo->fijarDato(nval);
            nodo->fijarHijoInfIzq(nuevo);
            eval=true;
        }
        else if(nodo->obtenerHijoInfIzq()->obtenerDato()==2 && nodo->obtenerHijoInfIzq()->estaCompletode1sy0s()==-1)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfIzq());
        }
        else if(nodo->obtenerHijoInfIzq()->obtenerDato()==2 && nodo->obtenerHijoInfIzq()->estaCompletode1sy0s()==4 && nodo->obtenerHijoInfIzq()->obtenerHijoInfIzq()->estaCompletode1sy0s()!=0)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfIzq());
        }
    
    if(!eval)
    {
        //si es hoja se ingesa
        if (nodo->obtenerHijoSupDer()== NULL)
        {
            Nodo* nuevo=new Nodo;
            nuevo->fijarDato(nval);
            nodo->fijarHijoSupDer(nuevo);
            eval=true;
        }
        //si es dos y no esta lleno
        else if(nodo->obtenerHijoSupDer()->obtenerDato()==2 && nodo->obtenerHijoSupDer()->estaCompletode1sy0s()==-1)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoSupDer());
        }
        else if(nodo->obtenerHijoSupDer()->obtenerDato()==2 && nodo->obtenerHijoSupDer()->estaCompletode1sy0s()==4 && nodo->obtenerHijoSupDer()->obtenerHijoInfIzq()->estaCompletode1sy0s()!=0)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoSupDer());
        }
    
    
        else if (nodo->obtenerHijoInfDer()== NULL)
        {
            Nodo* nuevo=new Nodo;
            nuevo->fijarDato(nval);
            nodo->fijarHijoInfDer(nuevo);
            eval=true;
        }
        else if(nodo->obtenerHijoInfDer()->obtenerDato()==2 && nodo->obtenerHijoInfDer()->estaCompletode1sy0s()==-1)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfDer());
        }
        else if(nodo->obtenerHijoInfDer()->obtenerDato()==2 && nodo->obtenerHijoInfDer()->estaCompletode1sy0s()==4 && nodo->obtenerHijoInfDer()->obtenerHijoInfIzq()->estaCompletode1sy0s()!=0)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfDer());
        }

        else if (nodo->obtenerHijoInfIzq()== NULL)
        {
            Nodo* nuevo=new Nodo;
            nuevo->fijarDato(nval);
            nodo->fijarHijoInfIzq(nuevo);
            eval=true;
        }
        else if(nodo->obtenerHijoInfIzq()->obtenerDato()==2 && nodo->obtenerHijoInfIzq()->estaCompletode1sy0s()==-1)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfIzq());
        }
        else if(nodo->obtenerHijoInfIzq()->obtenerDato()==2 && nodo->obtenerHijoInfIzq()->estaCompletode1sy0s()==4 && nodo->obtenerHijoInfIzq()->obtenerHijoInfIzq()->estaCompletode1sy0s()!=0)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfIzq());
        }
        
    }
    
    if(!eval)
    {
        if (nodo->obtenerHijoInfDer()== NULL)
        {
            Nodo* nuevo=new Nodo;
            nuevo->fijarDato(nval);
            nodo->fijarHijoInfDer(nuevo);
            eval=true;
        }
        else if(nodo->obtenerHijoInfDer()->obtenerDato()==2 && nodo->obtenerHijoInfDer()->estaCompletode1sy0s()==-1)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfDer());
        }
        else if(nodo->obtenerHijoInfDer()->obtenerDato()==2 && nodo->obtenerHijoInfDer()->estaCompletode1sy0s()==4 && nodo->obtenerHijoInfDer()->obtenerHijoInfIzq()->estaCompletode1sy0s()!=0)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfDer());
        }
                
    
    
        else if (nodo->obtenerHijoInfIzq()== NULL)
        {
            Nodo* nuevo=new Nodo;
            nuevo->fijarDato(nval);
            nodo->fijarHijoInfIzq(nuevo);
            eval=true;
        }
        else if(nodo->obtenerHijoInfIzq()->obtenerDato()==2 && nodo->obtenerHijoInfIzq()->estaCompletode1sy0s()==-1)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfIzq());
        }
        else if(nodo->obtenerHijoInfIzq()->obtenerDato()==2 && nodo->obtenerHijoInfIzq()->estaCompletode1sy0s()==4 && nodo->obtenerHijoInfIzq()->obtenerHijoInfIzq()->estaCompletode1sy0s()!=0)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfIzq());
        }
    }
    
    if(!eval)
    {
        if (nodo->obtenerHijoInfIzq()== NULL)
        {
            Nodo* nuevo=new Nodo;
            nuevo->fijarDato(nval);
            nodo->fijarHijoInfIzq(nuevo);
            eval=true;
        }
        else if(nodo->obtenerHijoInfIzq()->obtenerDato()==2 && nodo->obtenerHijoInfIzq()->estaCompletode1sy0s()==-1)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfIzq());
        }
        else if(nodo->obtenerHijoInfIzq()->obtenerDato()==2 && nodo->obtenerHijoInfIzq()->estaCompletode1sy0s()==4 && nodo->obtenerHijoInfIzq()->obtenerHijoInfIzq()->estaCompletode1sy0s()!=0)
        {
            eval=insertarNodo(nval,nodo->obtenerHijoInfIzq());
        }
    }
            
    return eval;
}

void Arbol ::preOrden()
{
    if(!this->esVacio())
{
    this->preOrden(this->obtenerRaiz());
}
}

void Arbol::preOrden(Nodo* nodo)
{
    if(nodo!=NULL)
{
    std::cout<<nodo->obtenerDato()<<" ";

    this->preOrden(nodo->obtenerHijoSupIzq());

    this->preOrden(nodo->obtenerHijoSupDer());

    this->preOrden(nodo->obtenerHijoInfDer());

    this->preOrden(nodo->obtenerHijoInfIzq());

}

}


void Arbol ::inOrden()
{
    if(!this->esVacio())
    {
    this->inOrden(this->raiz);
    }
}

void Arbol ::inOrden(Nodo* nodo)
{
if(nodo!=NULL)
{
    this->inOrden(nodo->obtenerHijoSupIzq());

    this->inOrden(nodo->obtenerHijoSupDer());

    std::cout<<nodo->obtenerDato()<<" ";

    this->inOrden(nodo->obtenerHijoInfDer());

    this->inOrden(nodo->obtenerHijoInfIzq());
    
}

}

void Arbol ::posOrden()
{
    if(!this->esVacio())
{
    this->posOrden(this->raiz);
}
}

void Arbol ::posOrden(Nodo* nodo)
{

if(nodo!=NULL)
{
    this->posOrden(nodo->obtenerHijoSupIzq());

    this->posOrden(nodo->obtenerHijoSupDer());

    this->posOrden(nodo->obtenerHijoInfDer());

    this->posOrden(nodo->obtenerHijoInfIzq());

    std::cout<<nodo->obtenerDato()<<" ";
}

}


void Arbol ::armarMatriz(std::vector<std::vector<int>>& imagen, int tamano)
{
if(!this->esVacio())
{
    
    this->armarMatriz(this->obtenerRaiz(),imagen, tamano,0,0); 
}
}

void Arbol::armarMatriz(Nodo* nodo, std::vector<std::vector<int>>& imagen, int tamano, int inicioI,int inicioJ)
{
    //si no es nulo, se entra
    if(nodo!=NULL)
    {
        //si no es dos significa que se debe ingresar datos en la matriz
        if(nodo->obtenerDato()!=2)
        {
        //se inicializa en 0
        int val=0;

        //pero si el dato del nodo es 1, se cambia
        if(nodo->obtenerDato()==1)
        {
            val=1;
        }
        
        //se llena el pedazo correspondiente de la matriz con el dato del nodo
        
        for(int i=inicioI; i<inicioI+tamano; i++)
        {
            for(int j=inicioJ; j<inicioJ+tamano; j++)
            {
                imagen[i][j]=val;
            }
        }
        
        }

        //de lo contrario es dos
        //primero se visita siempre el extremo SupIzq
        this->armarMatriz(nodo->obtenerHijoSupIzq(), imagen, tamano/2, inicioI,inicioJ);

        this->armarMatriz(nodo->obtenerHijoSupDer(), imagen, tamano/2, inicioI,inicioJ+tamano/2);

        this->armarMatriz(nodo->obtenerHijoInfDer(), imagen, tamano/2, inicioI+tamano/2,inicioJ+tamano/2);
        
        this->armarMatriz(nodo->obtenerHijoInfIzq(), imagen, tamano/2, inicioI+tamano/2,inicioJ);

    }
}

