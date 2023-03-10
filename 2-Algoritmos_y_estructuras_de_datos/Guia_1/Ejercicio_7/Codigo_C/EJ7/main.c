#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main()
{
    //Declaracion de variables a utilizar
    int vector[COLSMAX] = {0};
    int cnt = 0;
    int resultado = 0;

    //Llamada de funciones a utilizar
    cnt = completar_vector(vector);
    resultado = suma(vector, cnt);

    //Impresion de resultados
    printf("El resultado de la suma de los primeros 100 numeros pares es de: %i", resultado);

    return 0;
}
