#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main()
{
    int n1 = 1;
    int n2 = 2;
    float vec1[COLS1] = {0.0};
    float vec2[COLS2] = {0.0};
    completar_vector(vec1, n1, COLS1);
    completar_vector(vec2, n2, COLS2);
    printf("VECTOR: %i\n\n\n", n1);
    imprimir_vector(vec1, COLS1);
    printf("VECTOR: %i\n\n\n", n2);
    imprimir_vector(vec2, COLS2);
    vector_total(vec1, vec2);


    return 0;
}
