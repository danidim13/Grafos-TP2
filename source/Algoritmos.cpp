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
