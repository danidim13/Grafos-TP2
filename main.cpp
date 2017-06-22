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

    cout << "Eliminando una arista" << endl;
    G.EliminarArista(vd, vc);
    G.EliminarArista(vd, vc);
    G.print();

    cout << "Eliminando un vértice" << endl;
    G.EliminarVertice(vb);
    G.print();
	return 0;
}
