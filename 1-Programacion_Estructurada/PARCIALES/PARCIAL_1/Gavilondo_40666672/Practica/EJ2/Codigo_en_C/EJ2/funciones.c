#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "declaraciones_funciones.h"

void cargar_matriz(int matriz[FILAS][COLUMNAS], int idx_fila, int idx_columna, int identificador)
{
    printf("Leer valores de la matriz %i: \n\n", identificador);
    for (idx_fila = 0; idx_fila < FILAS; idx_fila++)
    {
        for (idx_columna = 0; idx_columna < COLUMNAS; idx_columna++)
        {
            printf("Ingrese el elemento [%i][%i]: ", idx_fila+1, idx_columna+1);
            scanf("%i", &matriz[idx_fila][idx_columna]);
        }
    }
}

void procesar_matriz(int matriz1[FILAS][COLUMNAS], int matriz2[FILAS][COLUMNAS], int idx_fila, int idx_columna, int aux)
{
    /*
    Esta funcion lo que hace es intercambiar los valores de arriba de la diagonal de la matriz 1 a la matriz 2, se le conoce como "Metodo de Burbuja".
    */
    for (idx_fila = 0; idx_fila < FILAS; idx_fila++)
    {
        for (idx_columna = 0; idx_columna < COLUMNAS; idx_columna++)
        {
            if(idx_fila > idx_columna)
            {
                aux = matriz1[idx_fila][idx_columna];
                matriz1[idx_fila][idx_columna] = matriz2[idx_columna][idx_fila];
                matriz2[idx_columna][idx_fila] = aux;

            }

        }
    }

}

void mostrar_resultados(const int matriz[FILAS][COLUMNAS], int idx_fila, int idx_columna, int identificador)
{
    printf("Matriz %i procesada\n\n", identificador);
    for (idx_fila = 0; idx_fila < FILAS; idx_fila++)
    {
        printf("|   ");
        for (idx_columna = 0; idx_columna < COLUMNAS; idx_columna++)
        {
            printf("%i   ", matriz[idx_fila][idx_columna]);
        }
        printf("|");
        puts("\n");
    }
    puts("\n");
}
