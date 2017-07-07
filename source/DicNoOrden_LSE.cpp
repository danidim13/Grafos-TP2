#include "DicNoOrden_LSE.h"

DicNoOrden_LSE::DicNoOrden_LSE()
{
    num_elem = 0;
    cabeza = NULL;
}

DicNoOrden_LSE::~DicNoOrden_LSE()
{
    Vaciar();
}

void DicNoOrden_LSE::Imprimir() //efectos de prueba
{
    nodoPtr n = cabeza;
    if(n==NULL)
    {
        cout<<"El diccionario esta vacio" << endl;
    }
    while(n!= NULL)
    {
        cout << n->elemento << " ";
        n = n->siguiente;
    }
    cout << endl;
};

void DicNoOrden_LSE::Vaciar()
{
    nodoPtr it = cabeza;
    nodoPtr tmp;
    while (it != NULL)
    {
        tmp = it;
        it = it->siguiente;
        delete tmp;
    }
    num_elem = 0;
    cabeza = NULL;
}

bool DicNoOrden_LSE::Vacio()
{
    return num_elem == 0;
}

void DicNoOrden_LSE::Agregar(string elem)
{
    nodoPtr n = new Nodo;
    n->siguiente = NULL;
    n->elemento = elem;
    if (num_elem == 0)
    {
        // Caso especial lista vacia
        cabeza = n;
    }
    else
    {
        // Caso especial primer elemento
        if (Vacio() && num_elem == 0)
        {
            //cout << "caso especial!" << endl;
            n->siguiente = cabeza;
            cabeza = n;
            // Otros casos, se inserta antes del elemento i
        }
        else
        {
            //cout << "Buscando posicion" << endl;
            nodoPtr it = cabeza;
            for (int i=1; i < num_elem; i++)
            {
                it = it->siguiente;
                //cout << "Apuntando a " << it->elemento << endl;
            }
            // Aqui it es el nodo anterior al nodo p
            n->siguiente = it->siguiente;
            it->siguiente = n;
        }
    }
    num_elem++;
}

void DicNoOrden_LSE::Eliminar(string elem)
{
    //cout << "Borrando " << elem << endl;
    // Lista vacia
    if (num_elem == 0)
        return;

    // Caso especial primer elemento
    nodoPtr it = cabeza;
    if (elem == cabeza->elemento)
    {
        cabeza = cabeza->siguiente;
        delete it;
        num_elem--;
        return;
    }

    while ((it->siguiente) && (it->siguiente)->elemento != elem)
    {
        it = it->siguiente;
    }

    // En este punto it esta en la posicion anterior
    // a donde deberia estar elem.

    // No se encontró elem
    if (!(it->siguiente) || (it->siguiente)->elemento != elem)
    {
        return;
    }
    else
    {
        nodoPtr tmp = it->siguiente;
        it->siguiente = tmp->siguiente;
        delete tmp;
        num_elem--;
        return;
    }
}

bool DicNoOrden_LSE::Pertenece(string elem)
{
    bool siPertenece = false;
    if(num_elem > 0)
    {
        int i = 1;
        nodoPtr it = cabeza;
        while(siPertenece == false && i < num_elem)
        {
            //cout<<"ElementoBuscado: "<<elem<<" ElementoActual: "<<it->elemento<<endl;
            if(elem == it->elemento)
            {
                siPertenece = true;
            }
            it = it->siguiente;
            i++;
        }
    }
    return siPertenece;
}

int DicNoOrden_LSE::NumElem()
{
    return num_elem;
}



