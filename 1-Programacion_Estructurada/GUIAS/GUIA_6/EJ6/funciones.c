#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "declaraciones_funciones.h"

void completar_matriz (int filas, int columnas, float **matriz)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("COMPLETE LA MATRIZ: \n\n");
            mostrar_matriz(filas, columnas, matriz);
            printf("Ingrese el valor [%i][%i]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
            system("cls || clear");
        }
    }
}

void mostrar_matriz (int filas, int columnas, float **matriz)
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
    puts("\n");
}

float **reservar_memoria(int fils, int cols)
{
    system("cls || clear");
    //Reservo memoria para las "filas" que seria el primer puntero(puntero a puntero).
    float **matriz = NULL;
    matriz = (float **)calloc(fils, sizeof(float *));
    if(matriz == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(1);
    }

    //Reservo memoria para las "columnas" que seria el segundo puntero.
    for(int i = 0; i < fils; i++)
    {
        matriz[i] = (float *)calloc(cols, sizeof(float));
        if((matriz[i]) == NULL)
        {
            printf("No se ha podido reservar espacio en memoria.\n");
            exit(1);
        }
    }

    //No pongo el else, donde diria que si se asigno memoria correctamente, cuando no aparece nada, doy por hecho que reservo una m

    return matriz;
}
void liberar_memoria(float **matriz, int fils)
{
    for(int i = 0; i < fils; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}
