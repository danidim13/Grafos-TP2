#ifndef NODOARISTA_H
#define NODOARISTA_H
#include <iostream>
using namespace std;

struct NodoArista
{
        int peso;
        string etiqueta;
        NodoArista* siguiente;
        NodoVertice *vertices;
};

#endif // NODOARISTA_H
