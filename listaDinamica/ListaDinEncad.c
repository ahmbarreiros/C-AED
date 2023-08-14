#include <stdlib.h>
#include <stdio.h>
#include "ListaDinEncad.h"

struct elemento {
    struct Aluno dados;
    struct elemento* prox;
};

typedef struct elemento Elem;

Lista* cria_lista() {
    Lista *li = malloc(sizeof(Lista));
    if(li != NULL) *li = NULL;
    return li;
}

void libera_lista(Lista* li) {
    if(li != NULL) {
        Elem* no;
        while((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li) {
    if(li == NULL) return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li) {
    return 0;
}

int lista_vazia(Lista* li) {
    if(li == NULL) return 1;
    if(*li == NULL) return 1;
    return 0;
}

int insere_lista_inicio(Lista* li, struct Aluno al) {
    if(li == NULL) return 0;
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_final(Lista* li, struct Aluno al) {
    if(li == NULL) return 0;
    Elem* no = malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL) {
        *li = no;
    } else {
        Elem *aux = *li;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct Aluno al) {
    if(li == NULL) return 0;
    Elem *no = malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if(lista_vazia(li)) {
        no->prox = (*li);
        *li = no;
        return 1;
    } else {
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula) {
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li) {
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista_inicio(Lista* li) {
    if(li == NULL) return 0;
    if(lista_vazia(li)) return 0;
    Elem* no = (*li);
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li) {
    if(li == NULL) return 0;
    if(lista_vazia(li)) return 0;
    Elem *atual = *li, *ant;
    while(atual->prox != NULL) {
        ant = atual;
        atual = atual->prox;
    }
    if(atual == (*li)) {
        *li = atual->prox;
    } else {
        ant->prox = atual->prox;
    }
    free(atual);
    return 1;
}

int remove_lista(Lista* li, int mat) {
    if(li == NULL) return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat) {
        ant = no;
        no = no->prox;
    }
    if(no == NULL) return 0;
    if(no == *li) {
        *li = no->prox;
    } else {
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct Aluno* al) {
    if(li == NULL || pos <= 0) return 0;
    if(lista_vazia(li)) return 0;
    Elem *no = *li;
    int cont = 1;
    while(no != NULL && cont < pos) {
        no = no->prox;
        cont++;
    }
    if(no == NULL) return 0;
    else {
    *al = no->dados;
    return 1;
    }

}

int consulta_lista_mat(Lista* li, int mat, struct Aluno* al) {
    if(li == NULL) return 0;
    Elem* no = *li;
    while(no != NULL && no->dados.matricula != mat) {
        no = no->prox;
    }
    if(no == NULL) return 0;
    else {
        *al = no->dados;
        return 1;
    }
}

void imprime_lista(Lista* li) {
    if(li == NULL) return;
    if(lista_vazia(li)) return;
    Elem* no = *li;
    while(no != NULL) {
        printf("Nome: %s, Matricula: %d, Notas: %.2f, %.2f e %.2f\n", no->dados.nome, no->dados.matricula, no->dados.n1, no->dados.n2, no->dados.n3);
        no = no->prox;
    }
}
