#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

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

void vector_total(float vec1[COLSMAX], float vec2[COLSMAX])
{
    int k = 0;
    int n3 = 3;
    float vec3[COLS3] = {0.0};
    for(int i = 0; i < COLS1; i++)
    {
        vec3[i] = vec1[i];
    }
    for(int j = COLS1; j < COLS3; j++)
    {
        vec3[j] = vec2[k];
        k++;
    }
    printf("VECTOR: %i\n\n\n", n3);
    imprimir_vector(vec3, COLS3);

}
