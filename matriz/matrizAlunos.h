#ifndef MATRIZ_ALUNOS_H
#define MATRIZ_ALUNOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO 50

struct AlunoMatriz {
    int matricula;
    char nome[TAMANHO_MAXIMO];
    char curso[TAMANHO_MAXIMO];
    double nota1;
    double nota2;
};

void matriz();
void create();
void read();
void update();
void delete();
void mediaAritmetica();

#endif
