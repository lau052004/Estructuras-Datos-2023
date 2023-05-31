#include "Nodo.h"

Nodo::Nodo()
{
    this->dato =0;
    this->hijoSupIzq=NULL;
    this->hijoSupDer=NULL;
    this->hijoInfIzq=NULL;
    this->hijoInfDer=NULL;
}

Nodo::Nodo(int val)
{
    this->fijarDato(val);
    this->hijoSupIzq=NULL;
    this->hijoSupDer=NULL;
    this->hijoInfIzq=NULL;
    this->hijoInfDer=NULL;
}

//mirar
Nodo::~Nodo()
{
    this->hijoSupIzq=NULL;
    this->hijoSupDer=NULL;
    this->hijoInfIzq=NULL;
    this->hijoInfDer=NULL;
}

void Nodo::fijarDato(int val)
{
this->dato= val;
}

int Nodo::obtenerDato()
{
return this->dato;
}

Nodo* Nodo::obtenerHijoSupIzq()
{
    return this->hijoSupIzq;
}

Nodo* Nodo::obtenerHijoSupDer()
{
    return this->hijoSupDer;  
}

Nodo* Nodo::obtenerHijoInfIzq()
{
    return this->hijoInfIzq;    
}

Nodo* Nodo::obtenerHijoInfDer()
{
    return this->hijoInfDer;    
}

void Nodo::fijarHijoSupIzq(Nodo* sizq)
{
    this->hijoSupIzq=sizq;
}

void Nodo::fijarHijoSupDer(Nodo* sder)
{
    this->hijoSupDer=sder;  
}

void Nodo::fijarHijoInfIzq(Nodo* iizq)
{
    this->hijoInfIzq=iizq;
}

void Nodo::fijarHijoInfDer(Nodo* ider)
{
    this->hijoInfDer=ider;    
}   

bool Nodo::esHoja()
{
    return this->hijoInfDer==NULL && this->hijoInfIzq==NULL && this->hijoSupDer==NULL && this->hijoSupIzq==NULL;
}

bool Nodo::estaCompleto()
{
    return this->hijoInfDer!=NULL && this->hijoInfIzq!=NULL && this->hijoSupDer!=NULL && this->hijoSupIzq!=NULL;
}

int Nodo::estaCompletode1sy0s()
{
    //eta completo
    if(this->hijoInfDer!=NULL && this->hijoInfIzq!=NULL && this->hijoSupDer!=NULL && this->hijoSupIzq!=NULL)
    {
        //ver si hay un dos en el cuarto
        if(this->hijoInfIzq->obtenerDato()==2)
        {
        return 4;
        }
        
        return 0;
    }
    
    //no esta completo
    return -1;
    
}