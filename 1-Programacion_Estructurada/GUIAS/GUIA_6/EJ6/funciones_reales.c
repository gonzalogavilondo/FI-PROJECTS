#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "declaraciones_funciones.h"
#include "declaraciones_funciones_reales.h"

void traspuesta_matriz(int filas, int columnas, float **matriz_1, float **matriz_2)
{
    for (int i = 0; i < columnas; i++)
    {
        for (int j = 0; j < filas; j++)
        {
            matriz_2[i][j] = matriz_1[j][i];
        }
    }
}
