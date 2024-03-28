#include <stdio.h>
#include "matriz/matrizAlunos.h"
#include "duplamenteEncadeada/listaDuplamenteEncadeadaCircular.h"

int main() {

    int tipo;

    printf("Voce prefere matriz ou lista duplamente encadeada?\n[1] Matriz\n[2] Lista\n");
    scanf("%d", &tipo);

    if(tipo == 1) {
        matriz();
        return 1;
    }
    else if(tipo == 2) {
        listaDuplamenteEncadeada();
        return 1;
    }

    return 0;
}
