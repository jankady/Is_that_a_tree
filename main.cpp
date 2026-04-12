
#include <iostream>

#include "Graph.h"


// strom je souvisly a acyklicky graf + jeste E = V - 1,
// taky nemuze mit smycku

int main() {
    // std::cout << "Hello, World!" << std::endl;

    Graph g(5);
    g.createVertex(4);
    g.createVertex(10);
    g.createVertex(15);

    g.addEdge(4, 10);
    g.addEdge(10, 15);
    g.addEdge(15, 15);

    g.printGraph();
    return 0;
}