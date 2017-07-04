#ifndef LISTALISTAS_H
#define LISTALISTAS_H
#include "ListaAristas.h"
#include "ListaVertices.h"

class NodoVertice;
class NodoArista;

class ListaListas
{
public:
    typedef int peso;
    typedef string tag;

    typedef  NodoVertice vertice;
    typedef  NodoArista arista;
    int num_vertices;
    int num_aristas;

    /**
    * Constructor por defecto (Iniciar).
    * Inicia el grafo con cero vértices
    */
    ListaListas();

    /**
    * Desctructor por defecto (Destruir).
    */
    virtual ~ListaListas();

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
     * lista de listas
     */
    vertice AgregarVertice(tag etiq);

    /**
    * Elimina un vertice del grafo.
    * @param v El vértice en la lista de listas
    * @return True si la operación tiene éxito
    */
    bool EliminarVertice(vertice v);

    /**
     * Modifica la etiqueta de un vértice del grafo.
     * @param v El vértice a modificar.
     * @param etiq La nueva etiqueta.
     */
    void ModificarEtiq(vertice v, tag etiq);

    /**
    * Obtiene la etiqueta de un vértice del grafo.
    * @param v Un vértice del grafo.
    * @return La etiqueta de \p v.
    */
    tag Etiqueta(vertice v);

    /**
     * Agrega una arista dirigida al grafo.
     * @param source Vértice origen.
     * @param dest Vértice destino.
     * @param weight Peso de la arista.
     * @return True si la operación tiene éxito.
     */
    bool agregarArista(vertice source, vertice dest, peso weight);

    /**
    * Agrega una arista no dirigida al grafo.
    * Equivalente a invocar addEdge(source, dest, weight) addEdge(dest, source, weight).
    * @param source Vértice origen.
    * @param dest Vértice destino.
    * @param weight Peso de la arista.
    * @return True si la operación tiene éxito.
    */
    bool AgregarArista(vertice source, vertice dest, peso weight);

    /**
    * Elimina una arista no dirigida del grafo.
    * @param source Un vértice del grafo
    * @param dest Un vértice del grafo
    * @return True si la operación tiene éxito
    */
    bool EliminarArista(vertice source, vertice dest);


    /**
     * Determina si existe un arco de
     * un vértice a otro.
     * @param source Vértice fuente.
     * @param dest Vértice destino.
     * @return True si existe.
     */
    bool Adyacentes(vertice source, vertice dest) const;

    /**
    * Cambia el peso de una arista.
    * @param source Un vértice del grafo.
    * @param dest Un vértice del grafo.
    * @return True si la operación es exitosa
    */
    bool ModificarPeso(vertice source, vertice dest, peso p);

    /**
     * Obtiene el peso de la arista que va desde source
     * a dest.
     * @param source Fuente.
     * @param dest Destino.
     * @Return Peso de la arista.
     */
    peso ObtenerPeso(vertice source, vertice dest) const;

    /**
    * Retorna el índice del primer vértice del grafo o -1
    * si el grafo no tiene vértices.
    * @return Índice del vértice en la lista de listas
    */
    vertice PrimerVertice() const;

    /**
    * Retorna el índice del vértice siguiente del grafo o -1
    * si es el último vértice
    * @param v Un vértice del grafo.
    * @return Índice del vértice siguiente a \p v en la
    * lista de listas
    */
    vertice SgteVertice(vertice v) const;

    /**
    * Retorna el índice del primer vértice adyacente del
    * grafo o -1 si el vértice dado no tiene vértices
    * adyacentes
    * @param v_padre Un vértice del grafo.
    * @return Índice del vértice en la lista de listas
    */
    vertice PrimerVertAd(vertice v_padre) const;

    /**
    * Retorna el índice del vértice adyacente siguiente del
    * grafo o -1 si es el último vértice adyacente al primer
    * vértice dado.
    * @param v_padre Un vértice del grafo.
    * @param v_hermano Un vértice del grafo que es vecino
    * de \p v_padre.
    * @return Índice del vértice vecino a \p v_padre
    * siguiente a \p v_hermano en la lista de listas
    */
    vertice SgteVertAd(vertice v_padre, vertice v_hermano) const;

    /**
    * Retorna el orden del grafo.
    * @return El numero de vertices.
    */
    int NumVertices() const;

    /**
    * Retorna el numero de vértices adyacentes a
    * un vértice.
    * @param v Un vértice del grafo.
    * @return El numero de vertices adyacentes a \p v.
    */
    int NumVertAd(vertice v) const;

    /**
    * Imprime la representacion del grafo.
    * En este caso, imprime la lista de listas.
    */
    void Imprimr() const;

};

#endif // LISTALISTAS_H
