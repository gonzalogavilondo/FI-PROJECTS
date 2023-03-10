#include "declaraciones_funciones_reales.h"
#include <stdio.h>
#include <stdlib.h>

void suma_matriz (int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX], float matriz_3[FILSMAX][COLSMAX])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_3[i][j] = (matriz_1[i][j] + matriz_2[i][j]);
        }
    }
}

void resta_matriz(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX], float matriz_3[FILSMAX][COLSMAX])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_3[i][j] = (matriz_1[i][j] - matriz_2[i][j]) ;
        }
    }
}

void multiplicar_matrices (int filas1, int columnas1, int filas2, int columnas2, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX], float matriz_3[FILSMAX][COLSMAX])
{
    for (int i = 0; i < filas1; i++)
    {
        for (int j = 0; j < columnas2; j++)
        {
            matriz_3[i][j] = multiplicar_escalar_matrices(i, j, filas2, matriz_1, matriz_2) ;
        }
    }

}

float multiplicar_escalar_matrices (int i, int j, int elementos, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX])
{
    float res = 0.0;

    for (int k = 0; k < elementos; k++)
    {
        res  += matriz_1[i][k]*matriz_2[k][j];
    }
    return res;
}

void multiplicar_filas_matriz(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], float matriz_2[FILSMAX][COLSMAX])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_2[i][j] = multiplicar_escalar_matriz(i, j, filas, matriz_1);
        }
    }

}

float multiplicar_escalar_matriz(int i, int j, int elementos, const float matriz[FILSMAX][COLSMAX])
{
    float res = 0.0;

    for (int k = 0; k < elementos; k++)
    {
        res  += matriz[i][k]*matriz[j][k]; //Si quiero calcular la multiplicacion de columnas, cambio hasta que k < columnas y tengo que pasar como parametro columnas.
    }
    return res;

}

void div_escalar(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], float matriz_2[FILSMAX][COLSMAX])
{
    float escalar = 0.0;
    printf("Ingrese un escalar: ");
    scanf("%f", &escalar);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_2[i][j] = (matriz_1[i][j] / escalar);
        }
    }
}

void traspuesta_matriz(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], float matriz_2[FILSMAX][COLSMAX])
{
    for (int i = 0; i < columnas; i++)
    {
        for (int j = 0; j < filas; j++)
        {
            matriz_2[i][j] = matriz_1[j][i];
        }
    }
}
/*
void inversa_matriz(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX], float matriz_3[FILSMAX][COLSMAX])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_3[i][j] = (traspuesta_matriz(filas, columnas, matriz_2, matriz_3)/determinante(filas, columnas, matriz_1));
        }
    }

}

void adjunta_matriz(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], float matriz_2[FILSMAX][COLSMAX])
{
    for (int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            matriz_2
        }
    }

}

int determinante(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX])
{

}
*/
