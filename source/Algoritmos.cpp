#include "../include/Algoritmos.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <vector>
#include <set>

using namespace std;

void CaminoFloyd(Graph::vertex_t i, Graph::vertex_t j, vector<vector<Graph::vertex_t>> &puntos, Graph &g)
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
    vector<vector<Graph::vertex_t>> puntos;
    puntos.resize( num_v, vector<Graph::vertex_t>( num_v, -1 ) );

    for (int i = 0; i < num_v; i++) {
        for (int j = 0; j < num_v; j++) {
            if (i == j)
                costos[i][j] = 0;
            else
                costos[i][j] = g.Adyacentes(i, j) ? (double)g.Peso(i, j) : numeric_limits<double>::infinity();
        }
    }

    for (int k = 0; k < num_v; k++) {
        for (int i = 0; i < num_v; i++) {
            for (int j = 0; j < num_v; j++) {
                if (costos[i][j] > costos[i][k] + costos[k][j]) {
                    costos[i][j] = costos[i][k] + costos[k][j];
                    puntos[i][j] = k;
                    //cout << "DEBUG: setting i, j, k" << i << "," << j << "," << k << endl;
                }
            }
        }
    }

    cout << endl;
    cout << "Matriz de costos más cortos (desde\\hacia):" << endl;

    cout << "    ";
    for (int it1 = 0; it1 < num_v; it1++) {
        cout << setfill(' ')
                    << setw(3)
                    << g.Etiqueta(it1) << " ";
    }
    cout << endl;

    for (int it1 = 0; it1 < num_v; it1++) {
        cout << setfill(' ')
                    << setw(3)
                    << g.Etiqueta(it1) << " ";
        for (int it2 = 0; it2 < num_v; it2++) {
            cout << setprecision(3)
                        << setfill(' ')
                        << setw(3)
                        << costos[it1][it2]  << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Matriz de puntos medios (desde\\hacia):" << endl;

    cout << "    ";
    for (int it1 = 0; it1 < num_v; it1++) {
        cout << setfill(' ')
                    << setw(3)
                    << g.Etiqueta(it1) << " ";
    }
    cout << endl;

    for (int it1 = 0; it1 < num_v; it1++) {
        cout << setfill(' ')
                    << setw(3)
                    << g.Etiqueta(it1) << " ";
        for (int it2 = 0; it2 < num_v; it2++) {
            cout << setprecision(3)
                        << setfill(' ')
                        << setw(3)
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
    //cout << "Eliminando " << g.Etiqueta(v) << endl;
    //g.print();
    // Se deben eliminar las aristas que tenga v primero
    Graph::vertex_t v_arista;
    for (v_arista = g.PrimerVertAd(v); v_arista != Graph::V_NULL; v_arista = g.SgteVertAd(v, v_arista))
    {
        //cout << "Eliminando arista (" <<
            //g.Etiqueta(v) << ", " << g.Etiqueta(v_arista)
            //<< ")" << endl;
        g.EliminarArista(v, v_arista);
    }

    //cout << "Listo!" << endl;
    //g.print();
    
    if (g.NumVertAd(v) != 0) {
        cout << "Algo salio mal xD" << endl;
        return false;
    }

    g.EliminarVertice(v);
    return true;
}

void ColorearRec(const Graph &g, Graph::vertex_t v, int color, ColorStaticVars &vars)
{
    //cout << "Coloreando " << v << " de color " << color << endl;
    vars.ColorVertices[v] = color;

    // Se verifica si es factible
    Graph::vertex_t v_her;
    for (v_her = g.PrimerVertAd(v); v_her != Graph::V_NULL; v_her = g.SgteVertAd(v, v_her)) {
        if (vars.ColorVertices[v] == vars.ColorVertices[v_her]) {
            // Condición de parada
            /*
            cout << "Parando por colores repetidos en adyacente "
                << v_her << endl;
            cout << "Colores = " << vars.ColorVertices[v] << "," << vars.ColorVertices[v_her] << endl;
            */
            vars.ColorVertices[v] = -1;
            return;
        }
    }

    vars.VerticesColoreados.insert(v);

    if (vars.VerticesColoreados.size() == g.NumVertices()) {
        // Solución factible, condicion de parada
        vars.ColoresUsados.clear();
        //cout << "Probando solucion factible" << endl;
        for (int i = 0; i < g.NumVertices(); i++) {
            vars.ColoresUsados.insert(vars.ColorVertices[i]);
        }

        if (vars.MejorNumColor <= vars.ColoresUsados.size()) {
            // No es mejor que la mejor solucion encontrada
            // hasta el momento
            vars.ColorVertices[v] = -1;
            vars.VerticesColoreados.erase(v);
            return;
        }

        // Se actualiza la mejor solucion
        vars.MejorNumColor = vars.ColoresUsados.size();
        //cout << "Se encontro una mejor solucion: " << vars.MejorNumColor << endl;
        for (int i = 0; i < g.NumVertices(); i++) {
            vars.MejorColorVert[i] = vars.ColorVertices[i];
            //cout << vars.ColorVertices[i] << " ";
        }
        //cout << endl;

        vars.ColorVertices[v] = -1;
        vars.VerticesColoreados.erase(v);
        return;
    }

    // Si no es una solucion factible se exploran todas las
    // posibles combinaciones de colores para el siguiente 
    // vertice del grafo.
    for (int c = 0; c < g.NumVertices(); c++) {
        ColorearRec(g, g.SgteVertice(v), c, vars);
    }

    vars.ColorVertices[v] = -1;
    vars.VerticesColoreados.erase(v);
    return;
}

void ColorGraph(Graph &g)
{

    int num_v = g.NumVertices();

    ColorStaticVars vars;
    vars.ColorVertices = new int[num_v];
    vars.MejorColorVert = new int[num_v];
    vars.MejorNumColor = num_v + 1;


    for (int i = 0; i < num_v; i++) {
        // -1 representa ningún color
        vars.ColorVertices[i] = -1;
    }

    ColorearRec(g, g.PrimerVertice(), 0, vars);

    cout << "Mejor Solución: " << vars.MejorNumColor << endl;
    for (int it1 = 0; it1 < num_v; it1++) {
        cout << setfill(' ')
                    << setw(3)
                    << g.Etiqueta(it1) << " ";
    }
    cout << endl;

    for (int it2 = 0; it2 < num_v; it2++) {
        cout << setprecision(3)
                    << setfill(' ')
                    << setw(3)
                    << vars.MejorColorVert[it2]  << " ";
    }
    cout << endl;

    delete[] vars.ColorVertices;
    delete[] vars.MejorColorVert;
}
