#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main()
{
    //Declaracion de variables a utilizar
    float vec[COLSMAX] = {0};
    float resultado = 0.0;

    //Llamada a funciones
    completar_vector(vec);
    resultado = media(vec);

    //Impresion de resultados
    printf("La media de los numeros ingresados en el vector es de: %.2f\n", resultado);


    return 0;
}
