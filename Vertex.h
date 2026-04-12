//
// Created by Jan Kaduch on 12.04.2026.
//

#ifndef IS_THAT_A_TREE_NODE_H
#define IS_THAT_A_TREE_NODE_H


class Vertex {
private:
    int id;
    int value;

public:
    Vertex(int id, int val);

    int getValue();
    int getId();

};


#endif //IS_THAT_A_TREE_NODE_H