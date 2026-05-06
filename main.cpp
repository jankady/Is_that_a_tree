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
 * - **acyklický** – neobsahuje žádný cyklus,
 * - **bez smyček** – žádný vrchol neukazuje sám na sebe.
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
 * Detekce stromu probíhá ve třech krocích:
 * -# **Kontrola počtu hran:** Graf musí mít přesně V-1 hran.
 *    Nejrychlejší test – zahodí evidentně špatné grafy bez dalšího procházení.
 * -# **Kontrola smyček:** Pro každý vrchol projde jeho seznam sousedů a hledá výskyt sebe sama.
 *    Smyčka (hrana vrcholu na sebe sama) ihned diskvalifikuje strom.
 * -# **Kontrola spojitosti:** Iterativní DFS od vrcholu 0 ověří,
 *    že jsou všechny vrcholy dosažitelné.
 *
 * @section usage_sec Použití
 * Vstupní soubory jsou uloženy ve složce `./testCases/`.
 * Každý řádek souboru obsahuje dvojici čísel – hodnoty vrcholů hrany.
 *
 * @section files_sec Soubory projektu
 * - main.cpp   – vstupní bod, testování grafů ze souborů
 * - Graph.h / Graph.cpp – třída grafu a algoritmus isTree()
 * - Vertex.h / Vertex.cpp – třída reprezentující jeden vrchol
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Graph.h"

/// Maximální počet vrcholů, které graf může obsahovat.
constexpr int MAX_VERTICES = 20;

/**
 * @brief Načte graf ze souboru, vypíše ho a otestuje, zda je stromem.
 *
 * @details
 * Vytvoří nový graf s @p vertexCount vrcholy (hodnoty 0 až vertexCount-1),
 * načte hrany ze souboru @p filename a zavolá isTree().
 *
 * @param[in] filename     Cesta k souboru s hranami.
 * @param[in] vertexCount  Počet vrcholů grafu (hodnoty 0 až vertexCount-1).
 */
void testGraph(const std::string& filename, int vertexCount) {
    std::cout << "========================================" << std::endl;
    std::cout << "Testing: " << filename << std::endl;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }

    Graph g(MAX_VERTICES);
    for (int i = 0; i < vertexCount; i++) {
        g.createVertex(i);
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        int vertex1Value, vertex2Value;
        iss >> vertex1Value >> vertex2Value;
        g.addEdge(vertex1Value, vertex2Value);
    }
    file.close();

    g.printGraph();
    if (g.isTree()) {
        std::cout << "Result: Graph IS a tree." << std::endl;
    } else {
        std::cout << "Result: Graph is NOT a tree." << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Vstupní bod programu – spustí testy pro všechny testovací soubory.
 *
 * @return 0 při úspěchu.
 */
int main() {
    testGraph("./testCases/graph1.txt", 14);
    testGraph("./testCases/graph2.txt", 14);
    testGraph("./testCases/graph3.txt", 14);
    testGraph("./testCases/graph4.txt", 14);
    return 0;
}
