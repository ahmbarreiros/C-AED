#include <stdio.h>
#include "FilaEncadeada.h"

struct fila {
    struct elemento *inicio, *final;
};

typedef struct elemento {
    struct Aluno dados;
    struct elemento* prox;
} Elem;




Fila* cria_fila() {
    Fila* fi = malloc(sizeof(Fila));
    if(fi != NULL) {
        fi->inicio = NULL;
        fi->final = NULL;
    }
    return fi;
}

void libera_fila(Fila* fi) {
    if(fi != NULL) {
        Elem *no;
        while(fi->inicio != NULL) {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_fila(Fila* fi) {
    if(fi == NULL) return -1;
    int cont = 0;
    Elem* no;
    while(no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int fila_cheia(Fila* fi) {
    return 0;
}

int fila_vazia(Fila* fi) {
    if(fi == NULL || fi->inicio == NULL) return 1;
    else return 0;
}

int insere_fila(Fila* fi, struct Aluno al) {
    if(fi == NULL || fila_cheia(fi)) return 0;
    Elem *novoNo = malloc(sizeof(Elem));
    if(novoNo == NULL) return 0;
    novoNo->dados = al;
    novoNo->prox = NULL;
    if(fi->final == NULL) {
        fi->inicio = novoNo;
    } else {
        fi->final->prox = novoNo;
    }
    fi->final = novoNo;
    return 1;
}

int remove_fila(Fila* fi) {
    if(fi == NULL || fila_vazia(fi)) return 0;
    Elem* no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL) {
        fi->final == NULL;
    }
    free(no);
    return 1;
}

int consulta_fila(Fila* fi, struct Aluno* al) {
    if(fi == NULL || fila_vazia(fi)) return 0;
    *al = fi->inicio->dados;
    return 1;
}