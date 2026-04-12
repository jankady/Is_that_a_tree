//
// Created by Jan Kaduch on 12.04.2026.
//

#include "Vertex.h"

Vertex::Vertex(int id, int val) {
    this->id = id;
    this->value = val;
}

int Vertex::getValue() {
    return this->value;
}

int Vertex::getId() {
    return this->id;
}