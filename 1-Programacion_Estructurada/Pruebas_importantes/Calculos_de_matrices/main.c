#include "header_ops_matrices.h"

int main()
{
    system("color 9f");
    int fil = 4, col = 4, nomMatriz= 0;
    float A[4][4] = {{0.0}};
    float B[4][4] = {{0.0}};
    float C[4][4] = {{0.0}};
    completar_matriz(fil, col, A, nomMatriz);
    nomMatriz = 1;
    completar_matriz(fil, col, B, nomMatriz);
    printf("La matriz A es: \n");
    mostrar_matriz(fil, col, (const float(*)[col])A);
    printf("La matriz B es: \n");
    mostrar_matriz(fil, col, (const float(*)[col])B);
    mult_matriz (fil, col, (const float(*)[col])A, (const float(*)[col])B, C);
    printf("La matriz resultante es: \n");
    mostrar_matriz(fil, col, (const float(*)[col])C);
    return 0;
}
