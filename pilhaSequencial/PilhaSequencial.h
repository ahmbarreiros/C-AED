#define MAX_N 100

typedef struct pilha Pilha;

struct Aluno {
    char nome[50];
    int matricula;
    float n1, n2, n3;
};

Pilha* cria_pilha();

void libera_pilha(Pilha* pi);

int tamanho_pilha(Pilha* pi);

int pilha_cheia(Pilha* pi);

int pilha_vazia(Pilha* pi);

int insere_pilha(Pilha* pi, struct Aluno al);

int remove_pilha(Pilha* pi, struct Aluno al);

int consulta_pilha(Pilha* pi, struct Aluno* al);