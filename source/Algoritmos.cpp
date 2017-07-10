#include "../include/Algoritmos.h"
#include <iostream>
#include <limits>
#include <iomanip>

void Floyd(Graph &g)
{
    int num_v = g.NumVertices();

    double caminos[num_v][num_v];

    for (int i = 0; i < num_v; i++) {
        for (int j = 0; j < num_v; j++) {
            if (i == j)
                caminos[i][j] = 0;
            else
                caminos[i][j] = g.Adyacentes(i, j) ? (double)g.Peso(i, j) : std::numeric_limits<double>::infinity();
        }
    }

    for (int k = 0; k < num_v; k++) {
        for (int i = 0; i < num_v; i++) {
            for (int j = 0; j < num_v; j++) {
                if (caminos[i][j] > caminos[i][k] + caminos[k][j])
                    caminos[i][j] = caminos[i][k] + caminos[k][j];
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Matriz de caminos más cortos (desde\\hacia):" << endl;

    cout << "    ";
    for (int it1 = 0; it1 < num_v; it1++) {
        cout << std::setfill(' ')
                    << std::setw(3)
                    << g.Etiqueta(it1) << " ";
    }
    cout << endl;

    for (int it1 = 0; it1 < num_v; it1++) {
        cout << std::setfill(' ')
                    << std::setw(3)
                    << g.Etiqueta(it1) << " ";
        for (int it2 = 0; it2 < num_v; it2++) {
            cout << std::setprecision(3)
                        << std::setfill(' ')
                        << std::setw(3)
                        << caminos[it1][it2]  << " ";
        }
        cout << endl;
    }
    cout << endl;
}

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
