#include "header_ops_matrices.h"

void completar_matriz (int filas, int columnas, float nombre_matriz[filas][columnas], int nombreMatriz)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("COMPLETE LA MATRIZ ");
            if (nombreMatriz == 0)
            {
                printf("A\n");
            }
            else
            {
                printf("B\n");
            }
            mostrar_matriz (filas, columnas, (const float(*)[columnas])nombre_matriz);
            printf("Ingrese el valor [%i][%i]: ", i+1, j+1);
            scanf("%f", &nombre_matriz[i][j]);
            system("cls||clear");
        }
    }
}

void mostrar_matriz (int filas, int columnas, const float nombre_matriz[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        printf("|\t");
        for (int j = 0; j < columnas; j++)
        {
           printf("%.1f\t", nombre_matriz[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\n");
}

void suma_matriz (int filas, int columnas, const float matriz_1[filas][columnas], const float matriz_2[filas][columnas], float matriz_3[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_3[i][j] = matriz_1[i][j] + matriz_2[i][j] ;
        }
    }
}

void resta_matriz (int filas, int columnas, const float matriz_1[filas][columnas], const float matriz_2[filas][columnas], float matriz_3[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_3[i][j] = matriz_1[i][j] - matriz_2[j][i];
        }
    }
}

float mult_escalar (int i, int j, int filas, int columnas, const float matriz_1[filas][columnas], const float matriz_2[filas][columnas])
{
    float res = 0.0;
    for (int k = 0; k < filas; k++)
    {
        res += matriz_1[i][k]*matriz_2[k][j];
    }
    return res;
}

void mult_matriz (int filas, int columnas, const float matriz_1[filas][columnas], const float matriz_2[filas][columnas], float matriz_3[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_3[i][j] = mult_escalar (i, j, filas, columnas, matriz_1, matriz_2) ;
        }
    }
}

void div_escalar(int filas, int columnas, float matriz[filas][columnas], float escalar)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] /= escalar;
        }
    }
}

void transpuesta_matriz(int filas, int columnas, const float matriz_1[filas][columnas], float matriz_2[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_2[j][i] = matriz_1[i][j] ;
        }
    }
}

