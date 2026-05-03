/**
 * @file Vertex.cpp
 * @brief Implementace třídy Vertex.
 *
 * @author Jan Kaduch
 * @date 12.04.2026
 * @version 1.0
 */

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