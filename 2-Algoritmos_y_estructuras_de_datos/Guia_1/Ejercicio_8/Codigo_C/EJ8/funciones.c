#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

void completar_vector(float vec[COLSMAX])
{
    for(int j = 0; j < COLSMAX; j++)
    {
        printf("\t\t\t\t   -COMPLETE EL VECTOR-\n\n");
        imprimir_vector(vec);
        printf("Digite un valor para el elemento[%i]: ", j+1);
        scanf("%f", &vec[j]);
        system("cls || clear"); //Para que funcione tambien en linux el "clear"

    }
}
void imprimir_vector(float vector[COLSMAX])
{
    printf("|\t");
    for(int j = 0; j < COLSMAX; j++)
    {
        printf("%.2f\t", vector[j]);
    }
    printf("|\n\n");

}
float media(float vec[COLSMAX])
{
    float res = 0.0;
    float suma = 0.0;

    for(int j = 0; j < COLSMAX; j++)
    {
        suma += vec[j];
    }
    res = suma/COLSMAX;

    return res;
}

