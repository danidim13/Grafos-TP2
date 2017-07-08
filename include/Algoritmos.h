#ifndef __ALGORITMOS_H__
#define __ALGORITMOS_H__

#include "Graph.h"

/**
 * Encuentra el camino más corto entre cada par de
 * vértices del grafo. Esta información se muestra
 * en la pantalla en forma de una tabla.
 */
void Floyd(Graph g);

/**
 * Elimina un vértice no aislado del grafo.
 * @return Verdadero si la operación tiene éxito.
 */
bool EliminarVert(Graph g);

/**
 * Implementa el algoritmo de Colorea de Grafos.
 * Usa búsqueda exhaustiva pura para determinar el colero
 * óptimo.
 */
void ColorGraph(Graph g);


#endif
