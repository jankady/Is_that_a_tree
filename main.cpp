
#include <fstream>
#include <iostream>
#include <sstream>

#include "Graph.h"


// strom je souvisly a acyklicky graf + jeste E = V - 1,
// taky nemuze mit smycku

int main() {
    // std::cout << "Hello, World!" << std::endl;
    std::string line;
    std::ifstream graph1("./graph1.txt");

    if (!graph1.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }
    Graph g(20);

    for (int i = 0; i <= 13; i++) { // create 14 vertices
        g.createVertex(i);
    }

    while (getline(graph1, line)) {
        std::istringstream iss(line); // oddeluje pezerou
        int vertex1Value, vertex2Value;
        iss >> vertex1Value >> vertex2Value;
        // std::cout << vertex1Value << " " << vertex2Value << std::endl;
        g.addEdge(vertex1Value, vertex2Value);
    }
    graph1.close();


    g.printGraph();
    if (g.isTree()) {
        std::cout << "Graph is a tree." << std::endl;
    } else {
        std::cout << "Graph is not a tree." << std::endl;
    }
    return 0;
}