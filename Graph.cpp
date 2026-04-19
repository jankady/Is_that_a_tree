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
        this->edges[i] = new int[v](); // inicialiace na 0 pomoct () a ne for cyklud
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

bool Graph::isTree() {
    // Kontrola podminky E = V - 1
    if (this->edgeCount != this->vertexCount - 1) {
        std::cout << "Default condition is not satisfied" << std::endl;
        return false;
    }

    bool* visited = new bool[this->vertexCount];
    for (int i = 0; i < this->vertexCount; i++) {
        visited[i] = false;
    }
    std::stack<Vertex*> stack;
    stack.push(this->vertexes[0]);
    // DFS - pouze kontrola souvislosti (cyklus není třeba ověřovat, protože E==V-1 garantuje acykličnost u souvislého grafu)
    while (!stack.empty()) {
        Vertex* current = stack.top();
        stack.pop();
        int currentIndex = current->getId();
        if (visited[currentIndex]) {
            continue;
        }
        visited[currentIndex] = true;
        for (int i = 0; i < this->vertexCount; i++) {
            if (this->edges[currentIndex][i] == 1 && !visited[i]) {
                stack.push(this->vertexes[i]);
            }
        }
    }

    for (int i = 0; i < this->vertexCount; i++) {
       if (visited[i] == false) {
           delete[] visited;
           std::cout << "All of the verticies are not connected" <<  std::endl;
           return false; // graf neni souvisly, protoze nebyl navstiven nejaky vertex
       }
    }


    delete[] visited;
    return true;
}

void Graph::printGraph() {
    std::cout << "Graph with " << this->vertexCount << " vertexes and " << this->edgeCount << " edges." << std::endl;
    for (int i = 0; i < this->vertexCount; i++) {
        if (this->vertexes[i] != nullptr) {
            std::cout << "Vertex " << this->vertexes[i]->getId() << ": " << this->vertexes[i]->getValue() << std::endl;
        }
    }
    std::cout << "Edges:" << std::endl;
    for (int i = 0; i < this->vertexCount; i++) {
        for (int j = i ; j < this->vertexCount; j++) { // print only upper triangle of the matrix and diagonal
            if (this->edges[i][j] == 1) {
                std::cout << "Edge between vertex " << this->vertexes[i]->getValue() << " and vertex " << this->vertexes[j]->getValue() << std::endl;
            }
        }
    }
}