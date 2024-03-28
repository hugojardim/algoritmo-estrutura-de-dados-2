#include "matrizAlunos.h"

struct AlunoMatriz *aluno;
int ultimoAlunoLista = 0;

void matriz () {

    int opcao;

    aluno = (struct AlunoMatriz *)malloc(TAMANHO_MAXIMO * sizeof(struct AlunoMatriz));
    if (aluno == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
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
                create();
                break;
            case 2:
                read();
                break;
            case 3:
                delete();
                break;
            case 4:
                update();
                break;
            case 5:
                mediaAritmetica();
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
    } while(opcao != 1);

    free(aluno);
}

void create() {
    if (ultimoAlunoLista < TAMANHO_MAXIMO) {
        int adicionarOutroAluno;
        printf("Matricula: ");
        scanf("%d", &aluno[ultimoAlunoLista].matricula);
        for (int i = 0; i < ultimoAlunoLista; ++i) {
            if (aluno[ultimoAlunoLista].matricula == aluno[i].matricula) {
                printf("Ja existe um aluno com a matricula fornecida");
                printf("Deseja adicionar um novo aluno?\n[1]Sim\n[2]Nao\n");
                scanf("%d", &adicionarOutroAluno);
                if (adicionarOutroAluno == 1) {
                    create();
                }
                return;
            }
        }
        printf("Nome: ");
        getchar();
        fgets(aluno[ultimoAlunoLista].nome, sizeof(aluno[ultimoAlunoLista].nome), stdin);
        printf("Curso: ");
        fgets(aluno[ultimoAlunoLista].curso, sizeof(aluno[ultimoAlunoLista].curso), stdin);
        printf("Nota1: ");
        scanf("%lf", &aluno[ultimoAlunoLista].nota1);
        printf("Nota2: ");
        scanf("%lf", &aluno[ultimoAlunoLista].nota2);
        ultimoAlunoLista++;
        return;
    }
    printf("Quantidade maxima de alunos atingida ou valor invalido\n");
}

void read() {
    for (int i = 0; i < ultimoAlunoLista; ++i) {
        printf("Matricula: %d\n", aluno[i].matricula);
        printf("Nome: %s\n", aluno[i].nome);
        printf("Curso: %s\n", aluno[i].curso);
        printf("Nota1: %.2lf\n", aluno[i].nota1);
        printf("Nota2: %.2lf\n", aluno[i].nota2);
        printf("\n----------------------------------\n");
    }
}

void update() {
    int alunoEditado;
    for (int i = 0; i < ultimoAlunoLista; ++i) {
        printf("[%i] %s", i, aluno[i].nome);
    }

    printf("Qual aluno voce deseja editar:");
    scanf("%d", &alunoEditado);

    if (alunoEditado < ultimoAlunoLista && alunoEditado >= 0) {
        printf("Nova matricula: ");
        scanf("%d", &aluno[alunoEditado].matricula);
        getchar(); // Consume newline character
        printf("Novo nome: ");
        fgets(aluno[alunoEditado].nome, sizeof(aluno[alunoEditado].nome), stdin);
        strtok(aluno[alunoEditado].nome, "\n");
        printf("Novo curso: ");
        fgets(aluno[alunoEditado].curso, sizeof(aluno[alunoEditado].curso), stdin);
        strtok(aluno[alunoEditado].curso, "\n");
        printf("Nova nota1: ");
        scanf("%lf", &aluno[alunoEditado].nota1);
        printf("Nova nota2: ");
        scanf("%lf", &aluno[alunoEditado].nota2);
        printf("Atualizacao concluida.\n");
        return;
    }
    printf("Aluno nao encontrado\n");
}

void delete() {
    int alunoExcluido;
    int confirmarExclusao;

    printf("Deseja realmente excluir?\n[1]Sim\n[2]Não\n");
    scanf("%d", &confirmarExclusao);
    if (confirmarExclusao == 1) {
        for (int i = 0; i < ultimoAlunoLista; ++i) {
            printf("[%i] %s", i, aluno[i].nome);
        }

        printf("Qual aluno voce deseja excluir:");
        scanf("%d", &alunoExcluido);

        for (int i = alunoExcluido; i < ultimoAlunoLista - 1; ++i) {
            aluno[i] = aluno[i + 1];
        }
        ultimoAlunoLista--;
        printf("Aluno excluido!\n");
    }
}

void mediaAritmetica() {
    int alunoEscolhido;
    double media;
    for (int i = 0; i < ultimoAlunoLista; ++i) {
        printf("[%i] %s", i, aluno[i].nome);
    }
    printf("Qual aluno voce deseja visualizar a media das notas?:");
    scanf("%d", &alunoEscolhido);
    if (alunoEscolhido < ultimoAlunoLista) {
        media = (aluno[alunoEscolhido].nota1 + aluno[alunoEscolhido].nota2) / 2;
        printf("A media aritmetica das notas1 e nota2 do aluno e: %lf\n", media);
        return;
    }
    printf("Aluno nao encontrado\n");
}
