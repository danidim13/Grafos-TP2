#include "../include/Algoritmos.h"
#include <iostream>


bool EliminarVert(Graph &g, Graph::vertex_t v)
{
    //std::cout << "Eliminando " << g.Etiqueta(v) << endl;
    //g.print();
    // Se deben eliminar las aristas que tenga v primero
    Graph::vertex_t v_arista;
    for (v_arista = g.PrimerVertAd(v); v_arista != Graph::V_NULL; v_arista = g.SgteVertAd(v, v_arista))
    {
        //std::cout << "Eliminando arista (" <<
            //g.Etiqueta(v) << ", " << g.Etiqueta(v_arista)
            //<< ")" << std::endl;
        g.EliminarArista(v, v_arista);
    }

    //std::cout << "Listo!" << std::endl;
    //g.print();

    if (g.NumVertAd(v) != 0) {
        std::cout << "Algo salio mal xD" << std::endl;
        return false;
    }

    g.EliminarVertice(v);
    return true;
}

void TieneCiclos(Graph &g)
{
    Graph::vertex_t v_arista;
    if (!g.Vacio())
    {
        DicNoOrden_LSE Dvv;
        v_arista = g.PrimerVertice();
        while (v_arista != NULL)
        {
            if (!Dvv.Pertenece(v_arista))
            {
                ProfundidadPrimeroRec(v_arista, g);
            }
            v_arista = g.SgteVertice(v_arista);
        }
        Dvv.~DicNoOrden_LSE();
    }
}


void ProfundidadPrimeroRec(Graph::vertex_t v, Graph &g)
{

    DicNoOrden_LSE Dvv;
    Dvv.Agregar(v);
    Graph::vertex_t va = g.PrimerVertAd(v);
    while(va != NULL)
    {
        if (!Dvv.Pertenece(va))
        {
            ProfundidadPrimeroRec(va,g);
        }
        va = g.SgteVertAd(v, va);
    }
}

int TotalPesoAristas(Graph &g)
{
    int totalPeso = 0;
    if (!g.Vacio())
    {
        Graph::vertex_t v = g.PrimerVertice();
        Graph::weight_t* Respuesta = g.getNeighbors(v);
        for (int it = 0; it < g.NumVertices(); it++)
        {
            totalPeso += Respuesta[it];
        }
    }
    return totalPeso;
}
