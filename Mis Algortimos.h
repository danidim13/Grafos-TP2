#ifndef __ALGORITMOS_H__
#define __ALGORITMOS_H__

#include "Graph.h"
#include "DicNoOrden_LSE.h"

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

/**
 * Implementa el algoritmo de Colorea de Grafos.
 * Usa búsqueda exhaustiva pura para determinar el colero
 * óptimo.
 */
void ColorGraph(Graph &g);

/**
 * Implementa un algoritmo de recorrido en profundidad primero para averiguar si el grafo
 * tiene ciclos y usa al modelo diccionario para llevar el registro de vertices y aristas
 * visitados.
 */
void TieneCiclos(Graph &g);
/**
*   Hace un recorrido en profundidad a un grafo
*
*/
void ProfundidadPrimeroRec(Graph::vertex_t v, Graph &g);

/**
* Ve si dos grafos son iguales.
*
*/
void SonIguales(Graph &g,Graph &g2);

/**
*
* Suma el peso de todas las aristas en el grafo.
*/
int TotalPesoAristas(Graph &g);

#endif

