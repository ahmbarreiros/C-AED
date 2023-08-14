#define MAX 100

typedef struct lista Lista;

struct Aluno {
    int matricula;
    char nome[50];
    float n1, n2, n3;
};


Lista* cria_lista();

void libera_lista(Lista* li);

int tamanho_lista(Lista* li);

int lista_cheia(Lista* li);

int lista_vazia(Lista* li);

int insere_lista_final(Lista* li, struct Aluno al);

int insere_lista_inicio(Lista* li, struct Aluno al);

int insere_lista_ordenada(Lista* li, struct Aluno al);

int remove_lista_final(Lista* li);

int remove_lista_inicio(Lista* li);

int remove_lista(Lista* li, int mat);

int consulta_lista_pos(Lista *li, int pos, struct Aluno *al);

int consulta_lista_mat(Lista* li, int mat, struct Aluno *al);

void imprime_lista(Lista* li);