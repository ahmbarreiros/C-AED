#include <stdio.h>
#include "Sorts.h"

int main() {
    int vect[] = {3, 5, 4, 8, 2, 6, 9, 1, 7, 10};
    int tam = 10;
    printf("Antes da recursão:\n");
    for(int i = 0; i < tam; i++) {
        printf("%d ", vect[i]);
    }
    // bubbleSortI(vect, tam);
    // printf("\nDepois da iteracao:\n");
    // for(int i = 0; i < tam; i++) {
    //     printf("%d ", vect[i]);
    // }

    // bubbleSortR(vect, tam);
    // printf("\nDepois da recursão:\n");
    // for(int i = 0; i < tam; i++) {
    //     printf("%d ", vect[i]);
    // }

    // insertionSortI(vect, tam);
    // printf("\nDepois do insertion sort:\n");
    // for(int i = 0; i < tam; i++) {
    //     printf("%d ", vect[i]);
    // }

    // insertionSortR(vect, tam);
    // printf("\nDepois do insertion sort:\n");
    // for(int i = 0; i < tam; i++) {
    //     printf("%d ", vect[i]);
    // }

    // selectionSortI(vect, tam);
    // printf("\nDepois do selection sort:\n");
    // for(int i = 0; i < tam; i++) {
    //     printf("%d ", vect[i]);
    // }

    // selectionSortR(vect, tam);
    // printf("\nDepois do selection sort:\n");
    // for(int i = 0; i < tam; i++) {
    //     printf("%d ", vect[i]);
    // }

    // mergeSort(vect, 0, tam);
    // printf("\nDepois do merge sort:\n");
    // for(int i = 0; i < tam; i++) {
    //     printf("%d ", vect[i]);
    // }

    // quickSort(vect, 0, tam-1);
    // printf("\nDepois do quick sort:\n");
    // for(int i = 0; i < tam; i++) {
    //     printf("%d ", vect[i]);
    // }

    heapSort(vect, tam);
    printf("\nDepois do heap sort:\n");
    for(int i = 0; i < tam; i++) {
        printf("%d ", vect[i]);
    }
}