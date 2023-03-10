#include <stdio.h>
#include <stdint.h>
#include "declaraciones_funciones.h"
int main()
{
    //¿Por que si le pongo uint32_t no anda? ¿Numeros negativos? ¿O problemas con el return y uint?
    int32_t max = 0;
    int32_t vec[DIM] = {4, 55, -1, -8, 0, 45, 77, -2, 9, 8};
    max = maximo_elemento(vec);
    printf("El maximo elemento del vector es: %i", max);
    return 0;
}

