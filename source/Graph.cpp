#include "../include/Graph.h"
#include <limits>
#include <cmath>
#include <iostream>
#include <iomanip>

typedef std::numeric_limits<double> D;

Graph::Graph(): M(100),
    num_vertices(0),
    num_aristas(0),
    adjMatrix(NULL),
    vertices(NULL)
{
    adjMatrix = new weight_t*[M];
    for (int i = 0; i < M; i++) {
        adjMatrix[i] = new weight_t[M];
    }
    vertices = new tag_t[M];
}

Graph::Graph(int nodos): M(nodos),
    num_vertices(0),
    num_aristas(0),
    adjMatrix(NULL),
    vertices(NULL)
{
    adjMatrix = new weight_t*[M];
    for (int i = 0; i < M; i++) {
        adjMatrix[i] = new weight_t[M];
    }
    vertices = new tag_t[M];
}

Graph::~Graph()
{
    for (int i = 0; i < M; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] vertices;
}

Graph::vertex_t Graph::addVertex(string tag)
{
    if (num_vertices == M) {
        return -1;
    }

    // Insertar el nuevo tag al final
    vertices[num_vertices] = tag;

    // El nuevo vértice se inserta sin conexiones
    // (peso de 0)
    for (int it = 0; it < num_vertices; it++) {
        adjMatrix[it][num_vertices] = 0;
        adjMatrix[num_vertices][it] = 0;
    }
    adjMatrix[num_vertices][num_vertices] = 0;

    // La posición del nuevo vértice es la última, y luego
    // se aumenta el contador de vértices.
    return num_vertices++;
}

bool Graph::removeVertex(vertex_t v)
{
    return false;
}

bool Graph::addEdge(vertex_t source, vertex_t dest, weight_t weight)
{
    if (source >= 0 && dest >= 0 && source < num_vertices && dest < num_vertices) {
        if (source == dest) {
            std::cerr << "No se permiten lazos!" << std::endl;
            return false;
        }
        if (!weight) {
            std::cerr << "Peso invalido" << endl;
            return false;
        }
        adjMatrix[source][dest] = weight;
        num_aristas++;
        return true;
    }
    return false;
}

bool Graph::addEdgeBidir(vertex_t source, vertex_t dest, weight_t weight)
{
    if (source >= 0 && dest >= 0 && source < num_vertices && dest < num_vertices) {
        if (source == dest) {
            std::cerr << "No se permiten lazos!" << std::endl;
            return false;
        }
        if (!weight) {
            std::cerr << "Peso invalido" << endl;
            return false;
        }
        adjMatrix[source][dest] = weight;
        adjMatrix[dest][source] = weight;
        num_aristas+=2;
        return true;
    }
    return false;
}

Graph::weight_t* Graph::getNeighbors(vertex_t v) const
{
    return adjMatrix[v];
}

bool Graph::isEdge(vertex_t source, vertex_t dest) const
{
    if (source >= 0 && dest >= 0 && source < num_vertices && dest < num_vertices)
        return (bool)adjMatrix[source][dest];
    return false;
}

Graph::weight_t Graph::getEdge(vertex_t source, vertex_t dest) const
{
    if (source >= 0 && dest >= 0 && source < num_vertices && dest < num_vertices)
        return adjMatrix[source][dest];
    return 0;
}

int Graph::order() const
{
    return num_vertices;
}

int Graph::size() const
{
    return num_aristas;
}

void Graph::print() const
{
    std::cout << "Grafo con " << num_vertices
        << " vertices y " <<  num_aristas
        << " aristas" << endl;

    std::cout << "Lista de vértices:" << endl;
    for (int it1 = 0; it1 < num_vertices; it1++) {
        std::cout << vertices[it1] << " "; 
    }
    std::cout << endl;

    std::cout << "Matriz de adyacencia:" << endl;
    for (int it1 = 0; it1 < num_vertices; it1++) {
        for (int it2 = 0; it2 < num_vertices; it2++) {
            std::cout << std::setprecision(3)
                        << std::setfill(' ')
                        << std::setw(3)
                        << adjMatrix[it1][it2] << " ";
        }
        std::cout << std::endl;
    }

}
