#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"
int main()
{
    float tabla[FILAS][COLUMNAS] = {{0.0}};
    completar_matriz(tabla);
    printf("-MATRIZ ORIGINAL\n\n");
    mostrar_matriz((const float (*)[COLUMNAS])tabla);
    matriz_diagonal(tabla);
    system("pause");
    printf("\n-MATRIZ MODIFICADA\n\n");
    mostrar_matriz((const float (*)[COLUMNAS])tabla);

    return 0;
}
