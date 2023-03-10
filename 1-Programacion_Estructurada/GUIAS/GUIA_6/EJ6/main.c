#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "declaraciones_funciones.h"
#include "declaraciones_funciones_reales.h"

int main()
{
    int fils = 0;
    int cols = 0;
    float **matA = NULL;
    float **matB = NULL;

    printf("Ingrese la cantidad de filas: ");
    scanf("%i", &fils);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%i", &cols);
    matA = reservar_memoria(fils, cols);
    matB = reservar_memoria(cols, fils);
    completar_matriz(fils, cols, matA);
    traspuesta_matriz(fils, cols, matA, matB);
    printf("-MATRIZ INICIAL-\n\n");
    mostrar_matriz(fils, cols, matA);
    printf("-MATRIZ RESULTANTE-\n\n");
    mostrar_matriz(cols, fils, matB);
    //Liberamos memoria
    liberar_memoria(matA, fils);
    liberar_memoria(matB, cols); //Como es la traspuesta le paso las columnas.

    return 0;
}
