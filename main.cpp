#include <iostream>
#include "include/Graph.h"

using namespace std;

int main(int argc, char *argv[]) {

	cout << "Hello World!" << endl;
    Graph G;
    Graph::vertex_t va = G.addVertex("A");
    Graph::vertex_t vb = G.addVertex("B");
    Graph::vertex_t vc = G.addVertex("C");
    Graph::vertex_t vd = G.addVertex("D");
    Graph::vertex_t ve = G.addVertex("E");

    G.addEdgeBidir(va, ve, 5);
    G.addEdgeBidir(vb, ve, 6);
    G.addEdgeBidir(vc, vd, -1);
    G.addEdgeBidir(vd, ve, 21);

    G.print();

    G.EliminarVertice(ve);
    G.print();
	return 0;
}
