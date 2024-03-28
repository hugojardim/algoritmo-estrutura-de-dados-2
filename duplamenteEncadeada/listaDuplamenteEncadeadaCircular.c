#include "listaDuplamenteEncadeadaCircular.h"

struct Aluno *inicioLista = NULL;

void listaDuplamenteEncadeada() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar aluno\n");
        printf("2. Mostrar todos os alunos\n");
        printf("3. Excluir aluno\n");
        printf("4. Editar aluno\n");
        printf("5. Media aluno\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                createLista();
                break;
            case 2:
                readLista();
                break;
            case 3:
                deleteLista();
                break;
            case 4:
                updateLista();
                break;
            case 5:
                mediaAritmeticaLista();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        printf("Deseja realizar outra operacao?\n[1]Sim\n[2]Nao");
        scanf("%d", &opcao);
    } while(opcao != 2);

    //free();
}

void createLista() {
    int adicionarOutroAluno;
    int matricula;
    struct Aluno *temporario = inicioLista;

    printf("Matricula: ");
    scanf("%d", &matricula);

    if(inicioLista != NULL) {
        while (temporario->proxima != NULL) {
            if (temporario->matricula == matricula) {
                printf("Ja existe um aluno com a matricula fornecida");
                printf("Deseja adicionar um novo aluno?\n[1]Sim\n[2]Nao\n");
                scanf("%d", &adicionarOutroAluno);
                if (adicionarOutroAluno == 1) {
                    createLista();
                    return;
                }
                return;
            }
            temporario = temporario->proxima;
        }
    }

    struct Aluno *novoAluno = (struct Aluno *) malloc(sizeof (struct Aluno));
    novoAluno->matricula = matricula;
    printf("Nome: ");
    getchar();
    fgets(novoAluno->nome, sizeof(novoAluno->nome), stdin);
    printf("Curso: ");
    fgets(novoAluno->curso, sizeof(novoAluno->curso), stdin);
    printf("Nota1: ");
    scanf("%lf", &novoAluno->nota1);
    printf("Nota2: ");
    scanf("%lf", &novoAluno->nota2);
    novoAluno->anterior = NULL;
    novoAluno->proxima = NULL;

    if(inicioLista == NULL) {
        inicioLista = novoAluno;
        return;
    }

    temporario = inicioLista;

    while (temporario->proxima != NULL){
        temporario = temporario->proxima;
    }
    temporario->proxima = novoAluno;
    novoAluno->anterior = temporario;
    novoAluno->proxima = inicioLista;
    inicioLista->anterior = novoAluno;
}

void readLista() {

    if(inicioLista == NULL) {
        printf("Nao ha nenhum aluno cadastrado ainda");
        return;
    }
    struct Aluno *temporario = inicioLista;

    while (temporario != NULL) {
        printf("Matricula: %d\n", temporario->matricula);
        printf("Nome: %s\n", temporario->nome);
        printf("Curso: %s\n", temporario->curso);
        printf("Nota1: %.2lf\n", temporario->nota1);
        printf("Nota2: %.2lf\n", temporario->nota2);
        printf("\n----------------------------------\n");
        temporario = temporario->proxima;
    }
}

void deleteLista() {
    int confirmarExclusao;
    int alunoEscolhido;

    printf("Deseja realmente excluir?\n[1]Sim\n[2]Não\n");
    scanf("%d", &confirmarExclusao);
    if (confirmarExclusao == 1) {
        struct Aluno *temporario = inicioLista;
        struct Aluno *anteriorAoExcluido = NULL;

        int i = 0;

        while (temporario != NULL) {
            printf("[%i] %s", i, temporario->nome);
            i++;
            temporario = temporario->proxima;
        }

        printf("Qual aluno voce deseja excluir:");
        scanf("%d", &alunoEscolhido);

        temporario = inicioLista;

        for (i = 0; temporario != NULL; i++) {
            if (i == alunoEscolhido) {
                break;
            }
            anteriorAoExcluido = temporario;
            temporario = temporario->proxima;
        }

        if(temporario == NULL){
            printf("Aluno nao encontrado\n");
            return;
        }

        if(anteriorAoExcluido == NULL) inicioLista = temporario->proxima;

        else anteriorAoExcluido->proxima = temporario->proxima;

        free(temporario);

        printf("Aluno excluido!\n");
    }
}

void updateLista() {
    int alunoEditado;
    struct Aluno *temporario = inicioLista;
    int i = 0;

    while (temporario != NULL) {
        printf("[%i] %s\n", i, temporario->nome);
        temporario = temporario->proxima;
        i++;
    }

    printf("Qual aluno voce deseja editar: ");
    scanf("%d", &alunoEditado);

    temporario = inicioLista;
    i = 0;

    while (temporario != NULL) {
        if (i == alunoEditado) {
            break;
        }
        temporario = temporario->proxima;
        i++;
    }

    if (temporario != NULL) {
        printf("Nova matricula: ");
        scanf("%d", &(temporario->matricula));
        getchar(); // Consume newline character
        printf("Novo nome: ");
        fgets(temporario->nome, sizeof(temporario->nome), stdin);
        strtok(temporario->nome, "\n");
        printf("Novo curso: ");
        fgets(temporario->curso, sizeof(temporario->curso), stdin);
        strtok(temporario->curso, "\n");
        printf("Nova nota1: ");
        scanf("%lf", &(temporario->nota1));
        printf("Nova nota2: ");
        scanf("%lf", &(temporario->nota2));
        printf("Atualizacao concluida.\n");
        return;
    }
    printf("Aluno nao encontrado.\n");
}

void mediaAritmeticaLista() {
    int alunoEscolhido;
    struct Aluno *temporario = inicioLista;
    int i = 0;
    double media;

    while (temporario != NULL) {
        printf("[%i] %s\n", i, temporario->nome);
        temporario = temporario->proxima;
        i++;
    }

    i = 0;
    temporario = inicioLista;

    printf("Qual aluno voce deseja visualizar a media das notas?:");
    scanf("%d", &alunoEscolhido);

    while (temporario != NULL) {
        if (i == alunoEscolhido) {
            break;
        }
        temporario = temporario->proxima;
        i++;
    }

    if(temporario == NULL) {
        printf("Aluno nao encontrado\n");
        return;
    }

    media = (temporario->nota1 + temporario->nota2) / 2;
    printf("A media aritmetica das notas1 e nota2 do aluno e: %lf\n", media);
    media = 0;

}

