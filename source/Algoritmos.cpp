#include "../include/Algoritmos.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>

void CaminoFloyd(Graph::vertex_t i, Graph::vertex_t j, std::vector<std::vector<Graph::vertex_t>> &puntos, Graph &g)
{
    Graph::vertex_t k = puntos[i][j];

    if (k < 0) {
        return;
    } else {
        CaminoFloyd(i, k, puntos, g);
        cout << g.Etiqueta(k) << " ";
        CaminoFloyd(k, j, puntos, g);
    }
}

void Floyd(Graph &g)
{
    int num_v = g.NumVertices();

    double costos[num_v][num_v];
    std::vector<std::vector<Graph::vertex_t>> puntos;
    puntos.resize( num_v, vector<Graph::vertex_t>( num_v, -1 ) );

    for (int i = 0; i < num_v; i++) {
        for (int j = 0; j < num_v; j++) {
            if (i == j)
                costos[i][j] = 0;
            else
                costos[i][j] = g.Adyacentes(i, j) ? (double)g.Peso(i, j) : std::numeric_limits<double>::infinity();
        }
    }

    for (int k = 0; k < num_v; k++) {
        for (int i = 0; i < num_v; i++) {
            for (int j = 0; j < num_v; j++) {
                if (costos[i][j] > costos[i][k] + costos[k][j]) {
                    costos[i][j] = costos[i][k] + costos[k][j];
                    puntos[i][j] = k;
                    std::cout << "DEBUG: setting i, j, k" << i << "," << j << "," << k << std::endl;
                }
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Matriz de costos más cortos (desde\\hacia):" << endl;

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
                        << costos[it1][it2]  << " ";
        }
        cout << endl;
    }

    std::cout << std::endl;
    std::cout << "Matriz de puntos medios (desde\\hacia):" << endl;

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
                        << puntos[it1][it2]  << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Caminos:" << endl;
    for (int i = 0; i < num_v; i++) {
        for (int j = 0; j < i; j++) {
            cout << g.Etiqueta(i) << " ";
            CaminoFloyd(i,j,puntos,g);
            cout << g.Etiqueta(j) << " ";
            cout << endl;
        }
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

Graph copiar(Graph &g)
{
    Graph g2;
    vertex_t vert = g1.PrimerVertice();
    while(vert !=NULL)
    {
        g2.AgregarVertice(g1.Etiqueta(vert));
        vert = g1.SgteVertice(vert);
    }
    vertex_t v1 = g1.PrimerVertice();
    vertex_t vcopia;
    while(v1 != NULL)
    {
        tag_t e = g2.PrimerVertice();
        vcopia = g2.PrimerVertice();
        while(vcopia != NULL)
        {
            if(g2.Etiq(vcopia)==e) break;
            vcopia = g2.SgteVertice(vcopia);
        }
        vertex_t v2 = g1.PrimerVertAd();
        vertex_t v2copia;
        while(v2 != NULL)
        {
            tag_t tag2 = g1.Etiqueta(v2);
            v2copia = g2.SgteVertice(v2copia);
        }
        weight_t peso = g1.Peso(v1,v2);
        g2.AgregarArista(vcopia, v2copia,peso);
        v2 = SgteVertAd; 
        
        
    }
    v1 = g1.SgteVertice(v1);
    return g2;
    
}
