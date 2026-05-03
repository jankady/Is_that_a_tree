# Is that a tree?

Semestrální projekt z předmětu ALGI (1. ročník Bc.). Program načte neorientovaný graf
ze souboru a rozhodne, zda je **stromem**.

## Struktura projektu

```
.
├── CMakeLists.txt        # build konfigurace
├── main.cpp              # vstupní bod, spouští testy nad soubory
├── Graph.h / Graph.cpp   # třída Graph + algoritmus isTree()
├── Vertex.h / Vertex.cpp # třída reprezentující jeden vrchol
├── testCases/            # vstupní grafy (graph1.txt … graph4.txt)
└── README.md
```

### Formát vstupního souboru

Každý řádek obsahuje dvě celá čísla oddělená mezerou — hodnoty vrcholů jedné hrany:

```
0 1
1 2
2 3
```

## Build

Potřebuješ **CMake ≥ 3.20** a libovolný C++17 kompilátor (g++, clang, MSVC).

```bash
cmake -S . -B build
cmake --build build
```

Po buildu se složka `testCases/` automaticky zkopíruje vedle binárky,
takže program najde vstupní soubory ať ho spustíš odkudkoliv.

## Spuštění

Z kořene projektu:

```bash
./build/Is_that_a_tree
```

Nebo z `build/`:

```bash
cd build
./Is_that_a_tree
```

Program postupně otestuje všechny grafy v `testCases/` a u každého vypíše,
zda je stromem.

## Vlastní testy

Přidej do `testCases/` nový soubor (např. `graph5.txt`) a v `main.cpp` přidej řádek:

```cpp
testGraph("./testCases/graph5.txt", <pocet_vrcholu>);
```

Po `cmake --build build` se nový soubor zkopíruje vedle binárky automaticky.