#ifndef AED2_LISTADUPLAMENTEENCADEADACIRCULAR_H
#define AED2_LISTADUPLAMENTEENCADEADACIRCULAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO 50

struct Aluno {
    int matricula;
    char nome[TAMANHO_MAXIMO];
    char curso[TAMANHO_MAXIMO];
    double nota1;
    double nota2;
    struct Aluno *anterior;
    struct Aluno *proxima;
};

void listaDuplamenteEncadeada();
void createLista();
void readLista();
void updateLista();
void deleteLista();
void mediaAritmeticaLista();

#endif
