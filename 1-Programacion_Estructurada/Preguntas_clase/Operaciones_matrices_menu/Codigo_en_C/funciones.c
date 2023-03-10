#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_funciones_reales.h"
#include "declaraciones_funciones.h"

void cargar_filas_columnas(int *filas, int *columnas)
{
    int salir = 0;
    do
    {
        system("cls");
        printf("Digite el numero de filas: ");
        scanf("%i", filas);
        printf("Digite el numero de columnas: ");
        scanf("%i", columnas);
        if ((*filas > FILSMAX) || (*columnas > COLSMAX))
        {
            printf("Ha excedido el limite de memoria.\n");
            salir = 0;
        }
        else
        {
            salir = 1;
        }
        system("pause");
        system("cls || clear");

    }while(salir == 0);
}

void inicializar_matriz(int filas, int columnas, float matriz[FILSMAX][COLSMAX])
{
    float limpiar[FILSMAX][COLSMAX] = {{0.0}};

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

void completar_matriz (int filas, int columnas, float matriz[FILSMAX][COLSMAX], char nombreMatriz)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("COMPLETE LA MATRIZ %c: \n\n", nombreMatriz);
            mostrar_matriz(filas, columnas, (const float (*)[COLSMAX]) matriz);
            printf("Ingrese el valor [%i][%i]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
            system("cls || clear");
        }
    }
}

void mostrar_matriz (int filas, int columnas, const float matriz[FILSMAX][COLSMAX])
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

