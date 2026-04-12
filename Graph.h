//
// Created by Jan Kaduch on 12.04.2026.
//

#ifndef IS_THAT_A_TREE_GRAPH_H
#define IS_THAT_A_TREE_GRAPH_H

class Vertex;

class Graph {
private:
    Vertex** vertexes;
    int** edges;
    int vertexCount;
    int edgeCount;
    int maxVertexCount;

    int getVertexIndexFromValue(int vertexValue);

public:
    Graph(int vertexCount);
    ~Graph();

    int getVertexCount();
    int getEdgeCount();

    Vertex* createVertex(int value);
    void addEdge(int vertex1Value, int vertex2Value);

    bool isTree();

    void printGraph();
};


#endif //IS_THAT_A_TREE_GRAPH_H