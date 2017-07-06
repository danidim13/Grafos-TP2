#include <iostream>
#include "include/Graph.h"

using namespace std;

int main(int argc, char *argv[]) {

	cout << "Hello World!" << endl;
    Graph G;
    Graph::vertex_t va = G.AgregarVertice("A");
    Graph::vertex_t vb = G.AgregarVertice("B");
    Graph::vertex_t vc = G.AgregarVertice("C");
    Graph::vertex_t vd = G.AgregarVertice("D");
    Graph::vertex_t ve = G.AgregarVertice("E");

    G.AgregarArista(va, ve, 5);
    G.AgregarArista(vb, ve, 6);
    G.AgregarArista(vc, vd, -1);
    G.AgregarArista(vd, ve, 21);

    G.print();

    /*cout << "Eliminando una arista" << endl;
    G.EliminarArista(vd, vc);
    G.EliminarArista(vd, vc);
    G.print();

    cout << "Eliminando un vértice" << endl;
    G.EliminarVertice(vb);
    G.print();
    */

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
	return 0;
}
