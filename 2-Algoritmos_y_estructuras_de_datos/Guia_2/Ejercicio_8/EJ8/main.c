#include "declaraciones.h"

/*
Programar un algoritmo que mapee las coordenadas 2D de la matriz diagonal a la posición
(índice) 1D del array.

MATRIZ DIAGONAL:
                        1 0 0 0
                        0 5 0 0
                        0 0 8 0
                        0 0 0 10
*/
int main()
{
    //Declaramos la matriz diagonal y el vector donde van a ser almacenados los datos de forma estatica.
    float matriz[FILSMAX][COLSMAX] = {{0.0}};
    float vector[FILSMAX] = {0.0};

    //Le pedimos al usuario que complete una matriz
    completar_matriz(matriz);

    //Hacemos la matriz diagonal
    matriz_diagonal(matriz, vector);

    //Imprimimos los resultados
    printf("-MATRIZ DIAGONAL-\n\n");
    imprimir_matriz(matriz);
    printf("-VECTOR RESULTANTE-\n\n");
    imprimir_vector(vector);


    return 0;
}
