
#include <fstream>
#include <iostream>

#include "Graph.h"


// strom je souvisly a acyklicky graf + jeste E = V - 1,
// taky nemuze mit smycku

int main() {
    // std::cout << "Hello, World!" << std::endl;
    std::string line;
    std::ifstream graph1("graph1.txt");

    Graph g(20);

    for (int i = 1; i <= 13; i++) { // create 13 vertices
        g.createVertex(i);
    }

    while (getline( graph1, line)) {

        int vertex1Value = line[0] - '0';
        int vertex2Value = line[2] - '0';
        g.addEdge(vertex1Value, vertex2Value);
    }
    graph1.close();



    g.printGraph();
    return 0;
}