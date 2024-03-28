cmake_minimum_required(VERSION 3.27)
project(aed2 C)

set(CMAKE_C_STANDARD 11)

add_executable(aed2 main.c
        matriz/matrizAlunos.c
        matriz/matrizAlunos.h
        duplamenteEncadeada/listaDuplamenteEncadeadaCircular.c
        duplamenteEncadeada/listaDuplamenteEncadeadaCircular.h
)
