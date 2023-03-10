#include "declaraciones_funciones.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

float **reservar_memoria(int fils, int cols)
{
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
    //No pongo que se reservo memoria correctamente(else), si no salta este cartel, lo doy por hecho.

    return matriz;
}

void completar_matriz(float **matriz, int fils, int cols, char n_Matriz)
{
    for(int i = 0; i < fils; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("COMPLETE LA MATRIZ %c\n\n", n_Matriz);
            imprimir_matriz(matriz, fils, cols);
            printf("Ingrese un valor para el elemento[%i][%i]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
            system("cls || clear");

        }
    }

}
void imprimir_matriz(float **matriz, int fils, int cols)
{
    for(int i = 0; i < fils; i++)
    {
        printf("|\t");
        for(int j = 0; j < cols; j++)
        {
            printf("%.2f\t", matriz[i][j]);

        }
        printf("|\n");
    }
    puts("\n");
}
void liberar_memoria(float **matriz, int fils)
{
    for(int cnt = 0; cnt < fils; cnt++)
    {
        free(matriz[cnt]);
    }
    free(matriz);
}

