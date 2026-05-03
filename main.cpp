/**
 * @file main.cpp
 * @brief Začátek programu, načte graf ze souboru a otestuje, zda je stromem.
 *
 * @details
 * ### Formát vstupního souboru
 * Každý řádek obsahuje dvě celá čísla oddělená mezerou,
 * která představují čísla dvou vrcholů hrany:
 * @code
 * 0 1
 * 1 2
 * 2 3
 * @endcode
 *
 * ### Co je strom?
 * Neorientovaný graf je **stromem**, pokud je:
 * - **spojitý** – z každého vrcholu se lze dostat do každého jiného,
 * - **acyklický** – neobsahuje žádný cyklus.
 *
 * Ekvivalentně: graf s V vrcholy je stromem právě tehdy, když je spojitý
 * a má přesně V-1 hran.
 *
 * @author Jan Kaduch
 * @date 12.04.2026
 * @version 1.0
 *
 * @mainpage Is That a Tree?
 *
 * @section intro_sec Úvod
 * Tento program rozhoduje, zda zadaný neorientovaný graf je stromem.
 *
 * @section algo_sec Algoritmus
 * Detekce stromu probíhá ve dvou krocích:
 * -# **Kontrola počtu hran:** Graf musí mít přesně V-1 hran.
 *    Podmínka E = V-1 zaručuje acykličnost u spojitého grafu.
 * -# **Kontrola spojitosti:** Iterativní DFS od vrcholu 0 ověří,
 *    že jsou všechny vrcholy dosažitelné.
 *
 * Pokud jsou obě podmínky splněny, graf je stromem.
 *
 * @section usage_sec Použití
 * Vstupní soubor s hranami se předává jako `./testCases/graph1.txt`.
 * Každý řádek obsahuje dvojici čísel – štítky vrcholů hrany.
 *
 * @section files_sec Soubory projektu
 * - main.cpp   – vstupní bod, načítání grafu ze souboru
 * - Graph.h / Graph.cpp – třída grafu a algoritmus isTree()
 * - Vertex.h / Vertex.cpp – třída reprezentující jeden vrchol
 */

#include <fstream>
#include <iostream>
#include <sstream>

#include "Graph.h"

/// Maximální počet vrcholů, které graf může obsahovat.
constexpr int MAX_VERTICES = 20;

/**
 * @brief Vstupní bod programu.
 *
 * @details
 * Načte graf ze souboru `./testCases/graph1.txt`, vypíše jeho strukturu
 * a oznámí, zda je graf stromem.
 *
 * @return 0 při úspěchu, 1 pokud nelze otevřít vstupní soubor.
 */
int main() {
    std::string line;
    std::ifstream graph1("./testCases/graph1.txt");

    if (!graph1.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    Graph g(MAX_VERTICES);

    for (int i = 0; i < 14; i++) {
        g.createVertex(i);
    }

    while (getline(graph1, line)) {
        std::istringstream iss(line);
        int vertex1Value, vertex2Value;
        iss >> vertex1Value >> vertex2Value;
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
