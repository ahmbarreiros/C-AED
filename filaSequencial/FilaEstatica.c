#include "FilaEstatica.h"
#include <stdlib.h>

struct fila {
    int inicio, final, qtd;
    struct Aluno dados[MAX_N];
};

Fila* cria_fila() {
    Fila* fi = malloc(sizeof(Fila));
    if(fi != NULL) {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;    
}

void libera_fila(Fila* fi) {
    free(fi);
}

int tamanho_fila(Fila* fi) {
    if(fi == NULL) return -1;
    return fi->qtd;
}

int fila_cheia(Fila* fi) {
    if(fi == NULL) return -1;
    if(fi->qtd >= MAX_N) return 1;
    else return 0;
}

int fila_vazia(Fila* fi) {
    if(fi == NULL) return -1;
    if(fi->qtd == 0) return 1;
    else return 0;
}

int insere_fila(Fila* fi, struct Aluno al) {
    if(fi == NULL || fila_cheia(fi)) return 0;
    fi->dados[fi->final] = al;
    fi->final = (fi->final + 1) % MAX_N;
    fi->qtd++;
}

int remove_fila(Fila* fi) {
    if(fi == NULL || fila_vazia(fi)) return 0;
    fi->inicio = fi->inicio + 1 % MAX_N;
    fi->qtd--;
    return 1;
}

int consulta_fila(Fila* fi, struct Aluno* al) {
    if(fi == NULL || fila_vazia(fi)) return 0;
    *al = fi->dados[fi->inicio];
    return 1;
}