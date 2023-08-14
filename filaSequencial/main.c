#include <stdio.h>
#include "FilaEstatica.h"

int main() {
    Fila* fi;
    fi = cria_fila();

    libera_fila(fi);
    return 0;
}