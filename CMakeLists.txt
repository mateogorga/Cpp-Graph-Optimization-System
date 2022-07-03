cmake_minimum_required(VERSION 3.21)
project(tp3_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tp3_main
        arista.cpp
        arista.h
        cola.cpp
        cola.h
        cuento.cpp
        cuento.h
        escritor.cpp
        escritor.h
        escritores.txt
        grafo.cpp
        grafo.h
        hash_escritores.cpp
        hash_escritores.h
        historica.cpp
        historica.h
        lectura.cpp
        lectura.h
        lecturas.txt
        lista_escritores.cpp
        lista_escritores.h
        lista_lecturas.cpp
        lista_lecturas.h
        main.cpp
        menu.cpp
        menu.h
        nodo.h
        novela.cpp
        novela.h
        parser_escritores.cpp
        parser_escritores.h
        parser_lecturas.cpp
        parser_lecturas.h
        poema.cpp
        poema.h)
