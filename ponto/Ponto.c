#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

struct ponto {
    float x;
    float y;
};

Ponto *pto_cria(float x, float y) {
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

void pto_libera(Ponto *p) {
    free(p);
}

void pto_acessa(Ponto *p, float *x, float *y) {
    *x = p->x;
    *y = p->y;
}

void pto_atribui(Ponto *p, float x, float y) {
    p->x = x;
    p->y = y;
}

float pto_distancia(Ponto *p1, Ponto *p2) {
    return sqrt(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));
}

