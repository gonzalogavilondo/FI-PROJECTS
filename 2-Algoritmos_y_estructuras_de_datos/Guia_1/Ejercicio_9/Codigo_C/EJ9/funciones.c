#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

void completar_matriz (float matriz[FILSMAX][COLSMAX])
{
    for (int i = 0; i < FILSMAX; i++)
    {
        for (int j = 0; j < COLSMAX; j++)
        {
            printf("\t -COMPLETE LA MATRIZ-\n\n");
            mostrar_matriz ((const float (*)[COLSMAX])matriz);
            printf("Ingrese el valor [%i][%i]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
            system("cls || clear");
        }
    }
}

void mostrar_matriz (const float matriz[FILSMAX][COLSMAX])
{
    for (int i = 0; i < FILSMAX; i++)
    {
        printf("|\t");
        for (int j = 0; j < COLSMAX; j++)
        {
           printf("%.2f \t", matriz[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\n");
}
void suma_cols(float matriz[FILSMAX][COLSMAX], float suma[FILSMAX])
{
    for(int j = 0; j < COLSMAX; j++) //Hago el bucle al reves, primero recorro las filas para poder sumar y despues las columnas.
    {
        for(int i = 0; i < FILSMAX; i++)
        {
            suma[j] += matriz[i][j];
        }
    }
}

float valor_max(float suma[COLSMAX], float matriz[FILSMAX][COLSMAX])
{
    float max = 0.0;
    for(int i = 0; i < COLSMAX; i++)
    {
        if(suma[i] > max)
        {
            max = suma[i];
        }
    }

    return max;
}
