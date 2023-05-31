#ifndef __NODO__H__
#define __NODO__H__


#include <iostream>
#include <list>

class  Nodo
{
    protected:
    int dato;
    Nodo* hijoSupIzq;
    Nodo* hijoSupDer;
    Nodo* hijoInfIzq;
    Nodo* hijoInfDer;

    public:
    Nodo();
    Nodo(int val);
    ~Nodo();
    int obtenerDato();
    void fijarDato(int val);
    Nodo* obtenerHijoSupIzq();
    Nodo* obtenerHijoSupDer();
    Nodo* obtenerHijoInfIzq();
    Nodo* obtenerHijoInfDer();
    void fijarHijoSupIzq(Nodo* sizq);
    void fijarHijoSupDer(Nodo* sder);
    void fijarHijoInfIzq(Nodo* iizq);
    void fijarHijoInfDer(Nodo* ider);
    bool esHoja();
    bool estaCompleto();
int estaCompletode1sy0s();
};

#endif
