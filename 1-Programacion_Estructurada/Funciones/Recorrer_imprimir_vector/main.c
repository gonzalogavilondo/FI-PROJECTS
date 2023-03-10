#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_vector.h"

int main()
{
    int n1 = 1;
    int n2 = 2;
    float vec1[COLSMAX] = {0.0};
    float vec2[COLSMAX] = {0.0};
    int cols = 0;
    printf("Digite el numero de elementos del vector: ");
    scanf("%i", &cols);
    system("cls || clear");
    completar_vector(vec1, n1, cols);
    completar_vector(vec2, n2, cols);
    printf("\t-VECTOR: %i-\n\n", n1);
    imprimir_vector(vec1, cols);
    printf("\t-VECTOR: %i-\n\n", n2);
    imprimir_vector(vec2, cols);


    return 0;
}
