#include <declaraciones_funciones_reales.h>
#include <stdio.h>

void suma_matrices(float **matriz_A, float **matriz_B, int fils, int cols)
{
    for(int i = 0; i < fils; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            matriz_A[i][j] += matriz_B[i][j];
        }
    }

}

