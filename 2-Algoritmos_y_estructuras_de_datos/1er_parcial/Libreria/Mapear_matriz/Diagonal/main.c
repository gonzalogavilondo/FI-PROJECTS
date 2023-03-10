#include "declaraciones.h"

/*
MATRIZ DIAGONAL
                                  j
                               i  0 1 2 3 4 5
                               0| 1 0 0 0 0 0 |
                               1| 0 1 0 0 0 0 |
                               2| 0 0 l 0 0 0 |
                               3| 0 0 0 1 0 0 |
                               4| 0 0 0 0 1 0 |
                               5| 0 0 0 0 0 1 |


*/
int main()
{
    //Declaramos la matriz triangular y el vector donde van a ser almacenados los datos de forma estatica.
    float matriz[FILSMAX][COLSMAX] = {{1, 2, 3, 5}, {6, 10, 11, 19}, {12, 15, 14, 21}, {25, 26, 36, 32}};
    float vector[LONGMAX] = {0.0};

    //Mapeamos
    mapear_matriz(matriz, vector);

    //Imprimimos los resultados
    printf("-MATRIZ-\n\n");
    imprimir_matriz(matriz);
    printf("-VECTOR RESULTANTE-\n\n");
    imprimir_vector(vector);


    return 0;
}
