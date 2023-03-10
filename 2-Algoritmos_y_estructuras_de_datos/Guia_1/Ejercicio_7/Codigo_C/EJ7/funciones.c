#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int completar_vector(int vector[COLSMAX])
{
    int j = 0;
    int i = 0;

    for(j = 1; j < NUMS+1; j++) //NUMS+1 Porque quiero incluir al numero 200 como par.
    {
        if(j%2 == 0)
        {
            vector[i] = j;
            i++;
        }
    }

    return i;
}

int suma(int vector[COLSMAX], int cnt)
{
    int suma = 0;

    for(int j = 0; j < cnt; j++) //Ya que complete al vector de 0 a 99 (100 numeros pares).
    {
        suma += vector[j];
    }

    return suma;
}

