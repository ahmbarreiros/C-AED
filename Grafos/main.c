#include <stdio.h>
#include "Grafo.h"

int main() {
    Grafo *gr;
    gr = cria_grafo(10, 7, 0);
    insere_aresta(gr, 0, 1, 0, 0);
    insere_aresta(gr, 1, 3, 0, 0);
    remove_aresta(gr, 0, 1, 0);
    libera_grafo(gr);
    return 0;
}