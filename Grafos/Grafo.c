#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

struct grafo {
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};


Grafo* cria_grafo(int nro_vertices, int grau_max, int eh_ponderado) {
    Grafo* gr = malloc(sizeof(Grafo));
    if(gr != NULL) {
        int i = 0;
        gr->eh_ponderado = (eh_ponderado != 0) ? 1 : 0;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->grau = calloc(nro_vertices, sizeof(int));
        gr->arestas = (int**)malloc(nro_vertices*sizeof(int*));
        for(i = 0; i < nro_vertices; i++) {
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));
            if(gr->eh_ponderado) {
                gr->pesos=(float**)malloc(nro_vertices*sizeof(float*));
                for(i = 0; i < nro_vertices; i++) {
                    gr->pesos[i] = (float*)malloc(grau_max*sizeof(float));
                }
            }
        }
        return gr;
    }
}

void libera_grafo(Grafo *gr) {
    if(gr != NULL) {
        int i = 0;
        for(i = 0; i < gr->nro_vertices; i++) {
            free(gr->arestas[i]);
        }
        if(gr->eh_ponderado) {
            for(i = 0; i < gr->nro_vertices; i++) {
                free(gr->pesos[i]);
            }
        }
        free(gr->arestas);
        free(gr->pesos);
        free(gr->grau);
        free(gr);
    }
}

int insere_aresta(Grafo *gr, int orig, int dest, int eh_digrafo, float peso) {
    if(gr == NULL) return 0;
    if(orig < 0 || orig > gr->nro_vertices) return 0;
    if(dest < 0 || dest > gr->nro_vertices) return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado) {
        gr->pesos[orig][gr->grau[orig]] = peso;
    }
    gr->grau[orig]++;

    if(eh_digrafo == 0) {
        insere_aresta(gr, dest, orig, 1, peso);
    }
    return 1;
}

int remove_aresta(Grafo *gr, int orig, int dest, int eh_digrafo) {
    if(gr == NULL) return 0;
    if(orig < 0 || orig > gr->nro_vertices) return 0;
    if(dest < 0 || dest > gr->nro_vertices) return 0;

    int i = 0;
    while(i < gr->grau[orig] && gr->arestas[orig][i] != dest) {
        i++;
    }
    if(i == gr->grau[orig]) return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado) {
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    }
    if(eh_digrafo == 0) {
        remove_aresta(gr, dest, orig, 1);
    }

    return 1;
}

void buscaProfundidade(Grafo *gr, int ini, int* visitado, int cont) {
    int i;
    visitado[ini] = cont;
    for(i = 0; i < gr->grau[ini]; i++) {
        if(!visitado[gr->arestas[ini][i]]) {
            buscaProfundidade(gr, gr->arestas[ini][i], visitado, cont+1);
        }
    }
}

void buscaProfundidade_Grafo(Grafo *gr, int ini, int* visitado) {
    int i = 0, cont = 1;
    for(i = 0; i < gr->nro_vertices; i++) {
        visitado[i] = 0;
    }
    buscaProfundidade(gr, ini, visitado, cont);
}

void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado) {
    int i = 0, vert = 0, NV = 0, cont = 1, *fila, IF = 0, FF = 0;
    for(i = 0; i < gr->nro_vertices; i++) {
        visitado[i] = 0;
    }
    NV = gr->nro_vertices;
    fila = (int*)malloc(NV * sizeof(int));
    FF++;
    fila[FF] = ini;
    visitado[ini] = cont;
    while(IF != FF) {
        IF = (IF + 1) % NV;
        vert = fila[IF];
        cont++;
        for(i = 0; i < gr->grau[vert]; i++) {
            if(!visitado[gr->arestas[vert][i]]) {
                FF = (FF + 1) % NV;
                fila[FF] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
}

int procuraMenorDistancia(float *dist, int *visitado, int NV) {
    int i = 0, menor = -1, primeiro = 1;
    for(i = 0; i < NV; i++) {
        if(dist[i] >= 0 && visitado[i] == 0) {
            if(primeiro) {
                menor = i;
                primeiro = 0;
            } else {
                if(dist[menor] > dist[i]) {
                    menor = i;
                }
            }
        } 
    }
    return menor;
}

void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist) {
    int i = 0, cont = 0, NV = 0, ind = 0, *visitado = 0, u = 0;
    cont = NV = gr->nro_vertices;
    visitado =(int*)malloc(NV *sizeof(int));
    for(i = 0; i < NV; i++) {
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }
    dist[ini] = 0;
    while(cont > 0) {
        u = procuraMenorDistancia(dist, visitado, NV);
        if(u == -1) break;
        visitado[u] = 1;
        cont--;
    }
    for(i = 0; i < gr->grau[u]; i++) {
        ind = gr->arestas[u][i];
        if(dist[ind] < 0) {
            dist[ind] = dist[u] + 1;
            ant[ind] = u;
        } else {
            if(dist[ind] > dist[u] + 1) {
                dist[ind] = dist[u] + 1;
                ant[ind] = u;
            }
        }
    }
    free(visitado);
}