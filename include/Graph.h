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

        /** Definicion de vértice nulo */
        static const vertex_t V_NULL = -1; 

        /**
         * Constructor por defecto (Iniciar).
         * Inicia el grafo con cero vértices y un tamaño
         * máximo de 100.
         */
        Graph();

        /**
         * Constructor que recibe el numero máximo de vértices.
         * Reserva la memoria necesaria para la matriz de
         * adyacencia.
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
         * Agrega un nuevo vértice al grafo.
         * @return El índice del vértice en la
         * matriz de adyacencia.
         */
        vertex_t AgregarVertice(tag_t etiq);

        /**
         * Elimina un vértice del grafo.
         * El vértice debe estar aislado.
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
        bool AgregarArista(vertex_t source, vertex_t dest, weight_t weight);

        /**
         * Elimina una arista no dirigida del grafo.
         * @param source Un vértice del grafo
         * @param dest Un vértice del grafo
         * @return True si la operación tiene éxito
         */
        bool EliminarArista(vertex_t source, vertex_t dest);

        /**
         * Retorna las conexiones de un vértice
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
        bool Adyacentes(vertex_t source, vertex_t dest) const;

        /**
         * Cambia el peso de una arista.
         * @param source Un vértice del grafo.
         * @param dest Un vértice del grafo.
         * @return True si la operación es exitosa
         */
        bool ModificarPeso(vertex_t source, vertex_t dest, weight_t peso);

        /**
         * Obtiene el peso de la arista que va desde source
         * a dest.
         * @param source Fuente.
         * @param dest Destino.
         * @Return Peso de la arista.
         */
        weight_t Peso(vertex_t source, vertex_t dest) const;

       /**
        * Retorna el índice del primer vértice del grafo o -1
        * si el grafo no tiene vértices.
        * @return Índice del vértice en la matriz de adyacencia
        */
        vertex_t PrimerVertice() const;

       /**
        * Retorna el índice del vértice siguiente del grafo o -1
        * si es el último vértice
        * @param v Un vértice del grafo.
        * @return Índice del vértice siguiente a \p v en la
        * matriz de adyacencia
        */
        vertex_t SgteVertice(vertex_t v) const;

       /**
        * Retorna el índice del primer vértice adyacente del
        * grafo o -1 si el vértice dado no tiene vértices
        * adyacentes
        * @param v_padre Un vértice del grafo.
        * @return Índice del vértice en la matriz de adyacencia
        */
        vertex_t PrimerVertAd(vertex_t v_padre) const;

       /**
        * Retorna el índice del vértice adyacente siguiente del
        * grafo o -1 si es el último vértice adyacente al primer
        * vértice dado.
        * @param v_padre Un vértice del grafo.
        * @param v_hermano Un vértice del grafo que es vecino
        * de \p v_padre.
        * @return Índice del vértice vecino a \p v_padre
        * siguiente a \p v_hermano en la matriz de adyacencia
        */
        vertex_t SgteVertAd(vertex_t v_padre, vertex_t v_hermano) const;

        /**
         * Retorna el orden del grafo.
         * @return El numero de vértices.
         */
        int NumVertices() const;

        /**
         * Retorna el numero de vértices adyacentes a
         * un vértice.
         * @param v Un vértice del grafo.
         * @return El numero de vértices adyacentes a \p v.
         */
        int NumVertAd(vertex_t v) const;


        /**
         * Retorna el tamaño del grafo.
         * @return El número de aristas.
         */
        int size() const;

        /**
         * Imprime la representación del grafo.
         * En este caso, imprime la matriz de adyacencia.
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
