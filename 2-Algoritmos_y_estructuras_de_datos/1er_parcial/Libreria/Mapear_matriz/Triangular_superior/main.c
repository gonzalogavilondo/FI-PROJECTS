#include "declaraciones.h"

/*
MATRIZ TRIANGULAR SUPERIOR
                                  j
                               i  0 1 2 3 4 5
                               0| a b c d e f |
                               1| 0 g h i j k |
                               2| 0 0 l m n � |
                               3| 0 0 0 o p q |
                               4| 0 0 0 0 r s |
                               5| 0 0 0 0 0 t |

Luego, para declarar el vector:

En general, si la matriz es de nxn, se requieren n2 posiciones de memoria para guardar la matriz completa,
pero solamente 1+2+3+...+n = n(n+1)/2 posiciones para guardar los datos de la matriz triangular -> 4*(4+1)/2 = 20/2 = 10 lugares.
Por eso, LONGMAX = 10.
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
