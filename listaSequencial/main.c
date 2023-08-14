#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

int main() {
    Lista *li;
    li = cria_lista();
    int input, x, mat, pos;
    struct Aluno al;
    struct Aluno *pAl = &al;
    printf("Digite o valor da operacao que você deseja realizar.\n\n");
    printf("Inserir aluno no inicio da lista - 1\n");
    printf("Inserir aluno no final da lista - 2\n");
    printf("Inserir aluno na lista - 3\n");
    printf("Remover primeiro aluno da lista - 4\n");
    printf("Remover ultimo aluno da lista - 5\n");
    printf("Remover matricula da lista - 6\n");
    printf("Buscar aluno por posicao na lista - 7\n");
    printf("Buscar matricula na lista - 8\n");
    printf("Imprimir Lista - 9\n");
    printf("\n");
    do {
        x = 0;
        strcpy(al.nome, "");
        al.matricula = 0;
        al.n1 = 0.0;
        al.n2 = 0.0;
        al.n3 = 0.0;

        printf("Digite aqui...: ");
        scanf("%d", &input);

        switch(input) {
            case 1:
                printf("Digite o nome do aluno: ");
                scanf("%s", al.nome);
                printf("Digite a matricula: ");
                scanf("%d", &al.matricula);
                printf("Digite suas notas: ");
                scanf("%f %f %f", &al.n1, &al.n2, &al.n3);
                x = insere_lista_inicio(li, al);
                if(x) printf("Inserido com sucesso!\n");
                else printf("Erro ao inserir aluno\n");
                break;
            case 2:
                printf("Digite o nome do aluno: ");
                scanf("%s", al.nome);
                printf("Digite a matricula: ");
                scanf("%d", &al.matricula);
                printf("Digite suas notas: ");
                scanf("%f %f %f", &al.n1, &al.n2, &al.n3);
                x = insere_lista_final(li, al);
                if(x) printf("Inserido com sucesso!\n");
                else printf("Erro ao inserir aluno\n");
                break;
            case 3:
                printf("Digite o nome do aluno: ");
                scanf("%s", al.nome);
                printf("Digite a matricula: ");
                scanf("%d", &al.matricula);
                printf("Digite suas notas: ");
                scanf("%f %f %f", &al.n1, &al.n2, &al.n3);
                x = insere_lista_ordenada(li, al);
                if(x) printf("Inserido com sucesso!\n");
                else printf("Erro ao inserir aluno\n");
                break;
            case 4:
                x = remove_lista_inicio(li);
                if(x) printf("Removido com sucesso 1!\n");
                else printf("Erro ao remover aluno 1\n");
                break;
            case 5:
                x = remove_lista_final(li);
                if(x) printf("Removido com sucesso 2!\n");
                else printf("Erro ao remover aluno 2\n");
                break;
            case 6:
                printf("Digite a matricula: ");
                scanf("%d", &mat);
                x = remove_lista(li, mat);
                if(x) printf("Removido com sucesso 3!\n");
                else printf("Erro ao remover aluno 3\n");
                break;
            case 7:
                printf("Digite a posicao em que o aluno se encontra: ");
                scanf("%d", &pos);
                x = consulta_lista_pos(li, pos, pAl);
                if(x) printf("Posicao encontrada com sucesso!\n");
                else printf("Erro ao encontrar posicao de aluno\n");
                printf("%s", pAl->nome);
                break;
            case 8:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &mat);
                x = consulta_lista_mat(li, mat, pAl);
                if(x) printf("Matricula encontrada com sucesso!\n");
                else printf("Erro ao encontrar matricula\n");
                printf("%s", pAl->nome);
                break;
            case 9:
                imprime_lista(li);
            case -1:
                input == -1;
                break;
        } 
    } while(input != -1);

    libera_lista(li);
    return 0;
}