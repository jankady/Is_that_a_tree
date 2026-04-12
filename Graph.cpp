//
// Created by Jan Kaduch on 12.04.2026.
//

#include "Graph.h"

#include <iostream>

#include "Vertex.h"

Graph::Graph(int v) {
    this->vertexes = new Vertex*[v];
    for (int i = 0; i < v; i++) {
        this->vertexes[i] = nullptr;
    }

    this->edges = new int*[v];
    for (int i = 0; i < v; i++) { // matrix
        this->edges[i] = new int[v];
        for (int j = 0; j < v; j++) {
            this->edges[i][j] = 0;
        }
    }
    this->vertexCount = 0;
    this->edgeCount = 0;
    this->maxVertexCount = v;
}

Graph::~Graph() {
    for (int i = 0; i < this->maxVertexCount; i++) {
        delete this->vertexes[i];
    }
    delete[] this->vertexes;

    for (int i = 0; i < this->maxVertexCount; i++) {
        delete[] this->edges[i];
    }
    delete[] this->edges;
}

int Graph::getVertexIndexFromValue(int vertexValue) {
    for (int i = 0; i < this->vertexCount; i++) {
        if (this->vertexes[i] == nullptr) {
            break;
        }
        if (this->vertexes[i]->getValue() == vertexValue) {
            return this->vertexes[i]->getId();
        }
    }
    std::cout << "Vertex with value " << vertexValue << " was not found." << std::endl;
    return -1; // not found
}

int Graph::getVertexCount() {
    return this->vertexCount;
}

int Graph::getEdgeCount() {
    return this->edgeCount;
}

Vertex* Graph::createVertex(int value) {
    if (this->vertexCount >= this->maxVertexCount) {
        std::cout << "Max vertex count reached, cannot create more vertexes." << std::endl;
        return nullptr;
    }
    Vertex* newVertex = new Vertex(this->vertexCount, value);
    this->vertexes[this->vertexCount] = newVertex;
    this->vertexCount++;
    return newVertex;
}

void Graph::addEdge(int vertex1Value, int vertex2Value) {

    int vertex1 = this->getVertexIndexFromValue(vertex1Value);
    int vertex2 = this->getVertexIndexFromValue(vertex2Value);
    if (vertex1 == -1 ) {
        std::cout << "Cannot add edge vertex 1 does not exist" << std::endl;
        return;
    }
    if (vertex2 == -1 ) {
        std::cout << "Cannot add edge vertex 2 does not exist" << std::endl;
        return;
    }

    if (this->edges[vertex1][vertex2] == 0) { // prevent duplicate edges
        this->edges[vertex1][vertex2] = 1;
        this->edges[vertex2][vertex1] = 1; // undirected graph
        this->edgeCount++;
    }
}