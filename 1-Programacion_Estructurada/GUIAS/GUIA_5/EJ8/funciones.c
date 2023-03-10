#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_funciones.h"

void carga_tablas (int matriz[][DIM])
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            matriz[i][j] = (i+1)*(j+1);
        }
    }
}

void mostrar_una_tabla (int matriz[][DIM], int num)
{
    for (int i = 0; i < DIM; i++)
    {
        printf("%i * %i\t=  %i\n", num, i+1, matriz[i][num-1]);
    }
}
