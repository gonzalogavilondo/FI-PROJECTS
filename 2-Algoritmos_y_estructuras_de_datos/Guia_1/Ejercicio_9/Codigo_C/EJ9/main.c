#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main()
{
    //Declaraciones de datos a utilizar.
    float max = 0.0;
    float matriz[FILSMAX][COLSMAX] = {{0.0}};
    float suma[FILSMAX] = {0.0}; //Vector donde voy a guardar cada suma de cada columna.


    //Llamada a funciones
    completar_matriz(matriz);
    suma_cols(matriz, suma);
    max = valor_max(suma, matriz); //En esta funcion voy a mandar el vector de cada suma para comprobar cual es la mayor.

    //Impresion de resultados
    printf("\t  -MATRIZ TABULADA-\n\n");
    mostrar_matriz((const float (*)[COLSMAX])matriz);
    printf("\n\n\nEl valor maximo de la suma de cada columna es: %.2f\n\n", max);

    return 0;
}
