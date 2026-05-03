cmake_minimum_required(VERSION 3.20)
project(Is_that_a_tree CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Is_that_a_tree
        main.cpp
        Graph.cpp
        Graph.h
        Vertex.cpp
        Vertex.h)

# Po buildu zkopíruje testCases vedle binárky,
# aby relativní cesta ./testCases/... fungovala i při spuštění z build adresáře.
add_custom_command(TARGET Is_that_a_tree POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/testCases
                $<TARGET_FILE_DIR:Is_that_a_tree>/testCases)
