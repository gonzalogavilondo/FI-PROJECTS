#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

void completar_matriz (float tabla[FILAS][COLUMNAS])
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            tabla[i][j] = 1.0;
        }
    }
}


void mostrar_matriz (const float tabla[FILAS][COLUMNAS])
{
    for (int i = 0; i < FILAS; i++)
    {
        printf("|\t");
        for (int j = 0; j < COLUMNAS; j++)
        {
           printf("%.2f \t", tabla[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\n");
}

void matriz_diagonal (float tabla[FILAS][COLUMNAS])
{
    for(int i = 0; i < FILAS; i++)
    {
        tabla[i][i] = 0.0;
    }

}
