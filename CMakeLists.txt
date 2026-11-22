cmake_minimum_required(VERSION 4.3)
project(ProyectoFinal)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoFinal main.c
        Actions.c
        Estructuras.h
        Pilas.c
        Listas.c
        Colas.c
        Faces.c
        Listas.h
        Actions.h
        Faces.h
        Colas.h)
