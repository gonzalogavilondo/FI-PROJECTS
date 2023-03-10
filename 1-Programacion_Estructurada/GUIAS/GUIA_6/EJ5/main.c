#include "declaraciones_funciones.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main()
{
    float **matA = NULL;
    float **matB = NULL;
    int fils = 0;
    int cols = 0;
    char a = 'A';
    char b = 'B';

    printf("Digite el numero de filas: ");
    scanf("%i", &fils);
    printf("\nDigite el numero de columnas: ");
    scanf("%i", &cols);

    matA = reservar_memoria(fils,cols);
    matB = reservar_memoria(fils,cols);
    system("cls || clear");
    completar_matriz(matA, fils, cols, a);
    completar_matriz(matB, fils, cols, b);
    printf("-MATRIZ A-\n\n");
    imprimir_matriz(matA, fils, cols);
    printf("-MATRIZ B-\n\n");
    imprimir_matriz(matB, fils, cols);
    suma_matrices(matA, matB, fils, cols);
    printf("-LA SUMA DE AMBAS MATRICES-\n\n");
    imprimir_matriz(matA, fils, cols);
    //Liberamos memoria
    liberar_memoria(matA, fils);
    liberar_memoria(matB, fils);

    return 0;
}
