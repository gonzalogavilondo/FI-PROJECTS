#include "declaraciones_funciones_reales.h"
#include <stdio.h>
#include <stdlib.h>

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
    printf("\n");
}

void cargar_filas_columnas(int *filas, int *columnas)
{
    int salir = 0;
    do
    {
        printf("Digite el numero de filas: ");
        scanf("%i", filas);
        printf("Digite el numero de columnas: ");
        scanf("%i", columnas);
        if ((*filas > FILSMAX) || (*columnas > COLSMAX))
        {
            printf("Ha exedido el limite de memoria.\n");
            salir = 0;
        }

        salir = 1;

    }while(salir == 0);
}

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

void multiplicar_matrices (int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX], float matriz_3[FILSMAX][COLSMAX])
{
    /* Como en este caso las matrices A y B tienen las mismas FILAS Y COLUMNAS, ya que le pido una vez al usuario
    la cantidad de filas y columnas y esas cantiades que no necesariamente son iguales se le asignan a las 2 matrices
    como para multiplicar una matriz la cantidad de columnas de la primera tiene que ser igual que la cantidad de filas
    de la segunda matriz, y como para ambas matrices van a tener la misma cantidad, solo va a servir para matrices cuadradas
    esta funcion, ya que la unica forma de que sean iguales  la cantidad de columnas de la primera matriz, con las filas de la segunda
    es que sean cuadraas. Es decir  filas == columnas
    */
    if(filas == columnas)
    {
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                matriz_3[i][j] = multiplicar_escalar_matrices(i, j, filas, matriz_1, matriz_2) ;
            }
        }

    }
    else
    {
        system("pause");
        system("cls");
        printf("ERROR DE DIMENSION.\n");
        printf("La cantidad de columnas de la primer matriz no coincide con la cantidad de filas de la primera.\n");
        exit(0);
    }

}

float multiplicar_escalar_matrices (int i, int j, int filas, const float matriz_1[FILSMAX][COLSMAX], const float matriz_2[FILSMAX][COLSMAX])
{
    float res = 0.0;

    for (int k = 0; k < filas; k++)
    {
        res  += matriz_1[i][k]*matriz_2[k][j];
    }
    return res;
}

void limpiar_matriz(int filas, int columnas, float matriz[FILSMAX][COLSMAX])
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

void multiplicar_filas_matriz(int filas, int columnas, const float matriz_1[FILSMAX][COLSMAX], float matriz_2[FILSMAX][COLSMAX])
{
     /* En este caso para que una matriz pueda multiplicarse las filas, debe usar cada fila como columna
     para poder multiplicarse entre si, entonces la cantidad de filas, debera ser si o si igual a la cantidad
     de columnas ya que si voy a multiplicar una fila con una columna que seria otra fila, si tengo 3 filas
     por ejemplo y 4 columnas, cuando multiplique entre si las filas, voy a tener 3 combinaciones para la primera,
     segunda y tercer fila, es decir, 3 columnas seria la resultante... la cuarta que tenia antes quedaria toda en 0.
     Probe haciendo comparaciones donde si filas > columnas, la matriz resultante seria matriz_2[columnas][columnas]
     si es al reves seria matriz_2[filas][filas] y sino matriz_2[filas][columnas] como esta ahora, pero no anduvo
     entonces la voy a hacer mas facil, que ande solo para matrices cuadradas.
     Es decir  filas == columnas
    */
    if(filas == columnas)
    {
        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                matriz_2[i][j] = multiplicar_escalar_matriz(i, j, filas, matriz_1);
            }
        }

    }
    else
    {
        system("pause");
        system("cls");
        printf("ERROR DE DIMENSION.\n");
        printf("La cantidad de filas, no coincide con la cantidad de columnas.\n");
        exit(0);

    }
}

float multiplicar_escalar_matriz(int i, int j, int filas, const float matriz[FILSMAX][COLSMAX])
{
    float res = 0.0;

    for (int k = 0; k < filas; k++)
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
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz_2[j][i] = matriz_1[i][j] ;
        }
    }
}

