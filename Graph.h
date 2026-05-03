/**
 * @file Graph.h
 * @brief Deklarace třídy Graph a algoritmu pro detekci stromu.
 *
 * @author Jan Kaduch
 * @date 12.04.2026
 * @version 1.0
 */

#ifndef IS_THAT_A_TREE_GRAPH_H
#define IS_THAT_A_TREE_GRAPH_H

class Vertex;

/**
 * @class Graph
 * @brief Neorientovaný graf uložený jako matice sousednosti s podporou detekce stromu.
 *
 * @details
 * Třída spravuje pevný počet vrcholů (Vertex) a čtvercovou matici sousednosti.
 * Hlavním účelem je metoda isTree(), která v čase O(V) rozhodne, zda je graf stromem, kde V je počet vrcholů.
 *
 * ### Rozložení paměti
 * | Člen        | Typ         | Popis |
 * |-------------|-------------|-------|
 * | `vertexes`  | `Vertex**`  | Pole ukazatelů na vrcholy, indexované přes id. |
 * | `edges`     | `int**`     | Čtvercová matice; `edges[i][j] == 1` právě tehdy, když hrana {i,j} existuje. |
 *
 * @note Graf je neorientovaný – matice je symetrická (`edges[i][j] == edges[j][i]`).
 */
class Graph {
private:
    Vertex** vertexes;    ///< Pole ukazatelů na vrcholy indexované interním id.
    int**    edges;       ///< Symetrická matice sousednosti (hodnoty 0 nebo 1).
    int      vertexCount;    ///< Aktuální počet vrcholů v grafu.
    int      edgeCount;      ///< Aktuální počet neorientovaných hran v grafu.
    int      maxVertexCount; ///< Maximální kapacita určena konstruktorem.

    /**
     * @brief Vyhledá interní index vrcholu podle jeho uživatelského štítku.
     * @param[in] vertexValue  Uživatelská hodnota, kterou hledáme.
     * @return Index prvků, nebo -1 pokud vrchol neexistuje.
     */
    int getVertexIndexFromValue(int vertexValue);

public:
    /**
     * @brief Vytvoří prázdný graf se zadanou maximální kapacitou vrcholů.
     *
     * @details
     * Alokuje pole ukazatelů na vrcholy a matici sousednosti V×V,
     * přičemž všechny hodnoty jsou inicializovány na nulu.
     *
     * @param[in] vertexCount  Maximální počet vrcholů, které graf může obsahovat.
     */
    Graph(int vertexCount);

    /**
     * @brief Destruktor – uvolní veškerou dynamicky alokovanou paměť.
     *
     * @details
     * Smaže každý objekt Vertex, pole ukazatelů na vrcholy,
     * každý řádek matice sousednosti a pole ukazatelů na řádky.
     */
    ~Graph();

    /**
     * @brief Vrátí aktuální počet vrcholů v grafu.
     * @return Počet vrcholů.
     */
    int getVertexCount();

    /**
     * @brief Vrátí aktuální počet neorientovaných hran v grafu.
     * @return Počet hran.
     */
    int getEdgeCount();

    /**
     * @brief Vytvoří nový vrchol se zadanou hodnotou a přidá ho do grafu.
     *
     * @details
     * Vrchol dostane id rovné hodnotě `vertexCount` před inkrementací,
     * takže id jsou přiřazována sekvenčně od 0.
     *
     * @param[in] value  Hodnota nového vrcholu.
     * @return Ukazatel na nově vytvořený Vertex, nebo `nullptr` pokud je kapacita vyčerpána.
     */
    Vertex* createVertex(int value);

    /**
     * @brief Přidá neorientovanou hranu mezi dva vrcholy identifikované jejich hodnotou.
     *
     * @details
     * Funkce odmítne hranu ve dvou případech:
     * - **Neexistující vrchol** – některá z hodnot nebyla nalezena v grafu.
     * - **Duplicitní hrana** – hrana mezi těmito vrcholy již existuje.
     *
     * Ve zamítnutých případech graf zůstane beze změny.
     *
     * @param[in] vertex1Value  Hodnota prvního vrcholu hrany.
     * @param[in] vertex2Value  Hodnota druhého vrcholu hrany.
     */
    void addEdge(int vertex1Value, int vertex2Value);

    /**
     * @brief Zjistí, zda je graf stromem.
     *
     * @details
     * Spojitý, acyklický, neorientovaný graf s V vrcholy je stromem právě tehdy,
     * když má přesně V-1 hran. Algoritmus to využívá takto:
     *
     *
     * **Krok 1 – kontrola počtu hran:**
     * Okamžitě vrátí `false`, pokud E ≠ V-1.
     * Tato podmínka zároveň zaručuje acykličnost u spojitého grafu,
     * takže samostatná detekce cyklů není potřeba.
     *
     * **Krok 2 – kontrola spojitosti (iterativní DFS) a smyčky:**
     * Spustí prohledávání do hloubky od vrcholu 0 a ověří,
     * že každý vrchol byl navštíven.
     * Pokud `edges[i][i] == 1`,
     * vrchol ukazuje sám na sebe (smyčka), graf nemůže být stromem.
     *
     * **Složitost:**
     * - Časová: O(V + E) = O(V), protože E = V-1
     * - Prostorová: O(V) pro pole `visited` a zásobník DFS
     *
     * @return `true` pokud je graf stromem, jinak `false`.
     *
     *
     * @par Zdroj
     * Vlastnost E = V-1 jako podmínka stromu:
     * https://en.wikipedia.org/wiki/Tree_(graph_theory),  Levitinova kniha  \n
     * Pak cvičení pro DFS
     *
     * @see addEdge()
     */
    bool isTree();

    /**
     * @brief Vypíše strukturu grafu (vrcholy a hrany) do konzole.
     *
     * @details
     * Při výpisu hran se prochází pouze horní trojúhelník matice sousednosti,
     * aby se každá neorientovaná hrana vytiskla jen jednou.
     */
    void printGraph();
};

#endif //IS_THAT_A_TREE_GRAPH_H
