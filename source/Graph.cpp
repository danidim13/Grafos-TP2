#include "Graph.h"
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

bool Graph::Vacio()
{
    return num_vertices == 0;
}

void Graph::Vaciar()
{
    num_vertices = 0;
    num_aristas = 0;
}


Graph::vertex_t Graph::AgregarVertice(tag_t etiq)
{
    if (num_vertices == M) {
        return -1;
    }

    // Insertar el nuevo tag al final
    vertices[num_vertices] = etiq;

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

bool Graph::EliminarVertice(vertex_t v)
{
    if (v >= 0 && v < num_vertices) {

        // Se cuentan los vértices que salen de v
        // y que van hacia v
        int aristas = 0;
        for (int i = 0; i < num_vertices; i++) {
            aristas = adjMatrix[v][i] ? aristas + 1 : aristas;
            aristas = adjMatrix[i][v] ? aristas + 1 : aristas;
        }
        num_aristas -= aristas;

        // Se corren todos los valores que vayan despues de
        // v en la matriz de adyacencia
        for (int i = 0; i < num_vertices; i++) {
            for (int j = v; j < num_vertices-1; j++) {
            adjMatrix[i][j] = adjMatrix[i][j+1];
            }
        }
        for (int i = 0; i < num_vertices; i++) {
            for (int j = v; j < num_vertices-1; j++) {
            adjMatrix[j][i] = adjMatrix[j+1][i];
            }
        }

        // Se corren todos los vértices que vayan despues
        // de v en la lista de vértices
        for (int j = v; j < num_vertices-1; j++) {
            vertices[j] = vertices[j+1];
        }
        num_vertices--;
        return true;
    }
    return false;
}

void Graph::ModificarEtiq(vertex_t v, tag_t etiq)
{
    if (v >= 0 && v < num_vertices)
        vertices[v] = etiq;
}

Graph::tag_t Graph::Etiqueta(vertex_t v)
{
    if (v >= 0 && v < num_vertices)
        return vertices[v];
    else
        return "";
}

bool Graph::addEdge(vertex_t source, vertex_t dest, weight_t weight)
{
    if (source >= 0 && dest >= 0 && source < num_vertices && dest < num_vertices) {
        if (source == dest) {
            cerr << "No se permiten lazos!" << endl;
            return false;
        }
        if (!weight) {
            cerr << "Peso invalido" << endl;
            return false;
        }
        if (adjMatrix[source][dest]) {
            cerr << "Ya existe una arista" << endl;
            return false;
        }
        adjMatrix[source][dest] = weight;
        num_aristas++;
        return true;
    }
    return false;
}

bool Graph::AgregarArista(vertex_t source, vertex_t dest, weight_t weight)
{
    if (source >= 0 && dest >= 0 && source < num_vertices && dest < num_vertices) {
        if (source == dest) {
            cerr << "No se permiten lazos!" << endl;
            return false;
        }
        if (!weight) {
            cerr << "Peso invalido" << endl;
            return false;
        }
        if (adjMatrix[source][dest] || adjMatrix[dest][source]) {
            cerr << "Ya existe una arista" << endl;
            return false;
        }
        adjMatrix[source][dest] = weight;
        adjMatrix[dest][source] = weight;
        num_aristas+=2;
        return true;
    }
    return false;
}

bool Graph::EliminarArista(vertex_t source, vertex_t dest) {
    if (source >= 0 && dest >= 0 && source < num_vertices && dest < num_vertices) {
        if (adjMatrix[source][dest] && adjMatrix[dest][source]) {
            adjMatrix[source][dest] = 0;
            adjMatrix[dest][source] = 0;
            num_aristas -= 2;
            return true;
        } else {
            cerr << "No existe la arista que se intentó borrar" << endl;
            return false;
        }
    }
    return false;
}

Graph::weight_t* Graph::getNeighbors(vertex_t v) const
{
    return adjMatrix[v];
}

bool Graph::Adyacentes(vertex_t source, vertex_t dest) const
{
    if (source >= 0 && dest >= 0 && source < num_vertices && dest < num_vertices)
        return (bool)adjMatrix[source][dest];
    return false;
}

bool Graph::ModificarPeso(vertex_t source, vertex_t dest, weight_t peso)
{
    if (!peso) {
        cerr << "Peso inválido" << endl;
        return false;
    }

    if (source >= 0 && dest >= 0 && source < num_vertices && dest < num_vertices) {
        if (adjMatrix[source][dest] && adjMatrix[dest][source]) {
            adjMatrix[source][dest] = peso;
            adjMatrix[dest][source] = peso;
            return true;
        }
    }
    return false;
}

Graph::weight_t Graph::Peso(vertex_t source, vertex_t dest) const
{
    if (source >= 0 && dest >= 0 && source < num_vertices && dest < num_vertices)
        return adjMatrix[source][dest];
    return 0;
}

Graph::vertex_t Graph::PrimerVertice() const
{
    if (num_vertices > 0)
        return 0;
    else
        return V_NULL;
}

Graph::vertex_t Graph::SgteVertice(vertex_t v) const
{
    if (v < num_vertices-1)
        return v+1;
    else
        return V_NULL;
}

Graph::vertex_t Graph::PrimerVertAd(vertex_t v_padre) const
{
    for (int i = 0; i < num_vertices; i++) {
        if (adjMatrix[v_padre][i]) {
            return i;
        }
    }
    return V_NULL;
}

Graph::vertex_t Graph::SgteVertAd(vertex_t v_padre, vertex_t v_hermano) const
{
    for (int i = v_hermano + 1; i < num_vertices; i++) {
        if (adjMatrix[v_padre][i]){
            return i;
        }
    }
    return V_NULL;
}

int Graph::NumVertices() const
{
    return num_vertices;
}

int Graph::NumVertAd(vertex_t v) const
{
    int cuenta = 0;
    for (int i = 0; i < num_vertices; i++) {
        cuenta = adjMatrix[v][i] ? cuenta + 1 : cuenta;
    }
    return cuenta;
}

int Graph::size() const
{
    return num_aristas;
}

void Graph::print() const
{
    cout << endl;
    cout << "Grafo con " << num_vertices
        << " vertices y " <<  num_aristas
        << " aristas" << endl;

    cout << "Lista de vértices:" << endl;
    for (int it1 = 0; it1 < num_vertices; it1++) {
        cout << vertices[it1] << " "; 
    }
    cout << endl;

    cout << "Matriz de adyacencia:" << endl;

    cout << "    ";
    for (int it1 = 0; it1 < num_vertices; it1++) {
        cout << std::setfill(' ')
                    << std::setw(3)
                    << vertices[it1] << " ";
    }
    cout << endl;

    for (int it1 = 0; it1 < num_vertices; it1++) {
        cout << std::setfill(' ')
                    << std::setw(3)
                    << vertices[it1] << " ";
        for (int it2 = 0; it2 < num_vertices; it2++) {
            cout << std::setprecision(3)
                        << std::setfill(' ')
                        << std::setw(3)
                        << adjMatrix[it1][it2]  << " ";
        }
        cout << endl;
    }
    cout << endl;

}
