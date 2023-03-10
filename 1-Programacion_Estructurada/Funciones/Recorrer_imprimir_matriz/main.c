#include <stdio.h>
#include <stdlib.h>
#include "declaracion_funciones.h"

int main()
{
    char a = 'A';
    char b = 'B';
    int fils = 0;
    int cols = 0;
    float A[FILSMAX][COLSMAX] = {{0.0}};
    float B[FILSMAX][COLSMAX] = {{0.0}};

    printf("Digite el numero de filas: ");
    scanf("%i", &fils);
    printf("\nDigite el numero de columnas: ");
    scanf("%i", &cols);
    if(fils > FILSMAX || cols > COLSMAX)
    {
        printf("Ha exedido el limite de memoria.\n");
    }
    else
    {
        system("cls || clear");
        completar_matriz(fils, cols, A, a);
        completar_matriz(fils, cols, B, b);
        printf("La matriz A es:\n\n");
        mostrar_matriz(fils, cols, A);
        printf("La matriz B es:\n\n");
        mostrar_matriz(fils, cols, B);
    }

    return 0;
}
