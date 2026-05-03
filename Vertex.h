/**
 * @file Vertex.h
 * @brief Deklarace třídy Vertex reprezentující jeden uzel(Node) grafu.
 *
 * @author Jan Kaduch
 * @date 12.04.2026
 * @version 1.0
 */

#ifndef IS_THAT_A_TREE_NODE_H
#define IS_THAT_A_TREE_NODE_H

/**
 * @class Vertex
 * @brief Reprezentuje jeden vrchol neorientovaného grafu.
 *
 * Každý vrchol má:
 * - **id** – interní index přiřazený sekvenčně při vytvoření (používá se jako
 *   index do matice sousednosti).
 * - **value** – uživatelský štítek, podle kterého se vrchol identifikuje
 *   zvenčí grafu.
 *
 */
class Vertex {
private:
    int id;     ///< Interní nulový index používaný pro adresování matice sousednosti.
    int value;  ///< Uživatelová celočíselná hodnota vrcholu.

public:
    /**
     * @brief Vytvoří vrchol se zadaným id a hodnotou.
     * @param[in] id   Interní sekvenční index přiřazený třídou Graph.
     * @param[in] val  Uživatelova celočíselná hodnota vrcholu.
     */
    Vertex(int id, int val);

    /**
     * @brief Vrátí hodnotu vrcholu.
     * @return Celočíselná hodnota vrcholu.
     */
    int getValue();

    /**
     * @brief Vrátí interní index vrcholu.
     * @return Nulový index do matice sousednosti.
     */
    int getId();
};

#endif //IS_THAT_A_TREE_NODE_H