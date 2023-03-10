#include "declaraciones_funciones_reales.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int fils = 0;
    int cols = 0;
    char a = 'A';
    char b = 'B';
    float A[FILSMAX][COLSMAX] = {{0.0}};
    float B[FILSMAX][COLSMAX] = {{0.0}};
    float C[FILSMAX][COLSMAX] = {{0.0}};

    cargar_filas_columnas(&fils, &cols);
    system("pause");
    system("cls");
    completar_matriz(fils, cols, A, a);
    completar_matriz(fils, cols, B, b);
    printf("-MATRIZ A-\n\n");
    mostrar_matriz(fils, cols, (const float (*)[COLSMAX])A);
    printf("-MATRIZ B-\n\n");
    mostrar_matriz(fils, cols, (const float (*)[COLSMAX])B);
    suma_matriz(fils, cols, (const float (*)[COLSMAX])A, (const float (*)[COLSMAX])B, C);
    printf("-LA MATRIZ RESULTANTE DE LA SUMA-\n\n");
    mostrar_matriz(fils, cols, (const float (*)[COLSMAX])C);
    resta_matriz(fils, cols, (const float (*)[COLSMAX])A, (const float (*)[COLSMAX])B, C);
    printf("-LA MATRIZ RESULTANTE DE LA RESTA-\n\n");
    mostrar_matriz(fils, cols, (const float (*)[COLSMAX])C);
    multiplicar_matrices(fils, cols, (const float (*)[COLSMAX])A, (const float (*)[COLSMAX]) B, C);
    printf("-LA MATRIZ RESULTANTE DE LA MULTIPLICACION-\n\n");
    mostrar_matriz(fils, cols, (const float (*)[COLSMAX])C);
    div_escalar(fils, cols, (const float (*)[COLSMAX])A, C);
    printf("-LA MATRIZ RESULTANTE DE LA DIVISION POR ESCALAR DE LA MATRIZ A-\n\n");
    mostrar_matriz(fils, cols, (const float (*)[COLSMAX])C);
    multiplicar_filas_matriz(fils, cols, (const float (*)[COLSMAX])A, C);
    printf("-LA MATRIZ RESULTANTE DE LA MULTIPLICACION DE FILAS DE LA MATRIZ A-\n\n");
    mostrar_matriz(fils, cols, (const float (*)[COLSMAX])C);
    traspuesta_matriz(fils, cols, (const float (*)[COLSMAX])B, C);
    printf("-LA MATRIZ RESULTANTE DE LA TRASPUESTA DE LA MATRIZ B-\n\n");
    mostrar_matriz(fils, cols, (const float (*)[COLSMAX])C);
    limpiar_matriz(fils, cols, A);
    limpiar_matriz(fils, cols, B);
}
