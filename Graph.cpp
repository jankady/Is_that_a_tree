//
// Created by Jan Kaduch on 12.04.2026.
//

#include "Graph.h"
#include "Vertex.h"

Graph::Graph(int v) {
    this->vertexes = new Vertex[v];
    this->edges = new int*[v];
    for (int i = 0; i < v; i++) { // matrix
        this->edges[i] = new int[v];
        for (int j = 0; j < v; j++) {
            this->edges[i][j] = -1;
        }
    }
    this->vertexCount = 0;
    this->edgeCount = 0;
    this->maxVertexCount = v;
}