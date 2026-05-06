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
 * @brief Neorientovaný graf uložený jako seznam sousednosti s podporou detekce stromu.
 *
 * @details
 * Třída spravuje pevný počet vrcholů (Vertex) a pro každý vrchol pole indexů jeho sousedů.
 * Hlavním účelem je metoda isTree(), která v čase O(V+E) rozhodne, zda je graf stromem,
 * kde V je počet vrcholů a E počet hran.
 *
 * ### Rozložení paměti
 * | Člen             | Typ         | Popis |
 * |------------------|-------------|-------|
 * | `vertexes`       | `Vertex**`  | Pole ukazatelů na vrcholy, indexované přes id. |
 * | `neighbors`      | `int**`     | Pole seznamů; `neighbors[i]` obsahuje indexy sousedů vrcholu i. |
 * | `neighborCount`  | `int*`      | `neighborCount[i]` je aktuální počet sousedů vrcholu i. |
 *
 * @note Graf je neorientovaný – každá hrana {i,j} je uložena dvakrát: index j v seznamu
 *       vrcholu i a index i v seznamu vrcholu j.
 */
class Graph {
private:
    Vertex** vertexes;       ///< Pole ukazatelů na vrcholy indexované interním id.
    int**    neighbors;      ///< Seznamy sousedů; neighbors[i] = pole indexů sousedů vrcholu i.
    int*     neighborCount;  ///< neighborCount[i] = aktuální počet sousedů vrcholu i.
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
     * Alokuje pole ukazatelů na vrcholy, pole seznamů sousedů (pro každý vrchol
     * pole velikosti V) a pole čítačů sousedů. Všechny čítače jsou inicializovány na 0.
     *
     * @param[in] vertexCount  Maximální počet vrcholů, které graf může obsahovat.
     */
    Graph(int vertexCount);

    /**
     * @brief Destruktor – uvolní veškerou dynamicky alokovanou paměť.
     *
     * @details
     * Smaže každý objekt Vertex, pole ukazatelů na vrcholy,
     * každý seznam sousedů, pole ukazatelů na seznamy a pole čítačů sousedů.
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
     * Nejrychlejší test – zahodí evidentně špatné grafy bez dalšího procházení.
     *
     * **Krok 2 – kontrola smyček:**
     * Pro každý vrchol projde jeho seznam sousedů a hledá výskyt sebe sama.
     * Pokud vrchol obsahuje sám sebe ve svém seznamu sousedů, jde o smyčku –
     * strom smyčku mít nesmí.
     *
     * **Krok 3 – kontrola spojitosti (iterativní DFS):**
     * Spustí prohledávání do hloubky od vrcholu 0 přes seznamy sousedů a ověří,
     * že každý vrchol byl navštíven.
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
     * Při výpisu hran se pro každý vrchol projdou jeho sousedé a vypíše se hrana
     * jen tehdy, pokud má soused vyšší index než aktuální vrchol – díky tomu se
     * každá neorientovaná hrana vytiskne jen jednou.
     */
    void printGraph();
};

#endif //IS_THAT_A_TREE_GRAPH_H
