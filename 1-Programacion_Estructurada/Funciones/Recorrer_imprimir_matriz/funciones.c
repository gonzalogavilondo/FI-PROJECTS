#include <stdio.h>
#include <stdlib.h>
#include "declaracion_funciones.h"

void completar_matriz (int filas, int columnas, float matriz[FILSMAX][COLSMAX], char nombreMatriz)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("COMPLETE LA MATRIZ %c: \n\n", nombreMatriz);
            mostrar_matriz (filas, columnas, matriz);
            printf("Ingrese el valor [%i][%i]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
            system("cls || clear");
        }
    }
}

void mostrar_matriz (int filas, int columnas, float matriz[FILSMAX][COLSMAX])
{
    for (int i = 0; i < filas; i++)
    {
        printf("|\t");
        for (int j = 0; j < columnas; j++)
        {
           printf("%.2f \t", matriz[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\n");
}
