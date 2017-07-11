#include <iostream>
#include "include/Graph.h"
#include "include/Algoritmos.h"

using namespace std;

int main(int argc, char *argv[]) {

	cout << "Hello World!" << endl;
    Graph G;
    Graph::vertex_t va = G.AgregarVertice("A");
    Graph::vertex_t vb = G.AgregarVertice("B");
    Graph::vertex_t vc = G.AgregarVertice("C");
    Graph::vertex_t vd = G.AgregarVertice("D");
    Graph::vertex_t ve = G.AgregarVertice("E");
    Graph::vertex_t vf = G.AgregarVertice("F");

    G.AgregarArista(va, vb, 2);
    G.AgregarArista(va, ve, 3);
    G.AgregarArista(va, vf, 2);

    G.AgregarArista(vb, vc, 3);
    G.AgregarArista(vb, vd, 2);
    G.AgregarArista(vb, vf, 8);

    G.AgregarArista(vc, vd, 5);

    G.AgregarArista(vd, vf, 30);

    G.AgregarArista(ve, vb, 1);
    G.AgregarArista(ve, vc, 10);
    G.AgregarArista(ve, vd, 20);

    G.AgregarArista(vf, ve, 8);

    G.print();

    /*cout << "Eliminando una arista" << endl;
    G.EliminarArista(vd, vc);
    G.EliminarArista(vd, vc);
    G.print();

    cout << "Eliminando un vértice" << endl;
    G.EliminarVertice(vb);
    G.print();
    */

    /*
    cout << "Recorriendo vértices" << endl;
    Graph::vertex_t it;
    it = G.PrimerVertice();
    while (it != Graph::V_NULL) {
        cout << "Vertice: " << it
            << "\t Tag: " << G.Etiqueta(it) << endl;
        cout << "\tVecinos: {" << endl;
        Graph::vertex_t it2 = G.PrimerVertAd(it);
        while (it2 != Graph::V_NULL) {
        cout << "\t\tVertice: " << it2
            << "\t Tag: " << G.Etiqueta(it2) << endl;
        it2 = G.SgteVertAd(it,it2);
        }
        cout << "\t}" << endl;
        it = G.SgteVertice(it);
    }
    */

    /*
    cout << endl;
    cout << "Eliminando un vértice no aislado" << endl;
    EliminarVert(G, ve);
    G.print();
    */

    cout << "---------------------------" << endl;
    cout << "Probando algoritmo de floyd" << endl;
    Floyd(G);
    cout << endl;

    cout << "---------------------------" << endl;
    cout << "Probando algoritmo de coloreo" << endl;
    ColorGraph(G);

    cout << "---------------------------" << endl;
    cout << "Eliminando un vértice no aislado" << endl;
    cout << "Eliminando " << G.Etiqueta(ve);
    EliminarVert(G, ve);
    G.print();

	return 0;
}
