#include "declaraciones.h"

void completar_matriz (float matriz[FILSMAX][COLSMAX])
{
    for (int i = 0; i < FILSMAX; i++)
    {
        for (int j = 0; j < COLSMAX; j++)
        {
            printf("COMPLETE LA MATRIZ: \n\n");
            imprimir_matriz(matriz);
            printf("Ingrese el valor [%i][%i]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
            system("cls || clear");
        }
    }
}

void imprimir_vector(float vector[FILSMAX])
{
    printf("|\t");
    for(int j = 0; j < FILSMAX; j++)
    {
        printf("%.2f\t", vector[j]);
    }
    printf("|\n\n");

}

void imprimir_matriz (float matriz[FILSMAX][COLSMAX])
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
    puts("\n");
}

void matriz_diagonal(float matriz[FILSMAX][COLSMAX], float vector[FILSMAX])
{
    int k = 0;
    for (int i = 0; i < FILSMAX; i++)
    {
        for (int j = 0; j < COLSMAX; j++)
        {
            if(i == j)
            {
                vector[k] = matriz[i][j];
                k++;
            }
            else
            {
                matriz[i][j] = 0.0;
            }
        }
    }

}
