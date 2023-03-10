#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_funciones_reales.h"
#include "declaraciones_funciones.h"

void cargar_filas_columnas(int *filas, int *columnas)
{
    printf("Digite el numero de filas: ");
    scanf("%i", filas);
    printf("Digite el numero de columnas: ");
    scanf("%i", columnas);
    system("pause");
    system("cls || clear");

}

void inicializar_matriz(int filas, int columnas, float **matriz)
{
    float limpiar[20][20] = {{0.0}};

    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            matriz[i][j] = limpiar[i][j];
        }
    }
}

void condicion_opcion(int opcion, int *filas1, int *columnas1, int *filas2, int *columnas2)
{
    if((opcion == 1) || (opcion == 2))
    {
//      *filas1 = *filas2;
//      *columnas1 = *columnas2;
        *filas2 = *filas1;
        *columnas2 = *columnas1;
    }
    else
    {
        if(opcion == 3)
        {
//          *columnas1 = *filas2;
            printf("Digite las columnas de la matriz 'B': ");
            scanf("%i", columnas2);
            *filas2 = *columnas1;
        }
        else
        {
            if(opcion == 5)
            {
                *filas1 = *columnas1;
            }
        }
    }
}

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
            exit(2);
        }
    }

    //No pongo el else, donde diria que si se asigno memoria correctamente, cuando no aparece nada, doy por hecho que reservo una m

    return matriz;
}

void completar_matriz (int filas, int columnas, float **matriz, char nombreMatriz)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("COMPLETE LA MATRIZ %c: \n\n", nombreMatriz);
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
