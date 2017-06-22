#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

using namespace std;
class Graph {
    public:

        typedef int vertex_t;
        typedef std::pair<vertex_t, vertex_t> edge_t;
        typedef int weight_t;
        typedef string tag_t;

        /**
         * Constructor por defecto (Iniciar).
         * Inicia el grafo con cero vértices y un tamaño
         * máximo de 100.
         */
        Graph();

        /**
         * Constructor que recibe el numero máximo de vertices.
         * Reserva la memoria necesaria e inicializa
         * la matriz de adyacencia con todos los
         * vertices desconectados, es decir Xij = inf.
         */
        Graph(int nodes);

        /**
         * Desctructor por defecto (Destruir).
         */
        virtual ~Graph();

        /**
         * Indica si el grafo se encuentra vacío.
         * @return Verdadero si no hay vértices en el grafo.
         */
        bool Vacio();

        /**
         * Elimina todos los vértices y aristas del grafo.
         */
        void Vaciar();

        /**
         * Agrega un nuevo vertice al grafo.
         * @return El índice del vértice en la
         * matriz de adyacencia.
         */
        vertex_t addVertex(tag_t etiq);

        /**
         * Elimina un vertice del grafo.
         * @param v El vértice en la matriz de adyacencia.
         * @return True si la operación tiene éxito
         */
        bool EliminarVertice(vertex_t v);

        /**
         * Modifica la etiqueta de un vértice del grafo.
         * @param v El vértice a modificar.
         * @param etiq La nueva etiqueta.
         */
        void ModificarEtiq(vertex_t v, tag_t etiq);

        /**
         * Obtiene la etiqueta de un vértice del grafo.
         * @param v Un vértice del grafo.
         * @return La etiqueta de \p v.
         */
        tag_t Etiqueta(vertex_t v);

        /**
         * Agrega una arista dirigida al grafo.
         * @param source Vértice origen.
         * @param dest Vértice destino.
         * @param weight Peso de la arista.
         * @return True si la operación tiene éxito.
         */
        bool addEdge(vertex_t source, vertex_t dest, weight_t weight);

        /**
         * Agrega una arista no dirigida al grafo.
         * Equivalente a invocar addEdge(source, dest, weight) addEdge(dest, source, weight).
         * @param source Vértice origen.
         * @param dest Vértice destino.
         * @param weight Peso de la arista.
         * @return True si la operación tiene éxito.
         */
        bool addEdgeBidir(vertex_t source, vertex_t dest, weight_t weight);

        /**
         * Retorna las conexiones de un vertice
         * en forma de un vector de pesos a otros
         * nodos.
         * @param v Índice del vértice en la matríz de
         * adyacencia.
         * @return Lista de pesos.
         */
        weight_t* getNeighbors(vertex_t v) const;

        /**
         * Determina si existe un arco de
         * un vértice a otro.
         * Existe un arco de source a dest
         * si el peso en la matríz es adyacencia
         * es finito.
         * @param source Vértice fuente.
         * @param dest Vértice destino.
         * @return True si existe.
         */
        bool isEdge(vertex_t source, vertex_t dest) const;

        /**
         * Obtiene el peso de la arista que va
         * desde source a dest.
         * @param source Fuente.
         * @param dest Destino.
         * @Return Peso de la conexión.
         */
        weight_t getEdge(vertex_t source, vertex_t dest) const;

        /**
         * Retorna el orden del grafo.
         * @return El numero de vertices.
         */
        int order() const;

        /**
         * Retorna el tamano del grafo.
         * @return El numero de aristas.
         */
        int size() const;

        /**
         * Imprime la representacion del grafo.
         * En este caso, imprime la matriz de
         * adyacencia.
         */
        void print() const;

    private:
        int M;
        int num_vertices;
        int num_aristas;

        typedef weight_t** matrix_t;
        matrix_t adjMatrix;
        tag_t* vertices;

        
        //typedef std::vector<std::vector<double>> matrix_type;

        //std::vector<std::vector<double>> adjMatrix; /**<Matriz de adyacencia que representa al grafo.*/

};

#endif
