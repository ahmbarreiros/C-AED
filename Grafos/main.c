#include <stdio.h>
#include "Grafo.h"

int main() {
    Grafo *gr;
    int eh_digrafo = 1;
    gr = cria_grafo(10, 7, 0);
    insere_aresta(gr, 0, 1, eh_digrafo, 0);
    insere_aresta(gr, 1, 3, eh_digrafo, 0);
    insere_aresta(gr, 1, 2, eh_digrafo, 0);
    insere_aresta(gr, 2, 4, eh_digrafo, 0);
    insere_aresta(gr, 3, 0, eh_digrafo, 0);
    insere_aresta(gr, 3, 4, eh_digrafo, 0);
    insere_aresta(gr, 4, 1, eh_digrafo, 0);
    int vis[5];
    int ant[5];
    float dist[5];

    // Busca em Profundidade
    buscaProfundidade_Grafo(gr, 0, vis);
    
    // Busca em Largura
    buscaLargura_Grafo(gr, 0, vis);

    // Algoritmo de Dijkstra
    menorCaminho_Grafo(gr, 0, ant, dist);

    libera_grafo(gr);
    return 0;
}