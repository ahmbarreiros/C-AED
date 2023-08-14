// LISTA DE ADJACENCIA

typedef struct grafo Grafo;

Grafo* cria_grafo(int nro_vertices, int grau_max, int eh_ponderado);

int insere_aresta(Grafo *gr, int orig, int dest, int eh_digrafo, float peso);

int remove_aresta(Grafo *gr, int orig, int dest, int eh_digrafo);

void libera_grafo(Grafo *gr);