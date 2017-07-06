#ifndef LISTAVERTICES_H
#define LISTAVERTICES_H
#include <cstdlib>
#include <iostream>
#include "NodoVertice.h"
#include "NodoArista.h"
using namespace std;

class NodoVertice;
class NodoArista;

class ListaVertices
{

public:
    int num_elem;
    NodoVertice *primero;
    typedef int peso;
    typedef string etiq;

    ListaVertices()
    {
       int num_vertices = 0;
        primero = NULL;
        //ctor
    }
    void Vaciar()
    {
      NodoVertice *it = primero;
      NodoVertice *tmp;
        while (it != NULL)
        {
            tmp = it;
            it = it->siguiente;
            delete tmp;
        }
        num_elem = 0;
        primero = NULL;
    };

    virtual ~ListaVertices()
    {
        Vaciar();
    }

    void Destruir()
    {
        Vaciar();
    }
    bool Vacia()
    {
        return num_elem == 0;
    };

    virtual string Recuperar(int p)   //debe darse un índice válido
    {
      NodoVertice *tmp = primero;
        for(int i=1; i<p; i++)
        {
            tmp = tmp->siguiente;
        }
        return tmp->etiqueta;

    };

    void Insertar(int p, string etiq)
    {
      NodoVertice *n = new NodoVertice;
        n->siguiente = NULL;
        n->etiqueta = etiq;
        n->posicion = p;
        if (num_elem == 0)
        {
            // Caso especial lista vacia
            primero = n;

        }
        else
        {

            // Caso especial primer etiqueta
            if (p == 1)
            {
                //cout << "caso especial!" << endl;
                n->siguiente = primero;
                primero = n;

                // Otros casos, se inserta antes del etiqueta i
            }
            else
            {
                //cout << "Buscando posicion" << endl;
              NodoVertice *it = primero;
                for (int i = 2; i < p; i++)
                {
                    it = it->siguiente;
                    //cout << "Apuntando a " << it->etiqueta << endl;
                }
                // Aqui it es el nodo anterior al nodo p
                n->siguiente = it->siguiente;
                it->siguiente = n;
            }
        }

        num_elem++;
    }

    void Borrar(int p)
    {
      NodoVertice *tmp; // Nodo que se va a borrar

        if (p == 1)
        {
            tmp = primero;
            primero = primero->siguiente;
        }
        else
        {
          NodoVertice *it = primero;
            for (int i = 2; i < p; i++)
            {
                it = it->siguiente;
            }
            // it apunta al nodo anterior al que se
            // va a borrar
            tmp = it->siguiente;
            it->siguiente = tmp->siguiente;
        }

        delete tmp;
        num_elem--;
    }

    void ModificarElem(int p, string etiq)
    {
      NodoVertice *n = primero;
        for(int i=1; i<p; i++)
        {
            n = n->siguiente;
        }
        n->etiqueta = etiq;
    }

    void Intercambiar(int p1, int p2)
    {

      NodoVertice *it1, *it2;

        it1 = primero;
        for (int i=1; i<p1; i++)
        {
            it1 = it1->siguiente;
        }

        it2 = primero;
        for (int i=1; i<p2; i++)
        {
            it2 = it2->siguiente;
        }

        string tmp = it1->etiqueta;
        it1->etiqueta = it2->etiqueta;
        it2->etiqueta = tmp;
    }

    int NumElem()
    {
        return num_elem;
    };

    void Imprimir() //efectos de prueba
    {
      NodoVertice *n = primero;
        if(n==NULL)
        {
            cout<<"La lista esta vacia" << endl;
        }

        else
            cout << "Recorrido de vertices" << endl;

        while(n!= NULL)
        {
            cout << n->etiqueta << " ";
            n = n->siguiente;
        }
        cout << endl;
    }

};

#endif // LISTAVERTICES_H
