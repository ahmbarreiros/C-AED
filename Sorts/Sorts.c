#include <stdio.h>
#include "Sorts.h"
#include <math.h>
#include <stdlib.h>

void bubbleSortR(int* V, int N) {
    int i, j, temp;
    if(N > 1) {
        for(j = 0; j < N - 1; j++) {
            if(V[j] < V[j + 1]) {
                temp = V[j + 1];
                V[j + 1] = V[j];
                V[j] = temp;
            }
        }
        bubbleSortR(V, N - 1);
    }
}

void bubbleSortI(int* V, int N) {
    int continua, fim = N, i, temp;
    do {
        for(i = 0; i < fim - 1; i++) {
            if(V[i] > V[i + 1]) {
                temp = V[i + 1];
                V[i + 1] = V[i];
                V[i] = temp;
                continua = i;
            }
        }
        fim--;
    } while(continua != 0);
}

void insertionSortI(int* V, int N) {
    int i, j, aux;
    for(i = 1; i < N; i++) {
        aux = V[i];
        for(j = i; (j > 0) && (V[j - 1] > aux); j--) {
            V[j] = V[j - 1];
        }
        V[j] = aux;
    }
}

void insertionSortR(int* V, int N) {
    int j, temp;
    if(N > 1) {
        insertionSortR(V, N - 1);
        j = N - 1;
        while(j >= 0 && V[j] > V[j + 1]) {
            temp = V[j];
            V[j] = V[j + 1];
            V[j + 1] = temp;
            j--;
        }
    }
}

void selectionSortI(int* V, int N) {
    int i, j, temp, menor;
    for(i = 0; i < N - 1; i++) {
        menor = i;
        for(j = i + 1; j < N; j++) {
            if(V[j] < V[menor]) {
                menor = j;
            }
        }
        if(i != menor) {
            temp = V[i];
            V[i] = V[menor];
            V[menor] = temp;
        }
    }
}

void selectionSortR(int* V, int N) {
    int pmax, j, temp;
    if(N > 1) {
        pmax = 0;
        for(j = 1; j <= N; j++) {
            if(V[pmax] <= V[j]) {
                pmax = j;
            }
        }
        temp = V[N];
        V[N] = V[pmax];
        V[pmax] = temp;
        selectionSortR(V, N - 1);
    }
}

void mergeSort(int* V, int inicio, int fim) {
    int meio;
    if(inicio < fim) {
        meio = floor((inicio + fim) / 2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio + 1, fim);
        merge(V, inicio, meio, fim);
    }
}

void merge(int* V, int inicio, int meio, int fim) {
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1=inicio;
    p2=meio+1;
    temp = (int*)malloc(sizeof(int));
    if(temp != NULL) {
        for(i = 0; i < tamanho; i++) {
            if(!fim1 && !fim2) {
                if(V[p1] < V[p2]) {
                    temp[i] = V[p1++];
                } else {
                    temp[i] = V[p2++];
                }
                if(p1 > meio) fim1 = 1;
                if(p2 > fim) fim2 = 1;
            } else {
                if(!fim1)
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];
            }
        } 
        for(j = 0, k=inicio; j < tamanho; j++, k++) {
            V[k] = temp[j];
        }
    }
    free(temp);
}

int particiona(int* V, int inicio, int fim) {
    int esq, dir, aux, pivo;
    esq = inicio;
    dir = fim;
    pivo = V[inicio];
    while(esq < dir) {
        while(V[esq] <= pivo) {
            esq++;
        }
        while(V[dir] > pivo) {
            dir--;
        }
        if(esq < dir) {
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}

void quickSort(int* V, int inicio, int fim) {
    int pivo;
    if(inicio < fim) {
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1, fim);
    }
}

void heapSort(int *vet, int N) {
    int i, aux;
    for(i = (N - 1) / 2; i >= 0; i--) {
        criaHeap(vet, i, N-1);
    }
    for(i = N - 1; i >= 1; i--) {
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criaHeap(vet, 0, i - 1);
    }
}

void criaHeap(int *vet, int i, int f) {
    int aux = vet[i];
    int j = i * 2 + 1;                          // Calcula o primeiro filho da primeira posição passada do vetor
    while(j <= f) {
        if(j < f) {                             // Pai tem 2 filhos? Quem é o maior?
            if(vet[j] < vet[j + 1]) {
                j = j + 1;
            }
        }
        if(aux < vet[j]) {                      // Filho é maior que o pai? Filho se torna o pai e repete o processo
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        } else {
            j = f + 1;
        }
    }
    vet[i] = aux;
}