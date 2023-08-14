#include <stdio.h>
#include "PilhaDinamica.h"

typedef struct elemento {
    struct Aluno dados;
    struct elemento* prox;
} Elem;

Pilha* cria_pilha() {
    Pilha* pi = malloc(sizeof(Pilha));
    if(pi != NULL) {
     *pi = NULL;
    }
    return pi;
}

void libera_pilha(Pilha* pi) {
    if (pi != NULL) {
        Elem* no;
        while((*pi) != NULL) {
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int tamanho_pilha(Pilha* pi) {
    if(pi == NULL) return 0;
    Elem *no = *pi;
    int cont = 0;
    while(no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int pilha_cheia(Pilha* pi) {
    return 0;
}

int pilha_vazia(Pilha* pi) {
    if(pi == NULL) return -1;
    if((*pi) == NULL) return 1;
    else return 0;
}

int insere_pilha(Pilha* pi, struct Aluno al) {
    if(pi == NULL || pilha_cheia(pi)) return 0;
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_pilha(Pilha* pi) {
    if(pi == NULL || pilha_vazia(pi)) return 0;
    Elem* no = *pi;
    (*pi) = (*pi)->prox;
    free(no);
    return 1;
}

int consulta_pilha(Pilha* pi, struct Aluno* al) {
    if(pi == NULL || pilha_vazia(pi)) return 0;
    *al = (*pi)->dados;
    return 1;
}