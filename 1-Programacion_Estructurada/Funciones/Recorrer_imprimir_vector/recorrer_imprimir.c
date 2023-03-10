#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_vector.h"

void completar_vector(float vector[COLSMAX], int n, int elementos)
{
    for(int j = 0; j < elementos; j++)
    {
        printf("\t-COMPLETE EL VECTOR: %i-\n\n", n);
        imprimir_vector(vector, elementos);
        printf("Digite un valor para el elemento[%i]: ", j+1);
        scanf("%f", &vector[j]);
        system("cls || clear"); //Para que funcione tambien en linux el "clear"

    }
}
void imprimir_vector(float vector[COLSMAX], int elementos)
{
    printf("|\t");
    for(int j = 0; j < elementos; j++)
    {
        printf("%.2f\t", vector[j]);
    }
    printf("|\n\n");

}
