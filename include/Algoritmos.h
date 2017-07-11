#ifndef __ALGORITMOS_H__
#define __ALGORITMOS_H__

#include "Graph.h"
#include <set>

/**
 * Encuentra el camino más corto entre cada par de
 * vértices del grafo. Esta información se muestra
 * en la pantalla en forma de una tabla.
 */
void Floyd(Graph &g);

/**
 * Elimina un vértice no aislado del grafo.
 * @return Verdadero si la operación tiene éxito.
 */
bool EliminarVert(Graph &g, Graph::vertex_t v);

struct ColorStaticVars {
    // Los colores que se han usado en la solucion actual
    set<int> ColoresUsados;
    // Los vertices que se han coloreado en la solucion actual
    set<Graph::vertex_t> VerticesColoreados;
    // El color de cada vertice en la solucion actual
    int *ColorVertices;

    int *MejorColorVert;
    int MejorNumColor;
};

void ColorearRec(const Graph &g, Graph::vertex_t v, int color, ColorStaticVars &vars);

/**
 * Implementa el algoritmo de Colorea de Grafos.
 * Usa búsqueda exhaustiva pura para determinar el colero
 * óptimo.
 */
void ColorGraph(Graph &g);


#endif
