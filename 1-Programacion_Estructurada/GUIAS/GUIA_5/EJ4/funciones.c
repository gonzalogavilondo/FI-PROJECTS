#include <stdio.h>
#include <stdint.h>
#include "declaraciones_funciones.h"

int maximo_elemento(const int32_t vector[])
{
    int32_t max = vector[0];
    for (int i = 0; i < DIM; i++)
    {
        if (vector[i] > max)
        {
            max = vector[i];
        }
    }
    return max;
}
