#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncad.h"

int main() {
    Lista *li;
    struct Aluno al;
    struct Aluno *pAl = &al;
    int x, pos, mat, input;
    li = cria_lista();
    printf("Digite o valor da operacao que voce deseja realizar.\n\n");
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
        strcpy(al.nome, "");
        al.matricula = 0;
        al.n1 = 0.0;
        al.n2 = 0.0;
        al.n3 = 0.0;
        mat = 0;
        pos = 0;
        printf("Digite aqui..: ");
        scanf("%d", &input);
        switch(input) {
            case 1:
                printf("--INSERINDO EM LISTA AO INICIO--\n\n");
                printf("Digite o nome do aluno: ");
                scanf("%s", al.nome);
                printf("Digite a matricula: ");
                scanf("%d", &al.matricula);
                printf("Digite as notas: ");
                scanf("%f %f %f", &al.n1, &al.n2, &al.n3);
                x = insere_lista_inicio(li, al);
                if(x) printf("Inserido com sucesso!\n");
                else printf("Erro ao inserir aluno.\n");
                break;
            case 2:
                printf("--INSERINDO EM LISTA AO FINAL--\n\n");
                printf("Digite o nome do aluno: ");
                scanf("%s", al.nome);
                printf("Digite a matricula: ");
                scanf("%d", &al.matricula);
                printf("Digite as notas: ");
                scanf("%f %f %f", &al.n1, &al.n2, &al.n3);
                x = insere_lista_final(li, al);
                if(x) printf("Inserido com sucesso!\n");
                else printf("Erro ao inserir aluno.\n");
                break;
            case 3:
                printf("--INSERINDO EM LISTA ORDENADA--\n\n");
                printf("Digite o nome do aluno: ");
                scanf("%s", al.nome);
                printf("Digite a matricula: ");
                scanf("%d", &al.matricula);
                printf("Digite as notas: ");
                scanf("%f %f %f", &al.n1, &al.n2, &al.n3);
                x = insere_lista_ordenada(li, al);
                if(x) printf("Inserido com sucesso!\n");
                else printf("Erro ao inserir aluno.\n");
                break;
            case 4:
                printf("--REMOVENDO EM LISTA AO INICIO--\n\n");
                x = remove_lista_inicio(li);
                if(x) printf("Removido com sucesso!\n");
                else printf("Erro ao remover aluno.\n");
                break;
            case 5:
                printf("--REMOVENDO EM LISTA AO FINAL--\n\n");
                x = remove_lista_final(li);
                if(x) printf("Removido com sucesso!\n");
                else printf("Erro ao remover aluno.\n");
                break;
            case 6:
                printf("--REMOVENDO EM LISTA POR MATRICULA--\n\n");
                printf("Digite a matricula: ");
                scanf("%d", &mat);
                x = remove_lista(li, mat);
                if(x) printf("Removido com sucesso!\n");
                else printf("Erro ao remover aluno.\n");
                break;
            case 7:
                printf("--BUSCA EM LISTA POR POSICAO--\n\n");
                printf("Digite a posicao: ");
                scanf("%d", &pos);
                x = consulta_lista_pos(li, pos, pAl);
                if(x) {
                    printf("Busca realizada com sucesso!\n");
                    printf("Dados do aluno: \n");
                    printf("Nome: %s, Matricula: %d, Notas: %.2f, %.2f, %.2f\n", pAl->nome, pAl->matricula, pAl->n1, pAl->n2, pAl->n3);
                }
                else printf("Erro ao buscar aluno.\n");
                break;
            case 8:
                printf("--BUSCA EM LISTA POR MATRICULA--\n\n");
                printf("Digite a matricula: ");
                scanf("%d", &mat);
                x = consulta_lista_mat(li, mat, pAl);
                if(x) {
                    printf("Busca realizada com sucesso!\n");
                    printf("Dados do aluno: \n");
                    printf("Nome: %s, Matricula: %d, Notas: %.2f, %.2f, %.2f\n", pAl->nome, pAl->matricula, pAl->n1, pAl->n2, pAl->n3);
                }
                else printf("Erro ao buscar aluno.\n");
                break;
            case 9:
                imprime_lista(li);
                break;
            case -1:
                input = -1;
                break;
        }
    } while(input != -1);
    libera_lista(li);
    return 0;
}